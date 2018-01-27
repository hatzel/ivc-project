#include "metals.inc"
#include "colors.inc"

#declare CactusTexture = texture {
    pigment{
        bozo
        color_map{
              [0.0 rgb <.701, .098, .654>]
              [0.5 rgb <.941, .058, .870>]
              [1.0 rgb <.505, .156, .478>]
        }
        scale 0.15
    }
    normal{
      granite .2
    }
    finish{
      brilliance 1
      //emission .1
      //Use with Radiosity instead
      specular .15
      roughness .05
    }
}

#macro Kektus(Seed)
    #local BaseDiameter = 0.5;

    #local Rand_1 = seed(Seed);

    #local base = union {
        cylinder {
            <0, 5, 0>,
            0,
            BaseDiameter
        }
        sphere {
            <0, 5, 0>
            BaseDiameter
        }
    }


    #local i = 0;
    #local NumBranches = int(30 * rand(Rand_1)) + 30;
    #local branches = union {
        #while (NumBranches > i)
            #local i = i + 1;
            cylinder {
                <0, 1.5, 0>
                0,
                0.1
                rotate <i*10, i*13, -60>
                translate <0, rand(Rand_1) * 4 + 1, 0>
            }
        #end
    }

    union {
        object { base }
        branches
        texture { CactusTexture }
    }
#end
