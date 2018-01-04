#version 3.7;

#include "turbine.inc"

camera {
  orthographic
  /* perspective */
  location <0, 0, -25>
  look_at <0, 0, 0>
  translate 1 * x
  // translate -8 * y
}

light_source {
  <0, 0, -1000>
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
  rotate <0, 90, -90>
  translate <3, 5, 0>
}

object {
  Turbine
  rotate <90, 0, -40>
  translate <-11.5, 5.5, 0>
}

object {
  Turbine
  rotate <-90, 0, -40>
  translate <-3, 4.5, 9>
}

object {
  Turbine
  rotate <135, 180, 45>
  translate <-11, -3.5, 8>
}

object {
  Turbine
  rotate <-45, 180, 45>
  translate <5, -8.5, 0>
}
