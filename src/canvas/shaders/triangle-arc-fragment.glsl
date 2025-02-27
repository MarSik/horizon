#version 330
##ubo

out vec4 outputColor;
smooth in vec3 color_to_fragment;
smooth in vec2 round_pos_to_fragment;
flat in float border_width;
flat in float line_width;
flat in float a0;
flat in float a1;

vec2 p2r(float phi, float l) {
  return vec2(cos(phi), sin(phi))*l;
}

void main() {
  if(length(round_pos_to_fragment)>1)
    discard;

  float my_alpha = alpha;
  if(layer_flags == 3) { //force alpha for stencil mode
    my_alpha = alpha;
  }

  float phi = atan(round_pos_to_fragment.y, round_pos_to_fragment.x);
  if(phi < 0)
    phi += 2*PI;

  float my_a0 = phi-a0;
  if(my_a0 < 0)
    my_a0 += 2*PI;

  bool disc = false;

  float len = length(round_pos_to_fragment);
  if(((len < (1-line_width+border_width)) || (len > (1-border_width))) && layer_flags != 3) {
    my_alpha = 1;
  }
  else {
    if(get_striper_discard(gl_FragCoord.xy) || layer_flags == 0) { //HATCH
      disc = true;
    }
  }

  if(len < (1-line_width)) {
    discard;
  }

  if(my_a0 > a1) { //outside of arc
    vec2 p0 = p2r(a0, 1-line_width/2) - round_pos_to_fragment;
    vec2 p1 = p2r(a0+a1, 1-line_width/2) - round_pos_to_fragment;
    if(length(p0) < line_width/2) {
      if(length(p0) > line_width/2-border_width) {
        if(layer_flags != 3)
          my_alpha = 1;
        disc = false;
      }
    }
    else if(length(p1) < line_width/2) {
      if(length(p1) > line_width/2-border_width) {
        if(layer_flags != 3)
          my_alpha = 1;
        disc = false;
      }
    }
    else {
      discard;
    }
  }

  if(disc)
    discard;

  outputColor = vec4(color_to_fragment, my_alpha);
}
