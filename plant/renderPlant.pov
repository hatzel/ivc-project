#version 3.7;
#include "plant.inc"

camera {
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
  Kektus(12)
}

object {
  Kektus(123)
  translate <10, 0, 0>
}

object {
  Kektus(1234)
  translate <-10, 0, 0>
}
