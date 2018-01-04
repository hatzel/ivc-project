//EXAMPLE OF SPHERE

//Files with predefined colors and textures
#include "colors.inc"
#include "glass.inc"
#include "golds.inc"
#include "metals.inc"
#include "stones.inc"
#include "woods.inc"

//Place the camera
camera {
  sky <0,0,1>           //Don't change this
  direction <-1,0,0>    //Don't change this  
  right <-4/3,0,0>      //Don't change this
  location <30,10,1.5> //Camera location
  look_at <0,0,0>     //Where camera is pointing
  angle 15      //Angle of the view--increase to see more, decrease to see less
}

global_settings { ambient_light White }

light_source {
  <10,-10,20>   //Change this if you want to put the light at a different point
  color White*2         //Multiplying by 2 doubles the brightness
}
background { color White }

sphere { <0,0,1.5>, 1 texture {T_Stone1} }
