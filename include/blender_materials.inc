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
