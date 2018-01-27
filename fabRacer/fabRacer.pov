#version 3.7;
#include "Turbine.inc"
#include "Cockpit.inc"
#include "../include/cable.inc"
#include "../include/blender_materials.inc"
#include "../include/electric/electric.inc"

camera {
  orthographic
  perspective
  location <-10, 20, 10>
  look_at <10, 0, 0>
  scale 1.6
}

light_source {
  <500, 1000, -1000>
  color White
}

background {
  color Green
}

// left turbine
object {
  Turbine(1)
  rotate 90 *  z
  rotate 180 * x
  translate -10 * z
}

// right turbine
object {
  Turbine(0)
  rotate 90 * z
  rotate 180 * x
  translate 10 * z
}

// cockpit
object {
  Cockpit
  rotate 90 * y
  translate <30, 5, 0>
}

// cables
make_cable(<5.5, 4, -10>, 0, <30, 5.5, -11.5>, 0, 0.3, Rubber)
make_cable(<5.5, 4, 10>, 0, <30, 5.5, 11.5>, 0, 0.3, Rubber)

#macro ElectricPath(V) LinearPath( <-1, 0, 6>, <-1, 0, -6>, V ) #end
#macro ElectricColor(V) <0.6,0.9,1.0> #end
//        Brightness, Thickness, Fuzzyness RollSpeed FlickerSpeed MinDist Lightscale
Electric( 0.01,       2,         0.10,     5,        10,          0.3     1)

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

/*object {
  Turbine(0)
  translate <-9, -5, 0>
}

object {
  Turbine(0)
  rotate 180 * y
  translate <-9, 5, 0>
}

object {
  Turbine(0)
  rotate 90 * x
  rotate 180 * y
  translate 4 * y
}

object {
  Turbine(0)
  rotate 90 * x
  rotate 90 * y
  translate <9, 4, 0>
}*/

/*object {
  Cockpit
}*/