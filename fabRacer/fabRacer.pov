#version 3.7;
#include "fabRacer/Turbine.inc"
#include "fabRacer/Cockpit.inc"
#include "include/cable.inc"
#include "include/blender_materials.inc"
#include "include/electric/electric.inc"

#local Rand = seed(9001);
#local wobble = 0.7*sin(0.1*clock+Rand);

#macro ElectricPath(V) LinearPath( <-1, wobble, 6>, <-1, wobble, -6>, V ) #end
#macro ElectricColor(V) <0.6,0.9,1.0> #end
#declare fabRacer = union {
    // left turbine
    object {
      Turbine(1)
      rotate 90 *  z
      rotate 180 * x
      translate -10 * z
      translate wobble*y
    }

    // right turbine
    object {
      Turbine(0)
      rotate 90 * z
      rotate 180 * x
      translate 10 * z
      translate wobble*y
    }

    // cockpit
    object {
      Cockpit
      rotate 90 * y
      translate <30, 5, 0>
    }
    fab_make_cable(<5.5, 4+wobble, -10>, 0, <30, 5.5, -11.5>, 0, 0.3, Rubber)
    fab_make_cable(<5.5, 4+wobble, 10>, 0, <30, 5.5, 11.5>, 0, 0.3, Rubber)
//        Brightness, Thickness, Fuzzyness RollSpeed FlickerSpeed MinDist Lightscale
    Electric( 0.01,       2,         0.10,     5,        10,          0.3     1)
}

// cables

//        Brightness, Thickness, Fuzzyness RollSpeed FlickerSpeed MinDist Lightscale
/* Electric( 0.01,       2,         0.10,     5,        10,          0.3     1) */

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
