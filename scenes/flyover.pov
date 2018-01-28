#include "include/track/track.inc"
#include "lukas/pod.inc"
#include "t-racer/t-racer.inc"

camera {
  location <890, 80, 820 - clock/10>
  look_at <890, 45, 710>
  rotate <0, clock*720, 0>
  right x * 16/9
}

object {
    StartArch(0)
    scale z*-1
    translate <890, 60, 710>
}

object {
    LukasPod(<0, 0, 0>, <0,0,1>)
    scale 0.5
    translate <880, 65, 700>
}

object {
    t_racer
    scale 0.5
    translate <900, 65, 710>
}
