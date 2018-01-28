// includes
#include "colors.inc"    // The include files contain
#include "consts.inc"
#include "t-racer/t-racer_textures.inc"
#include "include/fan.inc"

// variable settings
/* #declare shutter_steps = 12;
#declare Radius = 1.5;
#declare HullRadius = 2;
#declare OuterHullRadius = 2;
#declare HullLength = 7;
#declare Connectormargin = 1; */

#declare shutter_steps = 12;
#declare Radius = 3;
#declare HullRadius = 4;
#declare OuterHullRadius = 4;
#declare HullLength = 14;
#declare Connectormargin = 2;

// objects

// old turbine
#declare turbine_hull_part = intersection {
    difference {
      cylinder { <0,0,0>, <0,0,-3>, 1 open }
      cylinder { <0,0,1>, <0,0,-4>, 0.9 }
    }
    box { <0,0,1>, <1,1,-4> }
  }

#declare turbine_hull = union {
  object { turbine_hull_part }
  object { turbine_hull_part rotate <0,0,120>}
  object { turbine_hull_part rotate <0,0,240>}
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

// new turbine

#declare ring = difference {
    cylinder { <0,2,0>, <0,2.1,0>, 1.85
      texture {rings_texture }
    }
    cylinder { <0,-1,0>, <0,4,0>, 1.75 }
    texture { inner_texture }
}

#declare klappe = prism {
    #local Width = Radius*2*3.1415/shutter_steps;
    #local Length = 3;
    linear_sweep
    linear_spline
    0, 0.1, 5,
    <0,0>, <Length,0.3*Width>, <Length,0.7*Width>, <0,1*Width>, <0,0>
    texture { flaps_texture }
    translate -0.5*Width*z
    rotate 90*z
    translate Radius*x
    rotate 10*z+z*5*sin(ceil(clock))
}

#declare klappen = union {
  #for (i, 0, shutter_steps, 1)
  object {klappe rotate 360/shutter_steps*i*y}
  #end
}

#declare stabilizer = lathe {
    #local Width = 2;
    #local Length = 3;
    linear_spline
    6,
    <0,Length*-2>, <Width*0.2,Length*-1.75>, <Width*0.4,Length*-1.4>, <Width*0.6,Length*-0.9>, <Width*1,Length*1.6>, <Width*1,Length*2>
    /*<Width*1.3,Length*3>,<Width*1,Length*3.5>,<Width*0.6,Length*4.0>,<Width*0.4,Length*4.5>,<Width*0.2,Length*4.85>,<Width*0,Length*5>*/
    texture { turbine_end_texture }
}

#declare hull = lathe {
    #local length = HullLength;
    /*bezier_spline*/
    linear_spline
    /*4
    <2, 11>, <2, 11>, <0, 14.5>, <0, 14.5>*/
    /*linear_spline */
    16
    <OuterHullRadius*0.75,0.07*length>,<OuterHullRadius*0.75,0.07*length>,<OuterHullRadius,0.15*length>,<OuterHullRadius,0.15*length>,
    <OuterHullRadius*0.9,0.15*length>,<OuterHullRadius*0.9,0.15*length>,<OuterHullRadius*0.9,0.5*length>,<OuterHullRadius*0.9,0.5*length>,
    <OuterHullRadius,0.5*length>,<OuterHullRadius,0.5*length>,<OuterHullRadius*0.5,0.5*length>,<OuterHullRadius*0.5,0.5*length>,
    <OuterHullRadius*0.5,0.7*length>,<OuterHullRadius,0.7*length>,<OuterHullRadius,length>,<HullRadius*0.9,1*length>
    texture { hull_texture }
}

// the part where the connecting ray emerges from
#declare connectorbase = union {
    cylinder { <0,0,0>, <0,0,0.2>, 1
      texture { connector_texture }
    rotate <0,90,0>
    }
    cylinder { <0,0,0>, <0,0,0.2>, 0.5
      texture { connector_texture }
    rotate <0,90,0>
    translate <0.2,0,0>
    }
  }

#declare tturbine = union {
  Fan_Texture(OuterHullRadius*0.99, <0,HullLength*0.95,0>, <1,0,0>, t_racer_fan_texture)
  // lightning base
  object { connectorbase translate HullRadius*0.97*x translate (HullLength-Connectormargin)*y }
  // cable base
  object { connectorbase rotate <0,-90,0> translate HullRadius*0.97*z translate (HullLength-Connectormargin)*y }
  object { stabilizer }
  object { stabilizer rotate 180*z translate 12*y }
  object { hull }
  object { ring }
  object { ring translate 1*y }
  object { ring translate 0.5*y }
  object { ring translate -0.5*y }
  object { ring translate -1*y }
  object { ring translate -1.5*y scale 0.9 }
  object { klappen rotate 180*x translate 2*y }
}
