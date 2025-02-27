# Version 1.4.0

## New features

### Board Editor

 - Aribtrary view rotation ([d69b69c](https://github.com/horizon-eda/horizon/commit/d69b69c5359adae77ea2af388b1a5e0fea802a7e))
 - Rule export/import ([5f33144](https://github.com/horizon-eda/horizon/commit/5f33144c20fc00555be300de432dd32378640a28))
 - Pick&place export format can be be customized ([3ecc1bf](https://github.com/horizon-eda/horizon/commit/3ecc1bfe11efa193392d353a12f95c4f781d3ac8))

### Editors (interactive manipulator)

 - Measurement tool ([478bc50](https://github.com/horizon-eda/horizon/commit/478bc5063899eb2803d0a2a080af369668c7eb81))
 - Drag polygon edge tool ([084ac07](https://github.com/horizon-eda/horizon/commit/084ac072a957ca779e38421b6d437e4438a54d11))
 - Support pool reload in schematic and board ([f5214b2](https://github.com/horizon-eda/horizon/commit/f5214b21b36b2b27adc8fe1932f20a8d8ad416e2))

## Enhancements

### Board editor

 - Thermals in planes follow minimum width setting ([43c1928](https://github.com/horizon-eda/horizon/commit/43c1928869f090d5db59985191d5474577b6d2b4))
 - Place decal tool: Scale is adjustable from tool ([d351448](https://github.com/horizon-eda/horizon/commit/d351448d51fb292eeb8e60f17b4dca48fce64402))
 - Show holes in PDF export ([8de3dab](https://github.com/horizon-eda/horizon/commit/8de3dabb660e3cc9e1f7be3b5ce9e69ff5f7ac9a))
 - Improved rebuild performance after tools ([06fcd68](https://github.com/horizon-eda/horizon/commit/06fcd68829cf6acd62b2285efac9d8260444d6a6))
 - Draw plane/keepout tools for drawing planes/keepouts in one step ([e53f200](https://github.com/horizon-eda/horizon/commit/e53f200bdf3339abf1d8fedb1048fdc749354e2c))
 - Highlighting a package also highlights smashed texts ([1aedb43](https://github.com/horizon-eda/horizon/commit/1aedb433591823380a536d49e03e894aab64e484))
 - Show show more descriptive net names in preflight check ([3088cc8](https://github.com/horizon-eda/horizon/commit/3088cc8eb51891a9e8699e3ff5b0d2a54dd7dcaf))

### Editors (interactive manipulator)
 - Draw dimension tool: Label size is adjustable from tool ([07e0310](https://github.com/horizon-eda/horizon/commit/07e0310a338d9ef23c6337c0ebe9c9cc5c550cc9))
 - View can be flipped if a tool is active ([e213caf](https://github.com/horizon-eda/horizon/commit/e213caf18917ba46fb954183d8aa34a785f1e2b4))
 - Non modal enter datum windows don't immediately close after entering value ([bdc84fb](https://github.com/horizon-eda/horizon/commit/bdc84fb8ce0a6f2cfe9a5bfc7291ca2dbd3a38e3))
 - Arcs are drawn as such, not as line segments ([1367178](https://github.com/horizon-eda/horizon/commit/13671785b4b07f77c681a075163b8645ad85aeb1))
 - Rotate arbitrary/scale tool uses non modal dialogs ([b14e5f4](https://github.com/horizon-eda/horizon/commit/b14e5f438bdff38a5d0df7567b2f625aaf7846a0))
 - Rotate arbitrary/scale tool supports decals ([e8cc033](https://github.com/horizon-eda/horizon/commit/e8cc033b90476a3645896605ae40b846bd1f3c98))
 - Draw polygon tool: finish by closing polygon ([4707cc2](https://github.com/horizon-eda/horizon/commit/4707cc2b7e43944c0c4547148da3408b90f7e407))
 - Parameters window: add insert parameter button ([4d137c3](https://github.com/horizon-eda/horizon/commit/4d137c37b408bb4bc0277942021d01a5e2dc915d))
 - Use navigation buttons (back/forward) to switch layers ([f871566](https://github.com/horizon-eda/horizon/commit/f8715665467e0b348ebb16090d308faffd9ab858))

### Package editor

 - Edit pad tool uses non modal dialog ([e2bf3b2](https://github.com/horizon-eda/horizon/commit/e2bf3b2dcce2c3e276be9f0924dc67b82a303ba1))

### Symbol editor

 - Symbol preview window remembers window size ([f483d2c](https://github.com/horizon-eda/horizon/commit/f483d2cf55d87c5d617059742148ec4632a535a5))
 - Preview for expanded symbols ([1b32099](https://github.com/horizon-eda/horizon/commit/1b32099ca1dfe4a4231dad197cccde9d084222aa))

### 3D preview

 - Render gamma-correct background gradient ([67e0c4b](https://github.com/horizon-eda/horizon/commit/67e0c4b642dfd286aa88de03bf652c553c13af45))
 - Use gamma-correct shading ([693942f](https://github.com/horizon-eda/horizon/commit/693942f43774e55f7f02eb69ddbf5eb37c5dad2a))
 - Render models with smooth normals ([6395e2e](https://github.com/horizon-eda/horizon/commit/6395e2e61b3950bc848c4654e43e468d0d71923f))

### Pool manager

 - Improved progress reporting during pool download ([0781a51](https://github.com/horizon-eda/horizon/commit/0781a511497f68795348b2b7c7db968e94e2c2e4))
 - Git tab performance enhancements ([7c6a02f](https://github.com/horizon-eda/horizon/commit/7c6a02fb24e640872f3eb8cbb15cef4174d42c0b))
 - "Where used" list performance enhancements ([4e7dc29](https://github.com/horizon-eda/horizon/commit/4e7dc293ae1517a5c7a4c16a195fd2d8f0b14194))
 - Pool update is 2× to 5× times faster ([bd95955](https://github.com/horizon-eda/horizon/commit/bd95955f4f2e4e3a8f12823d3e0cba757dab3cc6), [b5603e3](https://github.com/horizon-eda/horizon/commit/b5603e3da80e817418a8116a4cc45bcfbc5f3d42), [acb4124](https://github.com/horizon-eda/horizon/commit/acb4124e37267a6fed2c3e2fdc5214a017bbac3d), [2806973](https://github.com/horizon-eda/horizon/commit/28069739a0d79e0df370339956f43c6f2da85f70))
 - Properly update pool after duplicating part with package ([f64af58](https://github.com/horizon-eda/horizon/commit/f64af586dcf39286ee5f30321a2bb6e9b55a7a48))
 - Partinfo searches by MPN prefix rather than exact match ([ac48399](https://github.com/horizon-eda/horizon/commit/ac48399234f0073d8701275ff488a86dc326f00b))


## Bugfixes

### Board editor

 - Make decals only selectable on used layers ([cb34b24](https://github.com/horizon-eda/horizon/commit/cb34b24e7b70e11df2e8f9333822e9c33bb09dbf))
 - Place decal tool: Support mirroring decal ([5f7a85d](https://github.com/horizon-eda/horizon/commit/5f7a85d334b87867363d7e8eb17ff5db554a1ff0))
 - Via overlay stays readable in bottom view ([bd8b7db](https://github.com/horizon-eda/horizon/commit/bd8b7db4fac45f5f4bffff7941c8dc5fee5f4b4a))
 - Decals are actually mirrored if mirrored ([435dde1](https://github.com/horizon-eda/horizon/commit/435dde1547e0406f39b70c1093e8d74280e0d995))
 - Add plane cutout for PTH barrels ([f3e813e](https://github.com/horizon-eda/horizon/commit/f3e813e0b74bae763aa12179f36dd0640f720f76))
 - Ignore irrelevant layer during plane updated ([8fb868b](https://github.com/horizon-eda/horizon/commit/8fb868bfb8df60f6b0ada62843071efb8f6aee12))
 - Properly handle zero length airwires ([d4f8ffe](https://github.com/horizon-eda/horizon/commit/d4f8ffee8649caf3bdc31f671929b390365bf39f))
 - Properly display nets with no airwires in nets window ([dad6c71](https://github.com/horizon-eda/horizon/commit/dad6c714cc43df72c877024f552134d3d3345bb0))

### Schematic editor

 - Don't crash if connected symbol pin is deleted in symbol ([9cf9a52](https://github.com/horizon-eda/horizon/commit/9cf9a528318b3b5f3b1c2084d8ebb25ac8316d3c))

### Editors

 - Multiline text edit dialog: insert newline at cursor ([5780aff](https://github.com/horizon-eda/horizon/commit/5780affd9a3fed4e89c7ca58691459752755e98a))
 - Load select polygon action keybindings on startup ([88d0bbc](https://github.com/horizon-eda/horizon/commit/88d0bbc10942708369586147a5ac9a460fafa65b))
 - Don't show action button menu if clicked the wrong way ([47654f3](https://github.com/horizon-eda/horizon/commit/47654f33852957b3870d48ee5ab0343775d7ceb6))
 - Avoid rendering empty buffers potentially leading to crashes ([69ac4b5](https://github.com/horizon-eda/horizon/commit/69ac4b50678daf822636c4cffc11d2114a7409f0), [438e65c](https://github.com/horizon-eda/horizon/commit/438e65c3f064f09cee358a50c09f321009f705aa))

### Pool manager

 - Remote tab: Don't crash if there's no local branch when updating a pull request ([88ca981](https://github.com/horizon-eda/horizon/commit/88ca98115bd32a99fc48cc4c812b44c75d3e6334))

### Windows builds

 - Use patched Gtk to work around Intel GPU driver bug ([84a1837](https://github.com/horizon-eda/horizon/commit/84a18373d3fc3c234bc35086d5e0eb7c261f9e15))
 
## Removed features

### Editors

 - Pasting as SVG isn't supported anymore ([13f2428](https://github.com/horizon-eda/horizon/commit/13f2428f6f22a44bc3edb648244f8de6c87acbd9))

# Version 1.3.0

## New features

### Board editor

 - Decals for putting logos and symbols on boards ([d2e88d7](https://github.com/horizon-eda/horizon/commit/d2e88d71601604c82a7ba680fe3da3dfe694ead1))
 - "Add text" tool for adding text linked to packages ([6fbfb78](https://github.com/horizon-eda/horizon/commit/6fbfb786172c339867845a6bf199ec404218bd0f))
 - Same net clearance check ([46c2156](https://github.com/horizon-eda/horizon/commit/46c2156b1cdc57d885a5c343216e92bd43c6f7cb))
 - Support highlight collisions and DRC off mode in router ([078d543](https://github.com/horizon-eda/horizon/commit/078d54340f4ccaa8cb1718d10780265a01cc803f))

### Editors (interactive manipulator)

 - Actions for pan and zoom ([1d57d9c](https://github.com/horizon-eda/horizon/commit/1d57d9c6f63466698e4935e002032efb3a744026))
 - Draw circle tool ([b63a8c1](https://github.com/horizon-eda/horizon/commit/b63a8c1f2f70083c4ac80926382a70e90aa1f321))
 - Highlight net class action in schematic and board ([9f1a240](https://github.com/horizon-eda/horizon/commit/9f1a24093cc1aa8c3c815a0a225f0d4ee86f1f3a))

### Pool manager

 - Support moving and renaming pool items ([14de320](https://github.com/horizon-eda/horizon/commit/14de3200d7e3e43df879dfd05cb4cfa2eae11d27))
 - Pull request review tool (needs to be enabled in `prefs.json`) ([e2d4cd2](https://github.com/horizon-eda/horizon/commit/e2d4cd2b9194dffba13a8bffd83254f118e6adc7))
 - Checks for Units/Entities/Parts ([76c596c](https://github.com/horizon-eda/horizon/commit/76c596ca5d08e7f43ac33b26d8b48e1b90025d33))

### Symbol editor

 - Symbol checks ([a873327](https://github.com/horizon-eda/horizon/commit/a873327f7fe02fec1b43612b3e3dca3da6e7cfea))

### 3D preview

 - Add option for hiding "do not populate" components ([d7d6a9c](https://github.com/horizon-eda/horizon/commit/d7d6a9cacac6fc9bc72417b2434d68458f3dc530))

### Package editor

 - Clearance checks ([a448a3c](https://github.com/horizon-eda/horizon/commit/a448a3c383d3a0af29d65e6e256b8388c860feb5))

### Misc

 - Store application version information in pool items and projects ([9f5cc52](https://github.com/horizon-eda/horizon/commit/9f5cc52a3e65389ad2ea6f4af63753876543b3ff))

## Enhancements

### Internals

 - Check object type when loading pool items ([b961e7a](https://github.com/horizon-eda/horizon/commit/b961e7af71fd3afc3671d4e9101445c29dcac559))

### Package editor

 - Avoid dependency cycles when setting alternate package ([2c3efac](https://github.com/horizon-eda/horizon/commit/2c3efac5212af11fc89d1e22d575437179490989))

### Editors (interactive manipulator)

 - Tell user about conflicting key sequences ([b63a8c1](https://github.com/horizon-eda/horizon/commit/b63a8c1f2f70083c4ac80926382a70e90aa1f321))
 - Make zoom factor configurable ([b5303b4](https://github.com/horizon-eda/horizon/commit/b5303b460d9ef79b73a7cbee5e490f7b472617e6))
 - Add action for entering click select mode ([da13af6](https://github.com/horizon-eda/horizon/commit/da13af6b4bde5f3b73b6b6bce638471f30c81eef))
 - Use layer ranges for improved selection usability in work layer only selection filter mode ([ed7d975](https://github.com/horizon-eda/horizon/commit/ed7d975a1dce767b4a2e0a82e96cea0d3cb37e76))
 - The "add polygon vertex" tool supports adding more than one vertex per invocation ([2129b75](https://github.com/horizon-eda/horizon/commit/2129b758796b228c35ee24033d90862ddb6991e2))
 - Only show apply rules button where applicable ([22fdd70](https://github.com/horizon-eda/horizon/commit/22fdd70578eb8e5a5f2be0d95df4a752731c541f))
 - Bottom view also flips arrow keys ([6a44ebe](https://github.com/horizon-eda/horizon/commit/6a44ebe04d60d6aa0f1efa33a73dce4331148b74))
 - Rotate arbitrary tool uses reference angle ([cccf0bd](https://github.com/horizon-eda/horizon/commit/cccf0bd0ab48ddad31b169b2035375a2f1753eb2))
 - Current tool is ended before starting tools triggered externally (such as placing part) ([cf70e2a](https://github.com/horizon-eda/horizon/commit/cf70e2a2c2c4e6d73fa831081e7fcc42b1811fd0))
 - Option for showing action bar if tool is active ([8d46953](https://github.com/horizon-eda/horizon/commit/8d4695396d49bbc88afb7e829d7eb6697083c1e4))

### Schematic editor

 - Support unsetting frame ([f4491d3](https://github.com/horizon-eda/horizon/commit/f4491d3284fe3ef7cfd4ce994ff8cc2bd198d828))
 - Use more sensible shift when placing power symbols on pins ([4bc6da5](https://github.com/horizon-eda/horizon/commit/4bc6da5fc9f257f1143538a92b0aa379df3d8fdf))

### Board editor

 - Router respects find grid key ([70f2f85](https://github.com/horizon-eda/horizon/commit/70f2f8531742f884054a18df2d4f469673afaf8c))

### Pool update

 - Improved detection of cycles among pool items ([6c8a184](https://github.com/horizon-eda/horizon/commit/6c8a1840b6cb929ff7ce8ec0aef7f53a6101db45))

### Preferences

 - Search for actions by substring rather than prefix ([14aa7d7](https://github.com/horizon-eda/horizon/commit/14aa7d752a871734417eef702303399e6e66d73d))

### Pool manager

 - Only enable save button in Unit/Entity/Part editor if needed ([994927c](https://github.com/horizon-eda/horizon/commit/994927c6d1b732b2551ac3caa96804680bb083fa))
 - Use device authentication in remote tab ([69c8b92](https://github.com/horizon-eda/horizon/commit/69c8b92a455e494179ea76e86d2de5d1458ef97b))
 - Option for only showing pull requests of signed in user ([eda6b5f](https://github.com/horizon-eda/horizon/commit/eda6b5f32dcc3630a5d72084a53b153fe3a85b75))
 - It's now possible to update pull requests opened with the pool manager ([b406423](https://github.com/horizon-eda/horizon/commit/b406423a6a3182ce2d8e56fcb5c80a1f84997eb6))
 - Log window in pool/project manager ([6720349](https://github.com/horizon-eda/horizon/commit/67203496641814bd754a46c094860f55548d280b))

## Bugfixes

### Board Editor

 - DRC doesn't ignore barrel of PTH holes without pads ([5490eae](https://github.com/horizon-eda/horizon/commit/5490eae5bf79397828c6da50a8bf2c9788e75c75))
 - Use 3D model from alternate package if it has only one model ([96cf811](https://github.com/horizon-eda/horizon/commit/96cf811793915ccb2157095dcf99d1f9a4691308))
 - Parts window doesn't crash if component has no part ([cbf9df3](https://github.com/horizon-eda/horizon/commit/cbf9df3af5350a65e72ea1511c8bb095eb381a53))
 - Update refdes in unplaced list when reloading netlist ([d42e44e](https://github.com/horizon-eda/horizon/commit/d42e44e0a94c8bcb21cb8a6cc696290c56be4b1b))
 - Don't load nonexistent nets in airwire filter ([1a14686](https://github.com/horizon-eda/horizon/commit/1a146869375354bee6daeb0e990a0e0b97507c93))
 - Router doesn't crash on pads with zero polygons ([e43a830](https://github.com/horizon-eda/horizon/commit/e43a8309cb2e697318596401d54bf478c709a41d))

### Canvas

 - Fix grid rendering on some platforms ([8e457c1](https://github.com/horizon-eda/horizon/commit/8e457c1d277b857fb24dbe5ff97f33ab485e682e))

### Editors (interactive manipulator)

 - Also save on exit if a tool is active ([12bc268](https://github.com/horizon-eda/horizon/commit/12bc268785771fe17fef301e36fd978614d2cb29)) 
 - Make cursor work near head-up display ([cae3fe2](https://github.com/horizon-eda/horizon/commit/cae3fe282de3f504a51441f7940b9a24c128973a))

### Schematic editor

 - Remove nonexistent connections in copy/paste ([0ceaf2e](https://github.com/horizon-eda/horizon/commit/0ceaf2ef9686bb83af3217ca0ec4e17f7ae3b37b))
 - Update symbol text placement while placing symbol ([431f7e6](https://github.com/horizon-eda/horizon/commit/431f7e63accfd007766ba39bd9f36d739b3abc35))

### Pool/project manager

 - Increase recent list refresh interval for reduced idle CPU usage ([3570e85](https://github.com/horizon-eda/horizon/commit/3570e859e6e6ecf82e493cc5a513edcac0c03c6a))
 - Catch errors in local pool update during pool upgrade ([86e6476](https://github.com/horizon-eda/horizon/commit/86e6476b258ecbeb48066a3e33fe88a2f9ade5b9))

### Part wizard

 - Update duplicate pad name warning after linking pads ([c0d7756](https://github.com/horizon-eda/horizon/commit/c0d7756957fafda420349d18c3936473564728eb))
 - Properly check for `.json` suffix in filenames ([6598cc3](https://github.com/horizon-eda/horizon/commit/6598cc33a4f57a6634b029fac46f45ae895a70c2))

## Changed behavior

### Editors (interactive manipulator)

 - Only exit hover select mode if actually clicking one something ([a17b450](https://github.com/horizon-eda/horizon/commit/a17b4504f797d0cd6b95e4377cc1e840b2119dd1))

### Board editor

 - Plane styles got renamed to reduce confusion ([7ec340e](https://github.com/horizon-eda/horizon/commit/7ec340e30753c1eaa93ee437f10b8e9bd9589646))

# Version 1.2.1

## Bugfixes

 - Fix crash in router due to undefined behaviour ([37882e0](https://github.com/horizon-eda/horizon/commit/37882e0f9619f634d7681932f0e2b72c4ec20a93))

## Misc

 - Makefile: allow gold linker to be disabled ([6113054](https://github.com/horizon-eda/horizon/commit/6113054dc674e508ca018debabe1974c1cc994a4))

# Version 1.2.0

## Added features

 - Action bar for easy access to commonly-used actions ([136cf03](https://github.com/horizon-eda/horizon/commit/136cf038e599570819297cffe84ac951bcf61cc1))
 - Bitmap picture import for schematic, package, board ([6f7edd7](https://github.com/horizon-eda/horizon/commit/6f7edd75e634a512f669d3ba17973f4b146a7f32))
 - KiCad symbol import ([8f10971](https://github.com/horizon-eda/horizon/commit/8f109717fe4b0a59973c38b089c9d049fce79177))
 - Searchable airwire filter window ([e4842ca](https://github.com/horizon-eda/horizon/commit/e4842cae282bf63f514b199e848397dcfedb61c1))
 - Color by net in board editor ([3accc33](https://github.com/horizon-eda/horizon/commit/3accc33cafbb1808f7c699c75cb1ddc71cc69b00))
 - Configurable in-tool key sequences ([07283ce](https://github.com/horizon-eda/horizon/commit/07283ce78fce6679e0d12c158742fa759bc25ced))
 - Grid supports non-zero offset and non-square spacing ([9d96d21](https://github.com/horizon-eda/horizon/commit/9d96d2114c290a8dd9f6e00596b57265837f3c37))
 - Gate swapping ([47a5a6e](https://github.com/horizon-eda/horizon/commit/47a5a6e3336259f2e5ccab3d33f71e73a50947ab))
 - Symbol to unit cross probing ([d1f81db](https://github.com/horizon-eda/horizon/commit/d1f81db235220fb6317317bf841b5f3fe03639c1))
 - Layer pairs for switching layers after placing vias ([176b8e2](https://github.com/horizon-eda/horizon/commit/176b8e2ff2a62efa9aaeb2c5cc42da7af6beb29e))
 - Distraction-free mode ([111309c](https://github.com/horizon-eda/horizon/commit/111309c6be1d0193664dae6a93e4fa113a9d7a83))
 - References to sheets in schematic ([ca23d34](https://github.com/horizon-eda/horizon/commit/ca23d34aecde221f0c5c4c90348bc7fe2aebca53))
 
## Enhancements

 - Progressive model loading in 3D preview ([10d52d7](https://github.com/horizon-eda/horizon/commit/10d52d749d1eb931fd1b384640b093966aa5a17e))
 - Show scale bar in preview canvas ([edaa964](https://github.com/horizon-eda/horizon/commit/edaa9649d105ba6a981887534d860c0b852209bc))
 - Show placeholder in length tuning window ([38044b2](https://github.com/horizon-eda/horizon/commit/38044b2b99d795f05f3f359866f9a388b6de3851))
 - Show key sequences in context menu ([3441ff5](https://github.com/horizon-eda/horizon/commit/3441ff5ae7015e3e9e9e8d729c68b2f927e712b8))
 - Selection qualifier is remembered when switching selection tools ([9af4a65](https://github.com/horizon-eda/horizon/commit/9af4a659f144e9434f0bef1dc9a0321bc4d82743))
 - Selection is is remembered for each sheet ([273c9bc](https://github.com/horizon-eda/horizon/commit/273c9bc64080e42ea461a485898a22035712a961))
 - Make minimum line width configurable ([309e41f](https://github.com/horizon-eda/horizon/commit/309e41f2357aa9c06ee1fe5c87dcbd06b2909604))
 - Search can do exact matching rather than substring search ([266fe7a](https://github.com/horizon-eda/horizon/commit/266fe7af05ba217a2ef755cf488e5996fc63f457))
 - Show placeholder in unit editor ([8fa9452](https://github.com/horizon-eda/horizon/commit/8fa9452b467b62227f17a281bbb05a8a9029f74e))
 - Add link to pool in project manager ([66e66c6](https://github.com/horizon-eda/horizon/commit/66e66c6f1fe7dd349155813114dc96c705c1732c))
 - Move Part wizard button to Parts tab ([6ae9361](https://github.com/horizon-eda/horizon/commit/6ae93615ab72be615892730fcba99edb320293e7))
 - Improve layout of unit and entity editors ([810fdba](https://github.com/horizon-eda/horizon/commit/810fdbad87a9059446556f5b9fda855f67730836), [0119cb8](https://github.com/horizon-eda/horizon/commit/0119cb8782c998464d43bae34675a0756f4d3c20), [555f2ff](https://github.com/horizon-eda/horizon/commit/555f2ff65ecaa427db01d1ad6ce1b063af357760))
 - Make sure symbol is in view when placing symbol ([c61afdb](https://github.com/horizon-eda/horizon/commit/c61afdb6e1b1fdec9738531fc480e8583922754d))
 - Tool popover is resizable ([1240fb8](https://github.com/horizon-eda/horizon/commit/1240fb8b81549176888e25af8783c0148d0ca0fb))
 - Hint for reloading the netlist in board editor ([94e82b7](https://github.com/horizon-eda/horizon/commit/94e82b77e686c49a1b00daa9db5f1be96dc88b59))
 - Kicad package import handles circular pads ([b5125e3](https://github.com/horizon-eda/horizon/commit/b5125e3d1793f71213cdd3d0ba521ac93f5f7a2b))
 - View options menu ([4e2fb33](https://github.com/horizon-eda/horizon/commit/4e2fb333bb23a7fbb6f10a7216f073ab10f03a71))
 - Package browser can sort by pad count ([e53098d](https://github.com/horizon-eda/horizon/commit/e53098d481488b49ca6912fb4b40b46d04aebae5))
 - Show pin names in pads ([4318650](https://github.com/horizon-eda/horizon/commit/43186500bd916a77f0f44ff2f84747cc46af8de9))
 - Show net names in vias ([9adf7ca](https://github.com/horizon-eda/horizon/commit/9adf7ca6447ef575ff7c8caa076b8e9fb04ccad3))
 - Deleting a track chain also deletes vias on the way ([24e9904](https://github.com/horizon-eda/horizon/commit/24e990440851097be05a457dcab3571e4503dfc7))
 - Kicad package import handles rectangular pads with round corners ([6eb90ba](https://github.com/horizon-eda/horizon/commit/6eb90ba3b455d19f08606254e562b09aec0e1516))
 - Kicad package import handles obround pads ([27d3d7e](https://github.com/horizon-eda/horizon/commit/27d3d7eba01b7b39c5ee248c3fda967564a276b3))
 - Place via tool asks for net rather than padstack ([a1b0e49](https://github.com/horizon-eda/horizon/commit/a1b0e4955842e61ed105d1555e2599326d6dd920))
 - Draw polygon rectangle tool rememberes mode ([092fec9](https://github.com/horizon-eda/horizon/commit/092fec906916aecbe73217bb1923ff9511c0b123))
 - Rules window position is stored for each editor type ([ecb51e0](https://github.com/horizon-eda/horizon/commit/ecb51e0a2d49bb9582ade37ed9d14ce69d659a76))
 - Grid snaps to pixel grid for improved sharpness ([017049d](https://github.com/horizon-eda/horizon/commit/017049d57ad5c8f081c77166011cff2bc2fab412))
 - Update KiCad router to 5.1.6 ([9e107c6](https://github.com/horizon-eda/horizon/commit/9e107c65024dbc9d43004489b1cd013c86fd6bd9))
 - Option for moving single tracks with router ([956d8f5](https://github.com/horizon-eda/horizon/commit/956d8f5fa6dc2637449a3cad666eb86575c368b4))
 - Add router settings window ([bf00701](https://github.com/horizon-eda/horizon/commit/bf007017473129dfb036e0a6309e2fe2905a3dd0))
 - Improve router performance ([1f86cf3](https://github.com/horizon-eda/horizon/commit/1f86cf35f82c650fe3cedd8abc2532ec1eac1548), [651475c](https://github.com/horizon-eda/horizon/commit/651475c9b73faec6f4e9174fc2549c5334a9a55a), [f68df85](https://github.com/horizon-eda/horizon/commit/f68df8534fb8e7bd85a32c1e9c9f8d86f204d307))
 - Button for copying logs to clipboard ([7b9e8d8](https://github.com/horizon-eda/horizon/commit/7b9e8d840ea75a463026016f7cab0ef4db01837f))
 - Work layer only display modes ([703ea35](https://github.com/horizon-eda/horizon/commit/703ea35ef8274dacca82f778fd6d879a2d9f2372))
 - Allow changing net while placing via ([e04d8f3](https://github.com/horizon-eda/horizon/commit/e04d8f33786e57185b808e1f06fcc17027162f20))
 - Make zero-width selectables smaller ([6c8fd8e](https://github.com/horizon-eda/horizon/commit/6c8fd8ef8b769e7f61fc83a59caefddebdf15fd9))
 - Show all polygon edges when selecting polygon ([20b14f0](https://github.com/horizon-eda/horizon/commit/20b14f0541026f3224958e00d1c032cf1cdc4f63))
 - Adjust plane priorities from property sidebar ([1ad4b04](https://github.com/horizon-eda/horizon/commit/1ad4b04de230608b27e72528a631b5bd9589c23d))
 - Show planes in head-up display ([ebb804f](https://github.com/horizon-eda/horizon/commit/ebb804f6e2f495d7f9dfcaa2bc55749075589e49))
 - Don't show clarify selection menu if there's only one line/point among the selection candidates ([ab058c3](https://github.com/horizon-eda/horizon/commit/ab058c3af2793cd4b374a3f51e639775b9b8e4a3))
 - Make minimum selectable size and target snap radius configurable ([96be373](https://github.com/horizon-eda/horizon/commit/96be373247bcbde5488e70a3c5c1aef62c7e342c))
 - Add option for snapping to targets on schematic ([bff1bbf](https://github.com/horizon-eda/horizon/commit/bff1bbfca3f4687ea22ef2338378de14954a0c8a))
 - Enable scale and rotate arbitrary tool in schematic ([685469b](https://github.com/horizon-eda/horizon/commit/685469b72b4e84efd9d61dc2524233a688eb55cb))
 - Make length tuning window sortable by length ([23136ad](https://github.com/horizon-eda/horizon/commit/23136ad244e1152fcefa5cdc9e639700335c6f01))
 - Length tuning tool uses reference from length tuning window ([0d0340e](https://github.com/horizon-eda/horizon/commit/0d0340e466f5ec6d83973d2b4e9cc634e819189d))
 - Optionally bend non-orthogonal net lines when dragging ([e0eb9e3](https://github.com/horizon-eda/horizon/commit/e0eb9e3fbce1c1a8f9177d9f86935149ccd1627d))
 - Show more information when deleting a pool item ([9d813cb](https://github.com/horizon-eda/horizon/commit/9d813cba76cc72bfd2b5f0c442168c477b691b03))
 - Show infor bar with links to docs in pool manager ([5c42c2a](https://github.com/horizon-eda/horizon/commit/5c42c2ac2cfd694be3c181a0a23f1439c53231ba))

## Bugfixes

 - Resize symbol tool respects quadrant the tool was started in ([80b2b67](https://github.com/horizon-eda/horizon/commit/80b2b672d4ee5244d41fe9f6f3ece7bbf7ec4ed8))
 - Don't show empty groups in tool popover ([3f6d528](https://github.com/horizon-eda/horizon/commit/3f6d5285b92fd6c07ff8c23425a5ef412b080555))
 - Fix copying frame of current sheet to new sheet ([c437557](https://github.com/horizon-eda/horizon/commit/c437557e98dd4522dcf2e223d7e66cf0e1e28604))
 - Properly set button sensitivity in part editor ([3009711](https://github.com/horizon-eda/horizon/commit/3009711842cf8549195d98dce917cea948b8be91))
 - Annotations: Fix gap filling for multi page components ([75139e8](https://github.com/horizon-eda/horizon/commit/75139e8a24cf1484ac8373f622f68f4d692530ee))
 - Don't crash when deleting junction attached to bus ripper ([bd1e9ae](https://github.com/horizon-eda/horizon/commit/bd1e9ae5975f1257ca43c4e3b3ffb2216261c84c))
 - Ignore mechanical pads for alternate package compatibility check ([5ee3cf6](https://github.com/horizon-eda/horizon/commit/5ee3cf6e9464e259f33ea62fc6753a3fd236fed3))
 - Don't draw connection lines from no-net junctions and mechanical pads ([0328bd4](https://github.com/horizon-eda/horizon/commit/0328bd42fc7a2cf48857bf2720950c955a81b91a))
 - Copy/paste copies tracks attached to pads ([0328bd4](https://github.com/horizon-eda/horizon/commit/0328bd42fc7a2cf48857bf2720950c955a81b91a))
 - Save no parametric data in part editor ([c2795bb](https://github.com/horizon-eda/horizon/commit/c2795bb3bdfe4ffe8ac7248e58d706343ab243d2))
 - Fix pool update if not duplicating symbol ([6eb90ba](https://github.com/horizon-eda/horizon/commit/6eb90ba3b455d19f08606254e562b09aec0e1516))
 - Properly implement target snap filter in tools ([cc5c029](https://github.com/horizon-eda/horizon/commit/cc5c029e630a70fb9e3423c278a397758d998058))
 - Don't render invisible annotations ([3816fd0](https://github.com/horizon-eda/horizon/commit/3816fd0f4b23d1cbc7fed2825046256f052f0ec2))
 - Git tab doesn't crash if 3D model is used in more than one package ([867e7ec](https://github.com/horizon-eda/horizon/commit/867e7ec51a84e6098cccf944837c5d7c8c986271))
 - Update catch-all warning in rules window when switching rules ([2eb90b3](https://github.com/horizon-eda/horizon/commit/2eb90b3bcc4cdd0973fa00495df1051e04f4465a))
 - Only show catch-all warning in rules window if actually required ([2eb90b3](https://github.com/horizon-eda/horizon/commit/2eb90b3bcc4cdd0973fa00495df1051e04f4465a))
 - Show pad name overlay at the right position of pad's bounding box center isn't at origin ([ab0272d](https://github.com/horizon-eda/horizon/commit/ab0272d43c6fccfe26402f17c3daeee0d9beead8))
 - Fix pointer warping while panning ([4f963c5](https://github.com/horizon-eda/horizon/commit/4f963c5c72ceb9f1829e3c7aceb804e6edda9d3a))
 - Don't snap to invisible SMD pads ([02539c7](https://github.com/horizon-eda/horizon/commit/02539c741d6daa8410035876814386fda4259d50))
 - Avoid drive not ready errors on win32 ([9b0d1e9](https://github.com/horizon-eda/horizon/commit/9b0d1e94f7b616009bb5a81f4301bdd840b15292))
 - Prevent errors during triangulation for 3D preview ([7f1ba24](https://github.com/horizon-eda/horizon/commit/7f1ba24ebbe7bbfcdb8918afab16b57f41356281))
 - Fade unhighlighted objects to background color rather than black in dim mode ([edcdb97](https://github.com/horizon-eda/horizon/commit/edcdb97eef3d8f1ea09b3350cbf350f2dc9bd0f0))
 - Refresh units after updating pool ([2c6655a](https://github.com/horizon-eda/horizon/commit/2c6655a3f114533b77120c6303afc801299d8573))
 - Avoid exception when loading keys for unavailable tool ([182c967](https://github.com/horizon-eda/horizon/commit/182c967daf7417fc8295ec1521d07b4b898f141c))
 - Avoid crashes by using `json::at` rather than `[]` ([55505e6](https://github.com/horizon-eda/horizon/commit/55505e6c343949d262f29fa8121256ce88e051cf))
 - Use multiline text editor when placing text ([bebd57a](https://github.com/horizon-eda/horizon/commit/bebd57a8bfc9570931c66a602ae5494d9d853d69))
 - Use menu rather than cropped popover in parameter set editor ([935c270](https://github.com/horizon-eda/horizon/commit/935c270155391af9ac96e88c3fa91374ab7e86ca))
 - Keep scrolling position in unplaced box ([83ec1be](https://github.com/horizon-eda/horizon/commit/83ec1bead7e47b78596a6c080e53ad03e1636e4e))
 - Incrementally update pool when duplicating items ([8a978bf](https://github.com/horizon-eda/horizon/commit/8a978bf4a0752dedb13e1365cf3f0d37678c96c6))
 - Fix symbol pin UUID when changing a symbol's unit ([494f19a](https://github.com/horizon-eda/horizon/commit/494f19aed7cc1e061f0caa8750859a3dcf887daf))
 - Don't trigger drag when holding shift for pan ([397757d](https://github.com/horizon-eda/horizon/commit/397757d240d830d88292c326a07d47943143482d))

## Changed behavior

 - Move some actions to more appropriate groups ([e29462e](https://github.com/horizon-eda/horizon/commit/e29462e49a00974ae964e1116d0530049974cbef), [e29462e](https://github.com/horizon-eda/horizon/commit/e29462e49a00974ae964e1116d0530049974cbef))
 - Pool is updated when saving parts, not after closing the editor ([e9305b3](https://github.com/horizon-eda/horizon/commit/e9305b327022187b9ad63c928eeb7911a439e4a3))
 - Widgets in unit/entity editor rows don't receive scroll events anymore ([6e15a9e](https://github.com/horizon-eda/horizon/commit/6e15a9e02234651a7a9dca721ffa7700ea299663))
 - Center of polygon arcs and arcs gets projected onto the perpendicular bisector of start and end point to force constant radius ([ae7b293](https://github.com/horizon-eda/horizon/commit/ae7b2938e314492890dbf9a56a66c091dd888242))

## Removals

 - Place package button is gone since the same functionality is available from the unplaced list ([ac7d7c1](https://github.com/horizon-eda/horizon/commit/ac7d7c1ce24922f830432f9627bbf3c434b76146))
 - Homegrown old router tool ([079530f](https://github.com/horizon-eda/horizon/commit/079530f636117e76472c017548cfd7896b94ff53))

## Misc

 - Combine low-content pages in preferences dialog ([45770af](https://github.com/horizon-eda/horizon/commit/45770afeac6cc9a3f9a82db25bf981e19a5955c1))
 - Bump C++ version to C++17 ([35faeda](https://github.com/horizon-eda/horizon/commit/35faedad9609db0c8432ac589bdd52157e093446))

# Version 1.1.1

## Bugfixes

 - Makefile: don't build during make install ([e991aff](https://github.com/horizon-eda/horizon/commit/e991aff73919b6b0d05ea22ed7ecc2c61d8a0c0b))
 - win32: regenerate gdk pixbuf loader cache during build ([b7a128b](https://github.com/horizon-eda/horizon/commit/b7a128bed12da74accec4231baf01caa333323fe))

# Version 1.1.0

## Added features

 - Pick&place export ([bdb0af8](https://github.com/horizon-eda/horizon/commit/bdb0af86c26d50d027a2013cf52e1eaf56543af4))
 - Support replacing project metadata variables on board ([c1293e2](https://github.com/horizon-eda/horizon/commit/c1293e25a04d62c7e7a520c8b3ec3f944e6664c5))
 - Airwire filter ([145bcb1](https://github.com/horizon-eda/horizon/commit/145bcb1b9b54efed4aee7cb50b62fbf6724bf8a2))
 - Support for touchscreen pan and zoom gestures ([38ff613](https://github.com/horizon-eda/horizon/commit/38ff6139d6e8ceba7ccc2bdf234168984fc5a528), [ca1b832](https://github.com/horizon-eda/horizon/commit/ca1b8321cb7cce845eaabec28ae467e59f8c9aa9))
 - Support for "dot not populate" components ([8cf32eb](https://github.com/horizon-eda/horizon/commit/8cf32ebdecc5f6bd73578b1b5ff07c331336bec9))
 - Action for selecting all vertices of a polygon ([5d2571f](https://github.com/horizon-eda/horizon/commit/5d2571fd76ca4eb33372810dfe4897aabe16cf5a))
 - Panelisation ([188802f](https://github.com/horizon-eda/horizon/commit/188802f1e94ed23777f89c778d422b2ec6fa461f))
 - Outline layer in packages ([03f29b5](https://github.com/horizon-eda/horizon/commit/03f29b5701f9f915d777a78eb0ad74d17e875bad))
 - Automatic update of pool cache status and hint when placing out of date part ([655c084](https://github.com/horizon-eda/horizon/commit/655c08476cd14726f6d2433938d1ae9b30cd8801))
 - Recursive `git add` from git tab in pool manager ([ea5bcb4](https://github.com/horizon-eda/horizon/commit/ea5bcb420ab32d6937b76cdcf378dcc296ddcbd1))
 - Tool for resizing symbols ([21763df](https://github.com/horizon-eda/horizon/commit/21763df7d0d46a4a55b7f1a154684fe489cd5371))
 - Tool for generating silkscreen ([c314592](https://github.com/horizon-eda/horizon/commit/c314592ec88b757f0355bd6fd95ea81122ff252c))
 - Run board checks from python module ([e47e579](https://github.com/horizon-eda/horizon/commit/e47e5798957282490aa0af93cb8818a45f2a0f60))
 - Tool for rounding off polygon vertices ([b028dbe](https://github.com/horizon-eda/horizon/commit/b028dbe8c297853873521308a8d801da526106e6), [1b9a801](https://github.com/horizon-eda/horizon/commit/1b9a801a9f587501ce96cfc4de972d778e97a09e))
 - Pool update from python module ([7cd5cc2](https://github.com/horizon-eda/horizon/commit/7cd5cc2e00b78e85a29ffd7f88065ac81ce01c84))
 - Package python module as docker image ([3b047c3](https://github.com/horizon-eda/horizon/commit/3b047c3a61dfe3daf69b0612261f893c5eb384a9))
 - Export 3D rendering from python module ([619b74b](https://github.com/horizon-eda/horizon/commit/619b74b6fe1abd6f7c7c9bc835cbb8e90b3e7a1c))

## Enhancements

 - Show list of unplaced symbols in schematic ([c237eeb](https://github.com/horizon-eda/horizon/commit/c237eeb2a7f53a69f2dbc9237709b033cc6a36b6))
 - Show list of unplaced packages in board ([fabbd65](https://github.com/horizon-eda/horizon/commit/fabbd65657a2b10836c62180874695b061d70094))
 - Copy placement tool copies silkscreen ([55a3226](https://github.com/horizon-eda/horizon/commit/55a322619d57340d054a153a277df05dcf4982f2))
 - Make pool download cancellable and show download progress ([fd943ae](https://github.com/horizon-eda/horizon/commit/fd943aeddb34bbaf8902ac0a4c70b2583ce16c3e))
 - Save board display options ([fd943ae](https://github.com/horizon-eda/horizon/commit/fd943aeddb34bbaf8902ac0a4c70b2583ce16c3e))
 - Increase 3D model offset range to ±1000 mm ([fd943ae](https://github.com/horizon-eda/horizon/commit/fd943aeddb34bbaf8902ac0a4c70b2583ce16c3e))
 - Edit via tool can edit multiple vias at once ([fd943ae](https://github.com/horizon-eda/horizon/commit/fd943aeddb34bbaf8902ac0a4c70b2583ce16c3e))
 - Move project metadata such as title and author to netlist rather than having them in schematic and project file ([ef6f647](https://github.com/horizon-eda/horizon/commit/ef6f647282f759d11ee66ed86f1e103ff3fd3e2b))
 - Show name of current document in interactive manipulator window title for pool items ([72e4eec](https://github.com/horizon-eda/horizon/commit/72e4eeca2c5374e440d82a492c573a5b3e09aaed))
 - Show project title in window title of project manager, schematic and board interactive manipulator ([71e69cc](https://github.com/horizon-eda/horizon/commit/71e69ccf0713ec92504f0a93d7241b08eabf9940))
 - Show package in component head-up display ([6214fa1](https://github.com/horizon-eda/horizon/commit/6214fa1c6d90ab35bfb7f343be0e84285fd23603))
 - Support degree sign (U+00B0) in texts ([5875829](https://github.com/horizon-eda/horizon/commit/587582958876ef160f6866aaac04bc515a1f073d))
 - Support plus/minus sign (U+00B1) in texts ([3f90d8f](https://github.com/horizon-eda/horizon/commit/3f90d8f6503ced3f73d37c6a19b251d4c07de060))
 - Show status of selection filter, airwire filter and flipped view in status bar ([162a679](https://github.com/horizon-eda/horizon/commit/162a6793302870ae84c5f66fb1e3b6c8002a5270))
 - Make URLs in text clickable in head-up display ([6fd2652](https://github.com/horizon-eda/horizon/commit/6fd26526f170eee3f52c06a6a5e36a1d0e8eba7d))
 - Support for mirroring/rotating around cursor in move tool ([455599e](https://github.com/horizon-eda/horizon/commit/455599e7fa696cedd4bb68cb51ff448ca95ba7c2))
 - Search for MPNs and pin/pad names ([819687c](https://github.com/horizon-eda/horizon/commit/819687c46b466a3621cf6c4ffc9b7fa98ae564ee))
 - Support circular renumbering in renumber pads tool ([6626585](https://github.com/horizon-eda/horizon/commit/6626585e14c147c9897dafc7426f8a4c85b115e0))
 - Place pin tool can place all remaining pins at once ([97540ca](https://github.com/horizon-eda/horizon/commit/97540cac0ce71fd23438de45bfe9da97e4a4ff54))
 - Place pin tool shows preview of next autoplaced pin ([8e5335f](https://github.com/horizon-eda/horizon/commit/8e5335f2ea242040a13bc10795d62ba4e2a2da64))
 - Show pin bounding box in symbol interactive manipulator ([24a8f4b](https://github.com/horizon-eda/horizon/commit/24a8f4be5a340825a35d71a37609999c0cbe0828))
 - Selection filter dialog can be closed by escape key ([c2b169c](https://github.com/horizon-eda/horizon/commit/c2b169c48f7ffffb672a48e15bd7951bafbb569c))
 - Add context menu to recent pools and projects for opening in file browser and deleting ([040bdc7](https://github.com/horizon-eda/horizon/commit/040bdc7ae6354b85b69a89d26bfcbaa600ec4e1a))
 - Only enable export buttons if all filenames are provided ([eb2698b](https://github.com/horizon-eda/horizon/commit/eb2698bb55bff8605d53eeb6ea97b7e5e86e4f7f), [04de328](https://github.com/horizon-eda/horizon/commit/04de32871dfbbfd3af3f7d2185082d3d206da7f0), [b3b51a7](https://github.com/horizon-eda/horizon/commit/b3b51a7219390ef27a9994e64c4adcff418772c4), [2325742](https://github.com/horizon-eda/horizon/commit/2325742cacfbc9f392c301b5d8ac10d1eb9cc066), [9ac1c59](https://github.com/horizon-eda/horizon/commit/9ac1c59b2268888dc9dd6f4871064d87a5a7d917))
 - Copy paste for bus labels and bus rippers in a schematic ([3cc5375](https://github.com/horizon-eda/horizon/commit/3cc5375b98012d94cb99fffb15e2831b009ffa79))
 - Make lists in git tab sortable ([ed27677](https://github.com/horizon-eda/horizon/commit/ed2767709b670311697339343fdb96f0c5e26b21))
 - Courtyard generated by IPC footprint generator has `courtyard` parameter class ([fa9b793](https://github.com/horizon-eda/horizon/commit/fa9b793220ab053446fb6e27f61f2f73f3a05377))
 - Use tabular figures in STEP export window's progress view ([2a5cc95](https://github.com/horizon-eda/horizon/commit/2a5cc956f5e454e99af783c115aa8526a76c5dd0))
 - Improve typesetting in dimension inputs ([058fdb8](https://github.com/horizon-eda/horizon/commit/058fdb8d9a0305f88b22d6aa2c8e6b9c0c00656b))
 - Export STEP from python module ([ea5e8b2](https://github.com/horizon-eda/horizon/commit/ea5e8b2c780ab8e5b138efe468f2a664ffc30c64))
 - Support `file://` schema in Links ([fedc6f6](https://github.com/horizon-eda/horizon/commit/fedc6f6ef2a4c92bac5f4398ea376230f1c29e91))
 - Add "Work layer only" checkbox to selection filter dialog ([e464ec4](https://github.com/horizon-eda/horizon/commit/e464ec4b6266d2a0ff835af8db57cfd7b817a18f))

## Bugfixes

 - Fix copy placement tool for packages on the bottom side ([53f3ac4](https://github.com/horizon-eda/horizon/commit/53f3ac46b30d63e4d630c37bdfd1584bc849e7b7))
 - Properly escape project/pool title in recent chooser ([7777ada](https://github.com/horizon-eda/horizon/commit/7777adaed0987d524bba0f0371ef78e3ea2aa53f))
 - Fix crash when autoconnecting more than one pin per symbol ([e0567f2](https://github.com/horizon-eda/horizon/commit/e0567f2513244b503f7662cf57c20de9895a3a4b)
 - Reduce idle CPU usage in 3D preview ([162a679](https://github.com/horizon-eda/horizon/commit/162a6793302870ae84c5f66fb1e3b6c8002a5270))
 - Don't crash when encountering layer not found in layer display settings ([c11c6d9](https://github.com/horizon-eda/horizon/commit/c11c6d9d0e817fad71a80e01698a95aa1c0aa855))
 - Always remove autosaved files when exiting cleanly ([ba881b8](https://github.com/horizon-eda/horizon/commit/ba881b8fa0c3a4b2b319a02cbe38ea89f6fce008))
 - Avoid superfluous line breaks in head-up display ([5f90eaa](https://github.com/horizon-eda/horizon/commit/5f90eaae0ef3d31248a736a69133524822115e00))
 - Increase interactive manipulator to project manager socket timeout to 5 seconds to prevent socket breakage on slow machines ([ec08ec7](https://github.com/horizon-eda/horizon/commit/ec08ec7346c70db83221175e885202a9ed420cda))
 - Fix windows not getting raised on X11 and wayland when switching between project manager and interactive manipulator ([50841e5](https://github.com/horizon-eda/horizon/commit/50841e572f025c6263bffef30ce5750d0d52f932))
 - Make it possible to select polygon vertices by hover select ([3c86273](https://github.com/horizon-eda/horizon/commit/3c86273bfd84f717e9e68bff3d9f6fe4402fe002))
 - Don't smash silkscreen again if it's already omitted ([11a4c50](https://github.com/horizon-eda/horizon/commit/11a4c50c99bde77bb0da0bb21f5dc27686059e8a))
 - Delete smashed texts if package is gone during startup or netlist reload ([4f64739](https://github.com/horizon-eda/horizon/commit/4f64739468f4c20c1cd90e287e4245a7fd48ea8d))
 - Apply smooth zoom setting to all canvases ([025a46b](https://github.com/horizon-eda/horizon/commit/025a46bad0e92a77be3a67abfa41a8d2633da214), [1e6539a](https://github.com/horizon-eda/horizon/commit/1e6539a0202cd260f9560d75f979e892bb23cd2b))
 - Connect bipoles the right way round when placing them on a net line ([cf709a2](https://github.com/horizon-eda/horizon/commit/cf709a230279e2648b3434b5bde5e534f8c9925c))
 - Use WAL mode for pool databases to prevent crashes due to locked database ([4cfbe5c](https://github.com/horizon-eda/horizon/commit/4cfbe5c200a857571c593e94577bbd8fb9a7342b))
 - Automatically set window title for export file choosers based on action ([24281f3](https://github.com/horizon-eda/horizon/commit/24281f3b3b19965507e7ec6c3285a79f8cb3854a))
 - Copy/paste copies net lines attached to pins ([41c5d1e](https://github.com/horizon-eda/horizon/commit/41c5d1e117f017207c45ea802bdaff183fe69ce8))
 - Fix possible crash when copy/pasting diffpairs ([6534e8f](https://github.com/horizon-eda/horizon/commit/6534e8faebf38b8c5196dffbe73817b1fa879b3f))
 - Fix STEP export for too short slot holes ([9e3c594](https://github.com/horizon-eda/horizon/commit/9e3c59474e42fed87809f3e5d2d88544ef0c40d4))
 - Update property panels after undo/redo ([cb29541](https://github.com/horizon-eda/horizon/commit/cb29541418fb2546a3470b0d013729a61ff2b7df))
 - Use proper window title in open pool/project file chooser ([93998c0](https://github.com/horizon-eda/horizon/commit/93998c05983d17dfcb3ab63c3dc02c3fe9df6d05))
 - Fix selection preview in selection clarification menu on win32 ([db61b45](https://github.com/horizon-eda/horizon/commit/db61b4542b8f8abc51e29b50c0a9dac80f0b7e3d))
 - Fix focus passing from project manager to editor on win32 ([940aa17](https://github.com/horizon-eda/horizon/commit/940aa17dfa77869e5cbc37110b7302656b5f3998))

## Changed behavior

 - Deleting the last gate's symbol of a component in a schematic will automatically delete the entire component without the option to keep the component with no symbols visible ([f34e006](https://github.com/horizon-eda/horizon/commit/f34e006e7ddee06c1b4126611b9695c0d4498ef5))
 - Save interactive manipulator metadata such as layer visibility and grid spacing to a separate file such as `board.json.imp_meta` rather than to the board file itself ([bb1aa8c](https://github.com/horizon-eda/horizon/commit/bb1aa8c398f051d272c9576dbd783091e3a95a35))
 - Package interactive manipulator automatically deletes floating junctions and shows junctions only if selected ([acd5c44](https://github.com/horizon-eda/horizon/commit/acd5c4498f9c1d5ed4c16a0f43fba86d53bc87ad))
 - Actions in tool popover are activated with a single click rather than a double click ([576da12](https://github.com/horizon-eda/horizon/commit/576da12accf2176a836ed4634ae7feda8303efcd))

## Removals

 - `make all` doesn't include `horizon-pool` and `horizon-prj` ([12da19f](https://github.com/horizon-eda/horizon/commit/12da19f5e007891e2613015d35435c2df186b960))
 - Remove `crontab -e` style editors from `horizon-pool` ([2edd506](https://github.com/horizon-eda/horizon/commit/2edd5063f7ed4e474f22f99f6a579a4375757057))

## Misc

 - Refactor core ([fd943ae](https://github.com/horizon-eda/horizon/commit/fd943aeddb34bbaf8902ac0a4c70b2583ce16c3e))
 - Factor out search from core ([819687c](https://github.com/horizon-eda/horizon/commit/819687c46b466a3621cf6c4ffc9b7fa98ae564ee))
 - Make board rebuild a bit faster by storing a shallow copy (no expanded packages) of the board rather than a json serialisation for undo/redo ([0ffb118](https://github.com/horizon-eda/horizon/commit/0ffb11885a8176c1265d9cafafa3360ecb5721d4))
 - Make mesh generation for 3D preview independent of UI ([005ed87](https://github.com/horizon-eda/horizon/commit/005ed87d1fcef6bbedddf1f2cfe057642316d0c4))

# Version 1.0.0

No change log since this is the first versioned release.
