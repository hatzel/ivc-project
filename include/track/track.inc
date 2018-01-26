#include "colors.inc"
#include "textures.inc"
#include "include/blender_materials.inc"

light_source {
  <10, 10, -10>
  color White
}

#declare water = plane {
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

#declare island = height_field {
    png "include/track/heightmap"
    smooth
    translate <-0.5, 0, -0.5>
    scale <100, 5, 100>
    /* texture { PinkAlabaster } */
    texture { Sand }
}

island
water
