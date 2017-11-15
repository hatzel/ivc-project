#version 3.7;
#include "colors.inc"    // The include files contain
#include "stones.inc"    // pre-defined scene elements
#include "consts.inc"
#include "glass.inc"

global_settings {assumed_gamma 1.0}
background { color Green }

// transmit
#declare Pinkish = color red 0.9 blue 0.4 green 0.2 transmit 0.9;
/*#declare Pinkish = color 0.9 0.4 0.2 0.5;*/

camera {
   /*orthographic*/
   /*fisheye*/
   perspective
   location <0, 2, -8>
   look_at  <0, 1,  2>
 }

light_source { <2, 14, -3> color White}

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
plane { <0, 1, 0>, -1
    pigment {
      checker color Black, color Blue
    }
  }

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

box {
    <2,0,0>, <3,1,1>
    texture {
      pigment { color Red}
    }
}
box {
    <-3,0,0>,<-2,1,1>
    texture {
      pigment { color Red}
    }
}
sphere {
  <0,0,0> 1
  texture {
      pigment { color Pink}
  }
  scale <1,1,3>
}
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
