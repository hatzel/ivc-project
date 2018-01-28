#include "include/track/track.inc"
#include "include/startsetup.inc"

camera {
  location <-8+clock/10, 10, 28-clock/6>
  look_at <-15, 5, 28-clock/7>
  angle 120
  right x * 16/9
}

Track(0, <890, 60, 710>)
