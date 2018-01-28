#include "colors.inc"
#include "textures.inc"
#include "include/blender_materials.inc"
#include "include/startlight.inc"

light_source {
  <0, 1000, 0>
  color <0.25,0.5,0.1>
}

#declare water = plane {
    <0, 1, 0>, 1
    texture {
        Polished_Chrome
        normal {
            bumps 0.3
            scale 30
            turbulence 0.7 * (sin(clock)/50)
        }
    }
}

sky_sphere {
    pigment {
        Blue_Sky3
        scale 5
    }
}

fog {
    distance 0.2
    color rgbt<0.75, 0.4, 1, 0.1>
    fog_type 2
    fog_alt 1
}

#declare island = height_field {
    png "include/track/heightmap"
    smooth
    translate <-0.5, 0, -0.5>
    scale <3000, 200, 3000>
    texture {
        Sand
        scale 40
    }
}


island
water
