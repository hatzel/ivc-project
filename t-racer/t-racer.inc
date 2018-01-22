#include "colors.inc"    // The include files contain
#include "stones.inc"    // pre-defined scene elements
#include "consts.inc"
#include "glass.inc"
#include "metals.inc"
#include "t-racer_textures.inc"
#include "../include/electric/electric.inc"
#include "../include/fan.inc"

/*global_settings {assumed_gamma 1.0}*/
/*background { color Green }*/

// transmit
#declare Pinkish = color red 0.9 blue 0.4 green 0.2 transmit 0.3;

/*#declare color_hull = color red 0.1 blue 0.1 green 0.1 transmit 0;*/
/*#declare color_turbine_end = color red 0.01 blue 0.01 green 0.01 transmit 0;*/
/*#declare color_flaps = color red 0.1 blue 0.05 green 0.05 transmit 0;*/
/*#declare color_rings = color red 0.01 blue 0.01 green 0.01 transmit 0;*/
 /*#declare Pinkish = color 0.9 0.4 0.2 0.5; */

/*camera {
   orthographic
   fisheye
   perspective
   location <0, 2, -8>
   look_at  <0, 1,  2>
 }*/

#declare turbine_hull_part = intersection {
    difference {
      cylinder {
        <0,0,0>,
        <0,0,-3>,
        1
        open
      }
      cylinder {
        <0,0,1>,
        <0,0,-4>,
        0.9
      }
    }
    box {
      <0,0,1>,<1,1,-4>
    }
  }

#declare turbine_hull = union {
  object { turbine_hull_part }
  object { turbine_hull_part rotate <0,0,120>}
  object { turbine_hull_part rotate <0,0,240>}
}


/*#declare mycone = difference {
  cone { <0,0,0> 0.5 <0,0,4> 2}
  texture {
      pigment { color Green }
  }
}*/

#declare ring = difference {
    cylinder { <0,2,0>, <0,2.1,0>, 1.85
      texture {rings_texture }
    }
    cylinder { <0,-1,0>, <0,4,0>, 1.75 }
      texture { inner_texture }
}
// ============= New ======

#declare shutter_steps = 12;
#declare Radius = 1.5;
#declare HullRadius = 2;
#declare OuterHullRadius = 2;
#declare HullLength = 7;
#declare Connectormargin = 1;

#declare klappe = prism {
    #local Width = Radius*2*3.1415/shutter_steps;
    #local Length = 1.5;
    linear_sweep
    linear_spline
    0, 0.1, 5,
    <0,0>, <Length,0.3*Width>, <Length,0.7*Width>, <0,1*Width>, <0,0>
    texture { flaps_texture }
    translate -0.5*Width*z
    rotate 90*z
    translate Radius*x
    /*rotate 30*z*clock*/
    rotate 10*z+360*z*clock
}

#declare klappen = union {
  #for (i, 0, shutter_steps, 1)
  object {klappe rotate 360/shutter_steps*i*y}
  #end
}

#declare stabilizer = lathe {
    #local Width = 1;
    #local Length = 1.5;
    linear_spline
    6,
    <0,Length*-2>, <Width*0.2,Length*-1.75>, <Width*0.4,Length*-1.4>, <Width*0.6,Length*-0.9>, <Width*1,Length*1.6>, <Width*1,Length*2>
    /*<Width*1.3,Length*3>,<Width*1,Length*3.5>,<Width*0.6,Length*4.0>,<Width*0.4,Length*4.5>,<Width*0.2,Length*4.85>,<Width*0,Length*5>*/
    texture { turbine_end_texture }
}

#declare hull = lathe {
    /*bezier_spline*/
    linear_spline
    /*4
    <2, 11>, <2, 11>, <0, 14.5>, <0, 14.5>*/
    /*linear_spline */
    16
    <OuterHullRadius*0.75,0.5>,<OuterHullRadius*0.75,0.5>,<OuterHullRadius,1>,<OuterHullRadius,1>,
    <OuterHullRadius*0.9,1>,<OuterHullRadius*0.9,1>,<OuterHullRadius*0.9,3>,<OuterHullRadius*0.9,3>,
    <OuterHullRadius,3>,<OuterHullRadius,3>,<OuterHullRadius*0.5,3>,<OuterHullRadius*0.5,3>,
    <OuterHullRadius*0.5,5>,<OuterHullRadius,5>,<OuterHullRadius,7>,<HullRadius*0.9,7>
    texture { hull_texture }
}


#declare connectorbase = union {
    cylinder { <0,0,0>, <0,0,0.1>, 0.5
      texture { connector_texture }
    rotate <0,90,0>
    }
    cylinder { <0,0,0>, <0,0,0.1>, 0.3
      texture { connector_texture }
    rotate <0,90,0>
    translate <0.1,0,0>
    }
  }

#declare coolbine = union {
  Fan_Texture(OuterHullRadius*0.99, <0,HullLength*0.95,0>, <1,0,0>, t_racer_fan_texture)
  object { connectorbase
    translate HullRadius*0.97*x
    translate (HullLength-Connectormargin)*y
  }
  object {
    stabilizer
  }
  object {
    stabilizer rotate 180*z translate 6*y
  }
  object {
    hull
  }
  object { ring }
  object { ring translate 1*y}
  object { ring translate 0.5*y }
  object { ring translate -0.5*y }
  object { ring translate -1*y }
  object { ring translate -1.5*y scale 0.9}
  object {klappen rotate 180*x translate 1*y}
}



#declare turbine = union {
  object { turbine_hull }
  cylinder { <0,0,0>, <0,0,-3>, 0.5
    texture { T_Stone25 }
  }
  cone { <0,0,0> 0.5 <0,0,4> 0
  }
  texture {
    pigment { color P_Copper1 }
  }
  finish { F_MetalC }
}

#declare c_inner_radius = 2.3;

#declare cockpitsupport = union {
  #for (i, 0, shutter_steps, 1)
  cylinder {<0,-1,0> <0,0,0> 0.3 translate -1*c_inner_radius*y rotate 360/shutter_steps*i*x}
  #end
}

#declare screen = union {
  box {<0,0,0> <1.8,0.2,1> }
}

#declare cockpit =
union {
  difference {
    torus {
      3 1
      rotate 90*z
    }
    difference {
      cylinder {
        <-1,0,0> <1,0,0> 3
        texture { hull_texture }
      }
      /* cylinder {
        <-2,0,0> <2,0,0> 1
        texture { hull_texture }
      } */
    }
    /* sphere {
      <0,1,0> 0.5
    }
    sphere {
    <0,0,0> 1
    scale <1,1,3>
    } */
    texture { turbine_end_texture }
        /* pigment { color P_Chrome5} */
    /* } */
  }
difference {
  cylinder {
    <-1,0,0> <1,0,0> 2.8
    texture { hull_texture }
  }
  cylinder {
    <-2,0,0> <2,0,0> c_inner_radius
    texture { hull_texture }
  }
}
object { cockpitsupport }
object { screen rotate 90*x rotate 10*x translate -0.9*x+-0.9*c_inner_radius*z+1*y}
box { <-1,-1*c_inner_radius,0>, <1,-0.5*c_inner_radius,0.5*c_inner_radius> texture { connector_texture } translate 0*y}
box { <-1,-1*c_inner_radius,0>, <1,-0.5*c_inner_radius,1*c_inner_radius> texture { connector_texture } translate -1.2*z rotate -60*x }
/* sphere {0 0.5} */
}


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
    /* object { coolbine rotate <-90,0,0> translate -(turbinemargin/2)*x translate Position}
    object { flap translate min_extent (turbine) }
    object { coolbine rotate <-90,0,180> translate (turbinemargin/2)*x translate Position}
    object { racebody translate 7*z+2*y translate Position} */
#end

#declare t_racer = union {
  #local turbinemargin = 10;
  #macro ElectricPath(V) LinearPath( <-(turbinemargin/2)+HullRadius, 0,  -HullLength+Connectormargin>, < (turbinemargin/2)-HullRadius, 0,  -HullLength+Connectormargin>, V ) #end
  #macro ElectricColor(V) <0.4,0.7,1.0> #end
  Electric( 0.01,       2,         0.30,     0,        16,          0.5, 1     )
    object { coolbine rotate <-90,0,0> translate -(turbinemargin/2)*x}
    /*object { flap translate min_extent (turbine) }*/
    object { coolbine rotate <-90,0,180> translate (turbinemargin/2)*x}
    object { cockpit translate 7*z+2*y }
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
