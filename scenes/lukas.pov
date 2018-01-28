#version 3.7;

#include "transforms.inc"
#include "lukas/pod.inc"

/* global_settings { radiosity {  } } */

camera {
    /* orthographic */
    perspective
    right <16/9, 0, 0>
    sky <0, 1, 0>
    /* location <0, 160, 0> */
    location <15, 20, 40>
    look_at <0, 0, 0>
    /* translate 1 * x */
    // translate -8 * y
    /* rotate <0, clock, 0> */
}

light_source {
  <0, 1000, 500>
  color White
}

/* background {
  color Green
} */

sky_sphere {
    pigment {
        gradient <0,1,0>
        color_map {
          [0.0 color rgb<1,1,1>        ]
          [0.8 color rgb<0.1,0.25,0.75>]
          [1.0 color rgb<0.1,0.25,0.75>]
        }
    }
}

#local PodPath = spline {
    natural_spline
    -9.4, <-80, 0, -35>
    0.00042948, <-80, 0, 0>
    13.3181356728, <-45, 0, 35>
    25.721110279, <0, 0, 45>
    34.3351787599, <20, 0, 20>
    49.5554144087, <60, 0, -20>
    52.2459973684, <70, 0, -20>
    58.2623237652, <80, 0, 0>
    64.2786501621, <70, 0, 20>
    66.9692331217, <60, 0, 20>
    76.6702679436, <30, 0, 0>
    100.1647735892, <-50, 0, -35>
    105.0152910002, <-65, 0, -45>
    109.8658084111, <-80, 0, -35>
    119.2828487698, <-80, 0, 0>
}

// Aligns an object to a spline for a given time value.
// The Z axis of the object will point in the forward direction
// of the spline and the Y axis of the object will point upwards.
//
// usage:     object {MyObj Spline_Trans(MySpline, clock, y, 0.1, 0.5)}
//
// Spline:    The spline that the object is aligned to.
//
// Time:      The time value to feed to the spline, for example clock.
//
// Sky:       The vector that is upwards in your scene, usually y.
//
// Foresight: How much in advance the object will turn and bank.
//            Values close to 0 will give precise results, while higher
//            values give smoother results. It will not affect parsing
//            speed, so just find the value that looks best.
//
// Banking:   How much the object tilts when turning. Note that the amount
//            of tilting is equally much controlled by the ForeSight value.
//
// Author: Rune S. Johansen
/* #macro Spline_Trans (Spline, Time, Sky, Foresight, Banking) */

#local Dir = transform { rotate <0, clock, 0> };
object {
    LukasPod(<0, 0, -20>, <0, 0, 1>) //vtransform(<0, 0, 1>, rotate <0, clock, 0>))
    /* Spline_Trans (PodPath, clock, y, 15, 1) */
}
