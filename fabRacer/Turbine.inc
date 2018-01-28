#version 3.7;
#include "fabRacer/MyTextures.inc"

// EnergyPlugPosition = 0 or 180
#macro Turbine(EnergyPlugPosition)
  union {
    // outer ring
    lathe {
      linear_spline
      5,
      <4, 0>, <4, 2>, <3.8, 2>, <3.8, 0>, <4, 0>
      
      texture { OrangeTexture }
    }
    
    // inner ring
    difference {
      lathe {
        linear_spline
        5,
        <3.6, 0>, <3.6, 2.5>, <3.4, 2.5>, <3.4, 0>, <3.6, 0>
      }
      
      cylinder {
        <0, -1, 0>, <0, 3, 0>, 4
        translate 5 * x
      }
      
      texture { WhiteTexture }
    }
    
    // shaft
    union {
      cylinder {
        <0, 0, 0>, <0, 3, 0>, 1
      }
      
      lathe {
        cubic_spline
        4,
        <0, 0>, <1, 0>, <0, 2>, <0, 0>
        translate 3 * y
      }
      
      texture { SilverTexture }
    }
    
    // braces
    union {
      lathe {
        linear_spline
        5,
        <1.2, 0>, <1.2, 1>, <1.4, 1>, <1.4, 0>, <1.2, 0>
      }
    
      #for (Count, 0, 11 , 1)
        box {
          <-0.1, 0.4, 1.3>, <0.1, 0.6, 3.9>
          rotate Count * 30 * y
        }
      #end
      
      texture { BrownTexture }
    }
    
    // 2nd orange ring
    cylinder {
      <0, 0, 0>, <0, -1.2, 0>, 3.8
      pigment { Orange }
    }
    
    // Middle gray ring
    cylinder {
      <0, -1.2, 0>, <0, -2.5, 0>, 3.4
      texture { DarkGrayTexture }
    }
    
    // ornaments
    #for (Count, 0, 19, 1)
      cylinder {
        <3.4, -1.2, 0>, <3.4, -2.5, 0>, 0.2
        texture { WhiteTexture }
        rotate Count * 18 * y
      }
    #end
    
    // orange-white ring
    cylinder {
      <0, -2.5, 0>, <0, -3, 0>, 4
      texture { OrangeTexture }
    }
    
    difference {
      cylinder {
        <0, -3, 0>, <0, -4.5, 0>, 4
      }
      
      lathe {
        linear_spline
        5,
        <3.9, -3.5>, <3.9, -3.7>, <4.1, -3.7>, <4.1, -3.5>, <3.9, -3.5>
      }
      
      texture { WhiteTexture }
    }
    
    // black line
    cylinder {
      <0, -4.5, 0>, <0, -4.6, 0>, 4
      texture { BlackTexture }
    }
    
    // white end ring
    cylinder {
      <0, -4.6, 0>, <0, -5, 0>, 4
      texture { WhiteTexture }
    }
    
    // dark gray end ring
    lathe {
      linear_spline
      5,
      <3.5, -5>, <3.5, -5.5>, <3.3, -5.5>, <3.3, -5>, <3.5, -5>
      texture { DarkGrayTexture }
    }
    
    // thruster
    union {
      cylinder {
        <0, -5, 0>, <0, -7, 0>, 2
      }
        
      cone {
        <0, -7, 0>, 2, <0, -7.5, 0>, 1.5
      }
        
      cylinder {
        <0, -7.5, 0>, <0, -9, 0>, 1.5
      }
      
      cone {
        <0, -9, 0>, 2, <0, -11.5, 0>, 1.5
      }
      
      texture { GrayTexture }
    }
      
    // flaps
    #local flap = prism {
      linear_spline
      linear_sweep
      0, 0.1, 5
      <-0.25, 0>, <0.25, 0>, <0.1, 2>, <-0.1, 2>, <-0.25, 0>
      
      texture { BlackTexture }
      
      rotate 100 * x
      translate <0, -11.5, 1.4>
    }
    
    #for (Count, 0, 15, 1)
      object {
        flap
        rotate Count * 22.5 * y
      }
    #end
      
    // ornaments at the thruster
    #for (Count, 0, 5, 1)
      union {
        cylinder {
          <1.6, -7, 0>, <1.6, -8, 0>, 0.2
        }
        
        torus {
          0.7, 0.2
          rotate 90 * z
          translate -8.75 * y
          translate 1.6 * x
        }
        
        texture { WhiteTexture }
        
        rotate Count * 60 * y
      }
    #end
      
    #local Ring = lathe {
      linear_spline
      5,
      <2, -5.5>, <2, -5.7>, <2.2, -5.7>, <2.2, -5.5>, <2, -5.5>
      texture { WhiteTexture }
    }
    
    object {
      Ring
    }
    
    object {
      Ring
      translate -1 * y
    }
    
    // cable connector
    cone {
      <-4, -4, 0>, 0 <-4, -5, 0>, 0.5
      texture { GrayTexture }
    }
    
    // energy plug
    difference {
      cylinder {
        <0, 1, 3.8>, <0, 1, 4.3>, 0.5
      }
      
      cylinder {
        <0, 1, 4>, <0, 1, 4.5>, 0.4
      }
      
      texture { GrayTexture }
      
      rotate EnergyPlugPosition * 180 * y
    }
  }
#end
