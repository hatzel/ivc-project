#version 3.7;
#include "Turbine.inc"

camera {
  orthographic
  // perspective
  location <0, 0, -20>
  look_at <0, 0, 0>
  // translate -8 * y
}

light_source {
  <500, 1000, -1000>
  color White
}

background {
  color Green
}

/*plane {
  <0, 1, 0>, -4
  pigment {
    color DarkGreen
  }
}*/

/*object {
  Turbine
  rotate <0, 0, -90>
  translate <-1, -4, 0>
}

object {
  Turbine
  rotate <90, 0, -90>
  translate <-10, 5, 0>
}

object {
  Turbine
  rotate <-90, 0, -90>
  translate <0, 5, 0>
}

object {
  Turbine
  rotate <45, 180, 45>
  translate <9, 1, 0>
}*/

object {
  Turbine
  translate <-9, -5, 0>
}

object {
  Turbine
  rotate 180 * y
  translate <-9, 5, 0>
}

object {
  Turbine
  rotate 90 * x
  rotate 180 * y
  translate 4 * y
}

object {
  Turbine
  rotate 90 * x
  rotate 90 * y
  translate <9, 4, 0>
}