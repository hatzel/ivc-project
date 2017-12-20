#include "metals.inc"
#include "colors.inc"

#declare outer = cone {
    <0, 0, 0>,
    1.0,
    <0, 0, 3>,
    0.85
}

#declare inner = cone {
    <0, 0, -0.01>,
    0.8,
    <0, 0, 1.55555>,
    0.1
}

#declare ring = cylinder {
    <0, 0, +2.5>,
    <0, 0, +2.8>,
    1.05
}

#declare simpleEnginebase = difference {
    object { outer }
    object { inner }
}

#declare fin = box {
    <-0.6,-0.1,0>,
    <0.6,0.1,5>
}

/* #declare bottom_fin = { */
/*     object { */
/*         fin */
/*         rotate -5*x */
/*         translate <0,-1.3,-2> */
/*     } */
/* } */

#declare enginebase = union {
    object { simpleEnginebase }
    object { ring }
    texture { T_Brass_1A }
}

#declare dome = sphere {
    0 1
    scale <1,1,2>
    texture {
        pigment { color Blue transmit 0.7 }
    }
}

#declare capsule = dome

#declare Hansracer = union {
    object {
        enginebase
        translate <2, 0, 0>
    }
    object {
        capsule
        translate <0, 0, 4>
    }
    object {
        enginebase
        translate <-2, 0, 0>
    }
}
