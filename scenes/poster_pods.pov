#version 3.7;

#include "colors.inc"
#include "include/racer.inc"

camera {
    location <0, 22, 90>
    look_at <0, 0, 0>
    right x * 16/9
}

light_source {
  <0, 1000, 500>
  color White * 0.3
}
object {
    racer_lukas
    /* rotate y * -180 */
    rotate y * -5
    translate <-20, 5, 45>
}

object {
    racer_julian
    /* rotate y * -180 */
    rotate y * 5
    translate <20, 5, 45>
}

object {
    racer_fabian
    /* rotate y * -180 */
    translate <0, 5, 50>
}
