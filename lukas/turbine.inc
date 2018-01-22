#version 3.7;

#include "colors.inc"
#include "shapes.inc"
#include "shapes3.inc"
#include "metals.inc"
#include "include/fan.inc"

#local bezC = 0.55191502449;
#local bezCN = 1 - bezC;


#declare Winglet = object{
    Round_Conic_Prism(
        6.4, // >0, vertical center distance
        0.5, // >0, upper radius
        0.2, // >0, lower radius
        2.5, //>2*border radius, length in z-
        0.19, // border radius,
        // max. = min(lower radius, upper radius)!
        0 // Merge_On: 0 or 1
    )
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
    scale <1, 1, 1>
    rotate <0, 0, 180>
    translate <0, 6.8, -3.7>
}

#declare cradius = 0.07;
#declare cradiusC = cradius * bezCN;
#declare endradius = 0.5;

#declare Turbine = union {
    union {
        #for (a, -25, 25, 25)
            object {
                Winglet
                rotate a * y
            }
        #end
    }

    Fan(3.8, <0, 1, 0>, <0, 0, 1>)

    union {
        #for (i, 0, 60, 1)
            object {
                Round_Box(<-0.1, 3, 3.65>, <0.1, 6, 3.8>, 0.05, 0)
                texture {
                    pigment { color rgb<0.01, 0.01, 0.01> }
                    finish {
                        phong 0.5
                        reflection 0.02
                    }
                }
                rotate 360 / 60 * i * y
            }
        #end
    }
    lathe {
        bezier_spline
        4
        <0, -2>, <0.7, -1>, <1, 0.3>, <1, 1>

        texture {
            pigment { LightSteelBlue }
            finish {
                ambient .1
                diffuse .1
                specular 1
                roughness .001
                reflection {
                    .75
                    metallic
                }
            }
        }
    }
    lathe {
        bezier_spline
        4
        <2, 11>, <2, 11>, <0, 14.5>, <0, 14.5>

        texture {
            pigment { LightSteelBlue }
            finish {
                ambient .1
                diffuse .1
                specular 1
                roughness .001
                reflection {
                    .75
                    metallic
                }
            }
        }
    }
    lathe {
        bezier_spline
        56,
        // front inner
        <4 - endradius, 3>, <4 - endradius, 3>, <4 - endradius, cradius>, <4 - endradius, cradius>,
        // front inner corner
        <4 - endradius, cradius>, <4 - endradius, cradiusC>, <4 - endradius + cradiusC, 0>, <4 - endradius + cradius, 0>,
        // front
        <4 - endradius + cradius, 0>,  <4 - endradius + cradius, 0>, <4 - cradius, 0>, <4 - cradius, 0>
        // front outer corner
        <4 - cradius, 0>, <4 - cradiusC, 0>, <4, 0 + cradiusC>, <4, 0 + cradius>,
        // first flat piece
        <4, 0 + cradius>, <4, 0 + cradius>, <4, 3>, <4, 3>,
        // dip
        /* <4, 3>, <3.3, 4>, <3.3, 5.5>, <4, 6>,  */
        <4, 3>, <4, 3.5>, <3.7, 3.5>, <3.7, 3.5>,
        <3.7, 3.5>, <3.7, 3.5>, <3.7, 5.5>, <3.7, 5.5>,
        <3.7, 5.5>, <3.7, 5.5>, <4, 5.5>, <4, 6>,
        // secnd flat
        <4, 6>, <4, 6>, <4, 7>, <4, 7>,

        // narrowing
        <4, 7>, <4, 7>, <3, 7>, <2.7, 12 - cradius>,
        // back outer corner
        <2.7, 12 - cradius>, <2.7, 12 - cradiusC>, <2.7 - cradiusC, 12>, <2.7 - cradius, 12>,
        // back
        <2.7 - cradius, 12>, <2.7 - cradius, 12>, <2.7 - endradius + cradius, 12>, <2.7 - endradius + cradius, 12>,
        // back inner corner
        <2.7 - endradius + cradius, 12>, <2.7 - endradius + cradiusC, 12>, <2.7 - endradius, 12 - cradiusC>, <2.7 - endradius, 12 - cradius>
        // back inner
        <2.7 - endradius, 12 - cradius>, <2.7 - endradius, 12 - cradius>, <2.7 - endradius, 6>, <2.7 - endradius, 6>

        texture {
            pigment { DarkSlateGray }

            /* normal {
                bumps 0.02
                scale 0.001
            } */

            finish {
                ambient 0
                reflection 0.01
                /* roughness 0.001 */
                roughness 0.05
                /*phong 0.5*/
                specular 1
            }
        }
    }
}
