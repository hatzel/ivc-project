#include "lukas/pod.inc"
#include "t-racer/t-racer.inc"
#include "fabRacer/fabRacer.pov"

#declare racer_fabian = object {
    fabRacer
    rotate y*90
    scale 0.7
    translate <0, 1, 8>
}

#declare racer_lukas = object {
    LukasPod(<0, 0, 0>, <0,0,1>)
    scale 0.5
}

#declare racer_julian = object {
    t_racer
    scale 0.6
    rotate y*180
}
