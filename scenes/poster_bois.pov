#include "include/round_boi.inc"
#include "colors.inc"

camera {
    location <0, 2.5, 8>
    look_at <0, 3, 0>
    right x * 16/9
}

light_source {
  <0, 1000, 500>
  color White * 0.3
}

RoundBoi(<0, 0, 0>)
RoundBoi(<-5, 0, -3>)
RoundBoi(<5, 0, -3>)
