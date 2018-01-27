#version 3.7;
#include "MyTextures.inc"
#include "textures.inc"
#include "../include/round_boi.inc"

#declare Cockpit = union {
  object {
    RoundBoi(<0, 0, 0>)
    translate <0, -1, 15>
  }
  
  prism {
    bezier_spline
    linear_sweep
    0, 1, 48
    <-12, 0>, <-12, 0>, <-11, 0>, <-11, 0>,
    <-11, 0>, <-11, 0>, <-11, 1>, <-11, 1>,
    <-11, 1>, <-11, 1>, <-8, 3>, <-4, 3>,
    <-4, 3>, <-4, 3>, <4, 3>, <4, 3>,
    <4, 3>, <8, 3>, <11, 1>, <11, 1>,
    <11, 1>, <11, 1>, <11, 0>, <11, 0>,
    <11, 0>, <11, 0>, <12, 0>, <12, 0>,
    <12, 0>, <12, 0>, <12, 1>, <12, 1>,
    <12, 1>, <12, 3>, <4, 7>, <2, 7>,
    <2, 7>, <2, 7>, <-2, 7>, <-2, 7>,
    <-2, 7>, <-4, 7>, <-12, 3>, <-12, 1>,
    <-12, 1>, <-12, 1>, <-12, 0>, <-12, 0>
    
    
    texture { GrayTexture }
  }
  
  cone {
    <0, 1, 9>, 2.5, <0, 1, 3>, 2
    texture { WhiteTexture }
  }
  
  difference {
    sphere {
      0, 2
      texture { GrayTexture }
      scale 5 * z
      translate <0, 1, 8>
    }
    
    cylinder {
      <0, 1, 3>, <0, 1, 20>, 3
    }
  }
  
  cone {
    <0, 1, 22>, 2.5, <0, 1, 24>, 2
    texture { OrangeTexture }
  }
  
  #local cockpit_glass = sphere {
    0, 2
    hollow
    texture { Glass3 }
    scale <0, 0, 3>
    translate <0, 3.5, 15>
  }
  
  object {
    cockpit_glass
  }
  
  difference {
    cylinder {
      <0, 1, 9>, <0, 1, 22>, 2.5
      texture { WhiteTexture }
    }
    
    cockpit_glass
  }
  
  // thruster
  union {
    cylinder {
      <0, 1, 22>, <0, 1, 26>, 2
    }
    
    cylinder {
      <0, 1, 26>, <0, 1, 26.5>, 1.8
    }
    
    cylinder {
      <0, 1, 26.5>, <0, 1, 27.5>, 2
    }
    
    cylinder {
      <0, 1, 27.5>, <0, 1, 28.5>, 1.8
    }
    
    #local flap = prism {
      linear_spline
      linear_sweep
      0, 0.2, 5
      <-0.25, 0>, <0.25, 0>, <0.1, 2>, <-0.1, 2>, <-0.25, 0>
      
      texture { BlackTexture }
      
      rotate -10 * x
      translate -1.7 * y
      translate 28.5 * z
    }
    
    #for (Count, 0, 19, 1)
      object {
        flap
        rotate Count * 18 * z
        translate 1 * y
      }
    #end
    
    texture { GrayTexture }
  }

  #declare Tail_Wing_Y =
  union{
   cone  { <0,0,0>, 1.50, <0, 5.50,0>, 0.80 }
   sphere{ <0,0,0>, 0.80  scale<1,0.15,1> translate<0,5.50,0> }
   scale <1,1,0.15>
   matrix<     1, 0, 0, // shearing in x direction
           -0.30, 1, 0,
               0, 0, 1,
               0, 0, 0>
  }
               
  #declare Wing =
  union{
   cone  { <0,0,0>, 2.40,<0,5.5,0>, 1.00 }
   sphere{ <0,0,0>, 1.00 scale<1,0.15,1> translate<0,5.5,0> }
   scale <1,1,0.15>
   matrix<     1, 0, 0, //Shearing in X direction
            0.10, 1, 0,
               0, 0, 1,
               0, 0, 0>
  }
  
  object {
    Wing
    texture { GrayTexture }
    
    rotate -90 * y
    translate <0, 2.8, 26>
  }
  
  object {
    Tail_Wing_Y
    texture { DarkGrayTexture }
    
    rotate -90 * z
    rotate 90 * x
    translate <1.8, 1, 26>
  }
  
  object {
    Tail_Wing_Y
    texture { DarkGrayTexture }
    
    rotate 90 * z
    rotate -90 * x
    translate <-1.8, 1, 26>
  }
}