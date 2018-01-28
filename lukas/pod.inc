#version 3.7;

#include "transforms.inc"
#include "lukas/turbine.inc"
#include "lukas/cockpit.inc"
#include "include/electric/electric.inc"

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

        #macro ElectricPath(V) LinearPath( <-10, 0, 18>, <10, 0, 18>, V ) #end
        #macro ElectricColor(V) <0.6,0.9,1.0> #end
        //     Brightness, Thickness, Fuzzyness RollSpeed FlickerSpeed MinDist Lightscale
        Electric( 0.01,       2,         0.20,     4,        12,          3,      1)
        /* Electric( 0.01,       2,         0.10,     5,        10,          0.3     1) */

        Reorient_Trans(<0, 0, 1>, Direction)
        translate Position
    }
#end
