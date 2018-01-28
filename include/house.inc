#version 3.7;

#include "include/blender_materials.inc"

#macro House()
    difference {
        union {
            sphere {
                <0, 0, 0>, 11
            }
            box {
                <-4, -1, 0>, <4, 3, 13>
            }
            cylinder {
                <0, 3, 0>, <0, 3, 13>, 4
            }
        }
        union {
            box {
                <-2, -1, 0>, <2, 3, 13.1>
            }
            cylinder {
                <0, 3, 0>, <0, 3, 13.1>, 2
            }
        }
        texture { Concrete1 }
    }
#end
