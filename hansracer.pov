#include "metals.inc"


#declare outer = cone {
    <0, 0, 0>,
    1.0,
    <0, 0, 2>,
    0.9
}

/* #declare inner = */ 
/* #declare hansracer = difference { */
/*     box {0 , 0 , 1} */
/* } */
#declare inner = cone {
    <0, 0, -0.01>,
    0.99,
    <0, 0, 1.55555>,
    0.1
}

#declare hansracer = difference {
    object { outer }
    object { inner }
    texture { T_Brass_1A }
}
