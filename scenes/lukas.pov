#version 3.7;

#include "transforms.inc"
#include "lukas/turbine.inc"
#include "lukas/cockpit.inc"

/* global_settings { radiosity {  } } */

camera {
    /* orthographic */
    perspective
    right <16/9, 0, 0>
    sky <0, 1, 0>
    location <0, 22, 50>
    /* location <60, 20, 0> */
    look_at <0, 0, 0>
    /* translate 1 * x */
    // translate -8 * y
    rotate <0, clock, 0>
}

light_source {
  <0, 1000, 500>
  color White
}

/* background {
  color Green
} */

sky_sphere {
    pigment {
        gradient <0,1,0>
        color_map {
          [0.0 color rgb<1,1,1>        ]
          [0.8 color rgb<0.1,0.25,0.75>]
          [1.0 color rgb<0.1,0.25,0.75>]
        }
    }
}

/*plane {
  <0, 1, 0>, -4
  pigment {
    color DarkGreen
  }
}*/

object {
  Turbine
  Reorient_Trans(<0, -1, 0>, <0, 0, 1>)
  Reorient_Trans(<0, -1, 0>, <-1, 0, 0>)
  translate <-15, 0, 20>
}

object {
  Turbine
  Reorient_Trans(<0, -1, 0>, <0, 0, 1>)
  Reorient_Trans(<0, -1, 0>, <1, 0, 0>)
  translate <15, 0, 20>
}

object {
    Cockpit
    translate <0, 0, -20>
}
