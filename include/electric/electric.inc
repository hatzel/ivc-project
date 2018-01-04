// ELECTRICITY INCLUDE FILE for POV-Ray 3.1
// ****************************************
// Copyright 2001 Rune S. Johansen
   
   #version 3.7;
   
// The output is a point that moves from PointA to PointB
// as Value goes from 0.0 to 1.0
   #macro LinearPath (PointA,PointB,Value)
      (PointA*(1-Value)+PointB*Value)
   #end
   
// The output is a color vector that changes from ColorA to ColorB
// as Value goes from 0.0 to 1.0
   #macro LinearColor (ColorA,ColorB,Value)
      (
         vnormalize( ColorA*(1-Value) + ColorB*Value )
         *( vlength(ColorA)*(1-Value) + vlength(ColorB)*Value )
      )
   #end
   
// This is the Electric macro. It calls the internal _Electric macro
// specified further down.
   #macro Electric(Brightness,Thickness,Fuzzyness,RollSpeed,FlickerSpeed,MinDist)
      _Electric(0,1,ElectricPath(0),ElectricPath(1),1,-((ElectricPath(0))+(ElectricPath(1)))*100)
   #end
   
// This macro is used internally only.
// The user do not need to call this macro.
   #macro _Electric(ValueA,ValueB,PointA,PointB,Level,Offset)
      #local ValueM = (ValueA+ValueB)/2;
      #local FlickerClock = int((clock*FlickerSpeed+vturbulence(0,0,0,Offset+FlickerSpeed*z*clock).y));
      #local Turbulence = vturbulence(0,0,0,Offset-<100*FlickerClock,RollSpeed*clock,0>);
      #local PointM = (
         (PointA+PointB)/2
         +(ElectricPath(ValueM))-((ElectricPath(ValueA))+(ElectricPath(ValueB)))/2
         +Turbulence*vlength(PointA-PointB)*Fuzzyness
      );
      
      union {
        sphere {
          PointM, #if(Thickness>0) Thickness * 0.1 #end
          pigment { color rgbt 1 }
          hollow
          interior {
            media {
              emission ElectricColor(ValueM) * Brightness * 100
              intervals 3
              samples 1, 1
            }
          }
        }
      
        sphere {
          PointM, #if(Thickness>0) Thickness #end
          pigment { color rgbt 1 }
          hollow
          interior {
            media {
              emission ElectricColor(ValueM) * Brightness
              intervals 3
              samples 1, 1
            }
          }
        }
      }
      // glow {location PointM type 0 color ElectricColor(ValueM)*Brightness #if(Thickness>0) radius Thickness #end}
      #if (vlength(PointA-PointM)>MinDist) _Electric(ValueA,ValueM,PointA,PointM,Level+1,Offset+pow(3,Level)*x) #end
      #if (vlength(PointB-PointM)>MinDist) _Electric(ValueB,ValueM,PointB,PointM,Level+1,Offset+pow(3,Level)*y) #end
   #end
   