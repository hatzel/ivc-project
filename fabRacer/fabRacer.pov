#version 3.7;
#include "Turbine.inc"

camera {
  orthographic
  // perspective
  location <0, 0, -25>
  look_at <0, 0, 0>
  translate 1 * x
  // translate -8 * y
}

light_source {
  <0, 0, -1000>
  color White
}

background {
  color Green
}

/*plane {
  <0, 1, 0>, -4
  pigment {
    color DarkGreen
  }
}*/

object {
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
}

/*parametric {
  function { sin(u)*cos(v) }
  function { sin(u)*sin(v) }
  function { cos(u) }

  <0,0>, <2*pi,pi>
  contained_by { sphere{0, 1.1} }
  max_gradient 10
  accuracy 0.0001
  precompute 10 x,y,z
  pigment {rgb 1}
}*/

/* parametric {
  function { cos(2*pi*u - pi/2)*cos(2*pi*(-u+v)+pi/2) }
  function { cos(2*pi*v - pi/2)*cos(2*pi*(-u+v)+pi/2) }
  function { cos(2*pi*v - pi/2)*cos(2*pi*u-pi/2) }
  <0,0>, <0.5,1>
  contained_by { sphere { <0,0,0>, 2.5 } }
  accuracy 0.001
  max_gradient 10
  pigment { Blue }
}*/