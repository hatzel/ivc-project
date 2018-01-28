#include "include/track/track.inc"
#include "include/startsetup.inc"

camera {
  location <15, 10-clock/30, 95-clock/3>
  look_at <0, 5, 70-clock/3>
  /* rotate <0, clock/2, 0> */
  right x * 16/9
}

Track(0, <890, 60, 710>)
