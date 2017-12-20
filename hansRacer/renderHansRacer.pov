#version 3.7;
#include "hansRacer.inc"

camera {
  orthographic
  // perspective
  location <0, 0, -25>
  look_at <0, 0, 0>
  translate 1 * x
  // translate -8 * y
}

light_source {
  <0, 0, -1000>
  color White
}

background {
  color Blue
}

object {
  Hansracer
  rotate <0, 0, -90>
  translate <-1, -4, 0>
}

object {
  Hansracer
  rotate <90, 0, -90>
  translate <-10, 5, 0>
}

object {
  Hansracer
  rotate <-90, 0, -90>
  translate <0, 5, 0>
}

object {
  Hansracer
  rotate <45, 180, 45>
  translate <9, 1, 0>
}
