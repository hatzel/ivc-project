#include "metals.inc"


#declare outer = cone {
    <0, 0, 0>,
    1.0,
    <0, 0, 2>,
    0.9
}

#declare inner = cone {
    <0, 0, -0.01>,
    0.8,
    <0, 0, 1.55555>,
    0.1
}

#declare enginebase = difference {
    object { outer }
    object { inner }
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

#declare hansracer = union {
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
