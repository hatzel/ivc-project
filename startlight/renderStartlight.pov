#version 3.7;
#include "startlight.inc"

camera {
  // perspective
  location <0, 0, -70>
  look_at <0, 0, 0>
  translate 1 * x
  // translate -8 * y
}

light_source {
  <0, 0, -100>
  color White
}

background {
  color Blue
}

StartArch(1)
