#include "include/track/track.inc"
#include "include/startsetup.inc"

camera {
  location <0, 20, 100 - clock * 0.8>
  look_at <0, 23, 0>
  angle 70 + clock * 0.4
  right x * 16/9
}

#if (clock > 80)
    Track(1, <890, 60, 710>)
#else
    Track(0, <890, 60, 710>)
#end
