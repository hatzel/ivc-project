#version 3.7;

#include "transforms.inc"
#include "lukas/turbine.inc"
#include "lukas/cockpit.inc"

#macro LukasPod(Position, Direction)
    union {
        object {
          LuTurbine
          Reorient_Trans(<0, -1, 0>, <0, 0, 1>)
          Reorient_Trans(<0, -1, 0>, <-1, 0, 0>)
          translate <-12, 0, 20>
        }

        object {
          LuTurbine
          Reorient_Trans(<0, -1, 0>, <0, 0, 1>)
          Reorient_Trans(<0, -1, 0>, <1, 0, 0>)
          translate <12, 0, 20>
        }

        object {
            LuCockpit
            translate <0, 0, -20>
        }

        Reorient_Trans(<0, 0, 1>, Direction)
        translate Position
    }
#end
