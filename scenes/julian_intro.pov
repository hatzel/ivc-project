#include "include/track/track.inc"
#include "include/startsetup.inc"

camera {
  location <27, 10, 28-clock/7>
  look_at <10, 5, 28-clock/8>
  angle 120
  right x * 16/9
}

Track(0, <890, 60, 710>)
