#version 3.7;
// Things in this file are taken from:
// https://wiki.blender.org/index.php/Extensions:2.6/Py/Scripts/Render/POV-Ray/Sample_Materials

#include "colors.inc"

// Gets everywhere, is course
#declare Sand=
  texture{
    pigment{
      color rgb <.518, .339, .138>
    }
    normal{
      bumps 5
      scale 0.01
    }
    finish{
      specular .3
      roughness .8
    }
  }

  texture{
    pigment{
      wrinkles
      scale 0.01
      color_map{
    	[0.0 color rgbt <1, .847, .644, 0>]
    	[0.2 color rgbt <.658, .456, .270, 1>]
    	[0.4 color rgbt <.270, .191, .067, .25>]
    	[0.6 color rgbt <.947, .723, .468, 0>]
    	[0.8 color rgbt <.356, .250, .047, 1>]
    	[1.0 color rgbt <.171, .136, .1, 1>]
      }
    }
  }



#declare Leather = texture {
        pigment {
            crackle
            metric 3
            turbulence .25
            color_map {
                [0.00 rgb <.015, .008, .004>]
                [0.25 rgb <.017, .008, .004>]
                [0.50 rgb <.010, .002, .004>]
                [0.75 rgb <.008, .002, .004>]
                [1.00 rgb <.006, .002, .003>]
            }
            scale 0.1
        }
        normal {
            crackle
            metric 3
            turbulence .25
            //granite .16
            scale 0.1
        }
        finish {
            specular .04
            roughness .1
        }
    }

#declare Rubber =
  texture{
    pigment{
      aoi
      color_map{
        [0.00 rgb <.0075, .0175, .0025>]
        [0.55 rgb <.020, .022, .024>]
        [0.65 rgb <.004, .004, .004>]
        [0.85 rgb <.006, .002, .001>]
        [1.00 rgb <.007, .004, .001>]
      }
      poly_wave 1.25
      scale 0.1
    }
    normal {bozo 0.2 scale 0.25}
    finish{
      specular .015
      roughness .075
      brilliance 0.275
    }
  }

#macro CarPaint(PaintColor)
    #declare PaintBright =
    pigment {
        PaintColor
    }

    #declare PaintDark =
    pigment {
        PaintColor / 2
    }

    texture {
        pigment {
            aoi
            pigment_map {
                //[0.0 PaintDark]
                [0.5 PaintDark]
                [1.0 PaintBright]
            }
        }
        normal { bozo 0.05 scale 0.1 }
        finish {
            diffuse 0.65
            brilliance 0.6
            reflection {
                rgb <.05, .05, .05>, rgb<.2,.2,.2>
                fresnel on
            }
        }
    }
#end

#macro CarPaintTuning(PaintColor)
    #local PaintBright =
    pigment {
        PaintColor
    }

    #local PaintDark =
    pigment {
        rgb <1-PaintColor.red, 1-PaintColor.green, 1-PaintColor.blue>
    }

    texture {
        pigment {
            aoi
            pigment_map {
                //[0.0 PaintDark]
                [0.5 PaintDark]
                [1 PaintBright]
            }
        }
        normal { bozo 0.05 scale 0.1 }
        finish {
            specular 0.4
            roughness 0.1
            metallic
            diffuse 0.25
            brilliance 2
            reflection {
                0.01 0.3
            }
        }
    }
#end

#declare StripesDepth = 0.01;
#declare AluminiumBase =
texture {

    pigment { rgb <0.658824, 0.658824, 0.658824> }

    normal {
        wood StripesDepth ramp_wave rotate 90*y scale 0.15
    }

    finish {
        ambient 0
        diffuse 0.35
        specular 0.25
        roughness 0.1
        reflection {
        0.00 0.96        metallic 0.5 fresnel on     falloff 1 exponent 1.25}
        brilliance 3.15


    }
}



#declare BrushedAluminium =
texture{
  average
  texture_map{
   #declare R=seed(1001);
   #declare V=0;
   #while(V<12)        // number of samples up to 256
    [1
     AluminiumBase
     normal{
      bumps StripesDepth
      scale <15, 15, 0.03>
      translate <rand(R),rand(R),rand(R)>
     }
    ]
    #declare V=V+1;
   #end
  }
}



#declare Concrete =
    texture { pigment { granite turbulence 1.5 color_map {
    [0  .25 color White color Gray75] [.25  .5 color White color Gray75]
    [.5 .75 color White color Gray75] [.75 1.1 color White color Gray75]}}
    finish { ambient 0.2 diffuse 0.3 crand 0.03 reflection 0 } normal {
    dents .5 scale .5 }}

#declare Concrete1 =
    texture { pigment { granite turbulence 1.5 color_map {
    [0  .25 color White color Gray95] [.25  .5 color White color White]
    [.5 .75 color White color White] [.75 1.1 color White color Gray85]}}
    finish { ambient 0.2 diffuse 0.3 crand 0.003 reflection 0 } normal {
    dents .5 scale .5 }}
