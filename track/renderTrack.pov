#include "colors.inc"
#include "textures.inc"
camera {
  location <0, 2, 0>
  look_at <0, 1, 10>
}

light_source {
  <10, 10, -10>
  color White
}

sphere {
    <0, 1, 10>, 1
    pigment { color rgb <1, 1, 1> }
    finish { ambient 0.2 diffuse 0 reflection 0.6 }
}

#declare ground = plane {
    <0, 1, 0>, 1
    texture { PinkAlabaster }
}

sky_sphere {
    pigment {
        Blue_Sky3
        scale 1
    }
}

fog {
    distance 7
    color rgbt<0.75, 0.4, 1, 0.1>
    fog_type 2
    fog_alt 1
}

ground
