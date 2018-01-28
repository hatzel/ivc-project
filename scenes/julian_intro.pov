#include "include/track/track.inc"
#include "include/startsetup.inc"

camera {
  location <20, 10, 30-clock/10>
  look_at <10, 5, 30-clock/10>
  angle 120
  right x * 16/9
}

Track(0, <890, 60, 710>)
