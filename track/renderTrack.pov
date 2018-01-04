#include "colors.inc"
#include "textures.inc"
camera {
  location <clock/10,5,-10>
  look_at <0, 2, 0>
  rotate <0, clock*720, 0>
}

light_source {
  <10, 10, -10>
  color White
}

/* sphere { */
/*     <0, 1, 10>, 1 */
/*     pigment { color rgb <1, 1, 1> } */
/*     finish { ambient 0.2 diffuse 0 reflection 0.6 } */
/* } */

#declare ground = plane {
    <0, 1, 0>, 1
    texture {
        Polished_Chrome
        normal {
            bumps 0.3
            scale 0.7
            turbulence 0.7 * (sin(clock)/50)
        }
    }
}

global_settings { number_of_waves 200 }

sky_sphere {
    pigment {
        Blue_Sky3
        scale 1
    }
}

fog {
    distance 5
    color rgbt<0.75, 0.4, 1, 0.1>
    fog_type 2
    fog_alt 1
}

height_field {
    png "heightmap"
    smooth
    translate <-0.5, 0, -0.5>
    scale <100, 5, 100>
    texture { PinkAlabaster }
}

ground
