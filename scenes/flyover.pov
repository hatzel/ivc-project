#include "include/track/track.inc"
#include "lukas/pod.inc"
#include "t-racer/t-racer.inc"
/* #include "fabRacer/fabRacer.pov" */

camera {
  location <950, 80, 820 - clock/2>
  look_at <890, 80, 710>
  right x * 16/9
}


Track(0)

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

box {
    0, <30, 20, 100>
    translate <820, 55, 660>
    texture { Cherry_Wood }
}

/* object { */
/*     fabRacer */
/*     translate <900, 65, 710> */
/* } */
