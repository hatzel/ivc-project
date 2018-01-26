#include "colors.inc"    // The include files contain
#include "stones.inc"    // pre-defined scene elements
#include "consts.inc"
#include "glass.inc"
#include "metals.inc"
#include "t-racer_textures.inc"
#include "../include/electric/electric.inc"
#include "../include/round_boi.inc"
#include "turbine.inc"
#include "cockpit.inc"


#declare ring = difference {
    cylinder { <0,2,0>, <0,2.1,0>, 1.85
      texture {rings_texture }
    }
    cylinder { <0,-1,0>, <0,4,0>, 1.75 }
      texture { inner_texture }
}
// ============= New ======

#declare shutter_steps = 12;
#declare Radius = 3;
#declare HullRadius = 4;
#declare OuterHullRadius = 4;
#declare HullLength = 14;
#declare Connectormargin = 2;

#declare flap = box { <0,0,0>, <2,0.5,4> }

#declare turbinestart = <-3,0,0>;

// old t_racer
/* #declare t_racer = union {
    object { turbine translate -3*x }
    object { flap translate min_extent (turbine) }
    object { turbine translate 3*x }
    object { racebody translate 3*z+2*y }
  } */
#macro make_t_racer(Position, Rotation, Turbinemargin)

  #local turbinemargin = Turbinemargin;
  #local RotatedPosition = vrotate(Position, Rotation);
  #macro ElectricPath(V) LinearPath( <-(turbinemargin/2)+HullRadius+Position.x, Position.y, Position.z>, < (turbinemargin/2)-HullRadius+Position.x, Position.y, Position.z>, V ) #end
  #macro ElectricColor(V) <0.4,0.7,1.0> #end
  Electric( 0.01,       2,         0.30,     0,        16,          1     )
  object { t_racer rotate Rotation translate Position}
    /* object { tturbine rotate <-90,0,0> translate -(turbinemargin/2)*x translate Position}
    object { flap translate min_extent (turbine) }
    object { tturbine rotate <-90,0,180> translate (turbinemargin/2)*x translate Position}
    object { racebody translate 7*z+2*y translate Position} */
#end

#declare t_racer = union {
  #local turbinemargin = 20;
  #macro ElectricPath(V) LinearPath( <-(turbinemargin/2)+HullRadius, 0,  -HullLength+Connectormargin>, < (turbinemargin/2)-HullRadius, 0,  -HullLength+Connectormargin>, V ) #end
  #macro ElectricColor(V) <0.4,0.7,1.0> #end
  Electric( 0.01,       2,         0.30,     0,        16,          0.5, 1     )
    object { tturbine rotate <-90,0,0> translate -(turbinemargin/2)*x }
    /*object { flap translate min_extent (turbine) }*/
    object { tturbine rotate <-90,0,180> translate (turbinemargin/2)*x }
    object { cockpit translate 17*z+2*y }
  }

// The upper one flickers very much and doesn't roll.

//           Brightness, Thickness, Fuzzyness RollSpeed FlickerSpeed MinDist

/*box {
    <-8, 0,   15>,  // Near lower left corner
    < 5, 0.6,  -1>   // Far upper right corner
    texture {
      T_Stone25     // Pre-defined from stones.inc
      scale 4       // Scale by the same amount in all
                    // directions
    }
    rotate y*20     // Equivalent to "rotate <0,20,0>"
  }*/
/*plane { <0, 1, 0>, -1
    pigment {
      checker color Black, color Blue
    }
  }*/

/*sphere {
    <0, 1, 2>, 2
    hollow
    texture {
      pigment { color Red }
    }
    interior {
      ior 1.5
      caustics 0.25
    }
  }*/
/*sphere {
    <0, 5, 2>, 1
    texture {
      pigment { color Red }
    }
  }*/

/*sky_sphere {
  pigment {
    gradient y
    color_map {
      [ 0.5  color CornflowerBlue ]
      [ 1.0  color MidnightBlue ]
    }
    scale 2
    translate -1
  }
}*/
