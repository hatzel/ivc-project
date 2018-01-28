#version 3.7;
#include "transforms.inc"
#include "textures.inc"
#include "include/round_boi.inc"
#include "shapes.inc"
#include "shapes3.inc"
#include "include/blender_materials.inc"

#declare LuCockpit = union {
    difference {
        intersection {
            sphere { <0, 118, 0>, 120 }
            sphere { <0, -27, 0>, 30 }
        }
        cylinder {
            <0, 0, 0>, <0, 4, 0>, 6.8
        }
        CarPaint(rgb <0.9, 0.4, 0>)
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
