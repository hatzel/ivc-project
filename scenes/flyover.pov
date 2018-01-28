#include "include/track/track.inc"

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

