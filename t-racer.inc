#include "colors.inc"    // The include files contain
#include "stones.inc"    // pre-defined scene elements
#include "consts.inc"
#include "glass.inc"
#include "metals.inc"

/*global_settings {assumed_gamma 1.0}*/
/*background { color Green }*/

// transmit
#declare Pinkish = color red 0.9 blue 0.4 green 0.2 transmit 0.3;
 /*#declare Pinkish = color 0.9 0.4 0.2 0.5; */

/*camera {
   orthographic
   fisheye
   perspective
   location <0, 2, -8>
   look_at  <0, 1,  2>
 }*/

/*light_source { <2, 14, -3> color White}*/
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


#declare mycone = difference {
  cone { <0,0,0> 0.5 <0,0,4> 2}
  texture {
      pigment { color Red }
  }
}

#declare ring = difference {
    cylinder { <0,2,0>, <0,2.1,0>, 1.85
      pigment { Yellow }
    }
    cylinder { <0,-1,0>, <0,4,0>, 1.75 }
      pigment { Red }
}
// ============= New ======

#declare Steps = 6;
#declare Radius = 1.5;

#declare klappe = prism {
    linear_sweep
    linear_spline
    0,0.1,5,
    <0,0>, <2,0.3>, <2,0.7>, <0,1>,<0,0>
    pigment { Orange}
    translate -0.5*z
    rotate 90*z
    translate Radius*x
    rotate 30*z*clock
}

#declare klappen = union {
  #for (i, 0, Steps, 1)
  object {klappe rotate 360/Steps*i*y}
  #end
}

#declare coolbine = union {
  lathe {
    linear_spline
    6,
    <0,-2>, <0.2,-1.75>, <0.4,-1.4>, <0.6,-0.9>, <1,1.6>, <1.3,2>
    pigment { Red }
    finish {
      ambient .3
      phong .75
    }
  }
  lathe {
    linear_spline
    6,
    <1.5,0.5>, <2,1>, <1.8,1>, <1.8,3>, <2,3>, <2,3.2>
    pigment { Green }
    finish {
      ambient .3
      phong .75
    }
  }
  object { ring }
  object { ring translate 0.5*y }
  object { ring translate -0.5*y }
  object { ring translate -1*y }
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

#declare racebody = union {
  sphere {
    <0,1,0> 0.5
  }
  sphere {
  <0,0,0> 1
  scale <1,1,3>
  }
  texture {
      pigment { color P_Chrome5}
  }
}

#declare flap = union {
  box { <0,0,0>, <2,0.5,4> }
}

#declare turbinestart = <-3,0,0>;

#declare t_racer = union {
    object { turbine translate -3*x }
    /*object { flap translate min_extent (turbine) }*/
    object { turbine translate 3*x }
    object { racebody translate 3*z+2*y }
  }

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
