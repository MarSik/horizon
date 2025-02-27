#include "canvas_gl.hpp"
#include <algorithm>
#include <epoxy/gl.h>
#include <iostream>

namespace horizon {
void CanvasGL::pan_drag_begin(GdkEventButton *button_event)
{
    if (gesture_zoom->is_recognized() || gesture_drag->is_recognized())
        return;

    gdouble x, y;
    gdk_event_get_coords((GdkEvent *)button_event, &x, &y);
    if (button_event->button == 2 || (button_event->button == 1 && (button_event->state & Gdk::SHIFT_MASK))) {
        pan_dragging = true;
        pan_pointer_pos_orig = {(float)x, (float)y};
        pan_offset_orig = offset;
    }
}

void CanvasGL::pan_drag_end(GdkEventButton *button_event)
{
    pan_dragging = false;
}

void CanvasGL::pan_drag_move(GdkEventMotion *motion_event)
{
    gdouble x, y;
    gdk_event_get_coords((GdkEvent *)motion_event, &x, &y);

    if (pan_dragging) {
        const bool wr = x >= get_allocated_width();
        const bool wl = x <= 0;
        const bool wb = y >= get_allocated_height();
        const bool wt = y <= 0;
        Coordi warp_distance;
        if (wr || wl || wb || wt) {
            auto dev = gdk_event_get_device((GdkEvent *)motion_event);
            auto srcdev = gdk_event_get_source_device((GdkEvent *)motion_event);
            const auto src = gdk_device_get_source(srcdev);
            if (src != GDK_SOURCE_PEN) {
                auto scr = gdk_event_get_screen((GdkEvent *)motion_event);
                gdouble rx, ry;
                gdk_event_get_root_coords((GdkEvent *)motion_event, &rx, &ry);
                if (wr) {
                    warp_distance = Coordi(-get_allocated_width(), 0);
                }
                else if (wl) {
                    warp_distance = Coordi(+get_allocated_width(), 0);
                }
                else if (wb) {
                    warp_distance = Coordi(0, -get_allocated_height());
                }
                else if (wt) {
                    warp_distance = Coordi(0, get_allocated_height());
                }
                gdk_device_warp(dev, scr, rx + warp_distance.x, ry + warp_distance.y);
            }
        }
        offset = pan_offset_orig + Coordf(x, y) - pan_pointer_pos_orig;
        update_viewmat();
        pan_pointer_pos_orig += warp_distance;
    }
}

void CanvasGL::pan_drag_move(GdkEventScroll *scroll_event)
{
    gdouble dx, dy;
    gdk_event_get_scroll_deltas((GdkEvent *)scroll_event, &dx, &dy);
    offset.x -= dx * 50;
    offset.y -= dy * 50;
    update_viewmat();
}

void CanvasGL::set_scale(float x, float y, float scale_new)
{
    float sc = scale;
    if (scale_new < 1e-7 || scale_new > 1e-2) {
        return;
    }
    this->scale = scale_new;
    float xp = (x - offset.x) / sc;
    float yp = -(y - offset.y) / sc;
    float xi = xp * (sc - scale_new);
    float yi = yp * (scale_new - sc);
    offset.x += xi;
    offset.y += yi;
    if (pan_dragging) {
        pan_offset_orig.x += xi;
        pan_offset_orig.y += yi;
    }
    if (gesture_zoom->is_recognized()) {
        gesture_zoom_offset_orig.x += xi;
        gesture_zoom_offset_orig.y += yi;
    }
    update_viewmat();
    s_signal_scale_changed.emit();
}

int CanvasGL::_animate_step(GdkFrameClock *frame_clock)
{
    auto r = zoom_animator.step(gdk_frame_clock_get_frame_time(frame_clock) / 1e6);
    if (!r) { // should stop
        return G_SOURCE_REMOVE;
    }
    auto s = zoom_animator.get_s();

    set_scale(zoom_animation_pos.x, zoom_animation_pos.y, zoom_animation_scale_orig * pow(zoom_base, s));

    if (std::abs((s - zoom_animator.target) / std::max(std::abs(zoom_animator.target), 1.f)) < .005) {
        set_scale(zoom_animation_pos.x, zoom_animation_pos.y,
                  zoom_animation_scale_orig * pow(zoom_base, zoom_animator.target));
        zoom_animator.stop();
        return G_SOURCE_REMOVE;
    }

    return G_SOURCE_CONTINUE;
}

static int tick_cb(GtkWidget *cwidget, GdkFrameClock *frame_clock, gpointer user_data)
{
    Gtk::Widget *widget = Glib::wrap(cwidget);
    auto canvas = dynamic_cast<CanvasGL *>(widget);
    return canvas->_animate_step(frame_clock);
}


void CanvasGL::pan_zoom(GdkEventScroll *scroll_event, bool to_cursor)
{
    if (gesture_zoom->is_recognized() || gesture_drag->is_recognized())
        return;
    gdouble x, y;
    if (to_cursor) {
        gdk_event_get_coords((GdkEvent *)scroll_event, &x, &y);
    }
    else {
        x = m_width / 2;
        y = m_height / 2;
    }

    float inc = 0;
    float factor = 1;
    if (scroll_event->state & Gdk::SHIFT_MASK)
        factor = .5;
    if (scroll_event->direction == GDK_SCROLL_UP) {
        inc = 1;
    }
    else if (scroll_event->direction == GDK_SCROLL_DOWN) {
        inc = -1;
    }
    else if (scroll_event->direction == GDK_SCROLL_SMOOTH) {
        gdouble sx, sy;
        gdk_event_get_scroll_deltas((GdkEvent *)scroll_event, &sx, &sy);
        inc = -sy;
    }
    inc *= factor;
    if (smooth_zoom) {
        if (inc == 0)
            return;
        if (!zoom_animator.is_running()) {
            zoom_animator.start();
            zoom_animation_scale_orig = scale;
            gtk_widget_add_tick_callback(GTK_WIDGET(gobj()), &tick_cb, nullptr, nullptr);
        }
        zoom_animator.target += inc;
        zoom_animation_pos.x = x;
        zoom_animation_pos.y = y;
    }
    else {
        set_scale(x, y, scale * pow(zoom_base, inc));
    }
}
} // namespace horizon
