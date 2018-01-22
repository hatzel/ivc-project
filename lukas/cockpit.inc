#version 3.7;
#include "transforms.inc"
#include "textures.inc"
#include "include/round_boi.inc"
#include "shapes.inc"
#include "shapes3.inc"

// https://wiki.blender.org/index.php/Extensions:2.6/Py/Scripts/Render/POV-Ray/Sample_Materials
#local Rubber =
texture {
    pigment {
        aoi
        color_map {
            [0.00 rgb <.0075, .0175, .0025>]
            [0.55 rgb <.020, .022, .024>]
            [0.65 rgb <.004, .004, .004>]
            [0.85 rgb <.006, .002, .001>]
            [1.00 rgb <.007, .004, .001>]
        }
        poly_wave 1.25
        scale 0.1
    }
    normal { bozo 0.2 scale 0.25 }
    finish {
        specular .015
        roughness .075
        brilliance 0.275
    }
}

#local Leather = texture {
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

#declare Cockpit = union {
    difference {
        intersection {
            sphere { <0, 118, 0>, 120 }
            sphere { <0, -27, 0>, 30 }
        }
        cylinder {
            <0, 0, 0>, <0, 4, 0>, 6.8
        }
        texture {
            pigment {
                color rgb <0.9, 0.4, 0>
            }
            finish {
                phong 0.95
                reflection {
                    0.05
                    metallic
                }
            }
        }
    }

    difference {
        sphere { <0, 1, 0>, 7 }
        sphere { <0, 1, 0>, 6.8 }
        cylinder {
            <0, -10, 0>, <0, 2.25, 0>, 7
        }

        texture { Glass3 }
    }

    difference {
        cylinder {
            <0, 2, 0>, <0, 2.7, 0>, 7.05
        }
        cylinder {
            <0, 0, 0>, <0, 4, 0>, 6.75
        }
        texture {
            pigment { DarkSlateGray }

            finish {
                ambient 0
                reflection 0.01
                roughness 0.05
                specular 1
            }
        }
    }

    intersection {
        union {
            box { <-100, -100, -0.7>, <100, 100, 0.7> }
            box { <-0.7, -100, -100>, <0.7, 100, 100> }
        }

        difference {
            cylinder {
                <0, -0.95, 0>, <0, 10, 0>, 14.7
            }
            cylinder {
                <0, -11, 0>, <0, 11, 0>, 7
            }
        }
        sphere { <0, -26.85, 0>, 30 }

        texture {
            pigment { DarkSlateGray }

            finish {
                ambient 0
                reflection 0.01
                roughness 0.05
                specular 1
            }
        }
    }

    union {
        object {
            Round_Box(<0, 0, 0>, <3, -0.5, 3>, 0.2, 0)
         }
        object {
            Round_Box(<0, 0, 0>, <3, 0.5, 5>, 0.2, 0)
            Reorient_Trans(<0, 0, 1>, <0, 1, -0.3>)
        }
        translate <-1.5, 1, -1.5>

        texture { Leather }
    }

    RoundBoi(<0, 1, 0>)

    union {
        cylinder {
            <0, 0, 2.3>, <0, 5, 2.3>, 0.1
            texture {
                pigment { DarkSlateGray }

                finish {
                    ambient 0
                    reflection 0.01
                    roughness 0.05
                    specular 1
                }
            }
        }
        object {
            Round_Cylinder_Tube(<0, 3.5, 2.3>, <0, 4.9, 2.3>, 0.2, 0.2, 1, 0)

            texture {
                Rubber
            }
        }
    }
}
