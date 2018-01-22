#version 3.7;
#include "colors.inc"    // The include files contain
#include "stones.inc"    // pre-defined scene elements
#include "consts.inc"
#include "glass.inc"
#include "t-racer.inc"

global_settings {assumed_gamma 1.0}
background { color Green }

camera {
   orthographic
   /*fisheye*/
   /*perspective*/
   location <0, 0, -27>
   look_at  <0, 0,  0>
 }

light_source { <2, 14, -3> color White}
light_source { <0, 0, -20> color White}

/*plane { <0, 1, 0>, -1
    pigment {
      checker color Black, color Blue
    }
  }*/

sky_sphere {
  pigment {
    gradient y
    color_map {
      [ 0.5  color CornflowerBlue ]
      /* [ 0.5  color Black ] */
      [ 1.0  color MidnightBlue ]
    }
    scale 2
    translate -1
  }
}

sphere {<0,0,0> 0.2 pigment {White}}


// turbine previews

/* object { coolbine rotate <0, 0, -90> translate <-1, -5, 0> scale 1.3 }

object { coolbine rotate <90, 0, -90> translate <-7, 5, 0> scale 1.3 }

object { coolbine rotate <-90, 0, -90> translate <0, 5, 0> scale 1.3 }

object { coolbine rotate <45, 180, 45> translate <7, 1, 0> scale 1.3 }

object { coolbine rotate <45, 0, 45> translate <-7, -5, 0> scale 1.3 } */

// racer preview

object {t_racer rotate <-30, 0, 0> translate <0, 0, 0>}

object {t_racer rotate <0, 84, 0> translate <-8, 5, 0> }

object {t_racer rotate <-90, 0, 0> translate <10, -4, 0> scale 1}

object {t_racer rotate <-90, 0, 0> translate <10, -4, 0> scale 1}

/* make_t_racer(<10,0,0>, 0, 10) */



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

/*sphere {
    <0, 1, 2>, 2
    hollow
    texture {
      pigment { color White }
    }
    interior {
      ior 1.5
      caustics 0.25
    }
  }
sphere {
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
