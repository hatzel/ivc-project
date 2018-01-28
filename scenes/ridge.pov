#include "include/track/track.inc"
#include "include/racer.inc"

Track(0, <870, 60, -120>)

camera {
  location <50, 60, -clock/2>
  look_at <0, 0, 100>
  right x * 16/9
}

#local lukas_path = spline {
    natural_spline
    -10, <0, 10, 800>
    0, <0, 5, 600>
    10, <-20, 10, 500>
    30, <-100, 15, 400>
    50, <-200, 10, 300>
    80, <-300, 5, 200>
    110, <-300, 5, 100>
    140, <-300, 5, 0>
}

#macro RightPath(delay, s)
#local Rand = seed(s);
spline {
    natural_spline
    -10+delay+rand(Rand), <0, 10, 700>
    0+delay+rand(Rand), <0, 5, 500>
    10+delay+rand(Rand), <20, 10, 300 + rand(Rand) * 20>
    30+delay+rand(Rand), <60, 15, 100 + rand(Rand) * 10>
    50+delay+rand(Rand), <80, 10, -100>
    80+delay+rand(Rand), <70, 5, -180>
    110+delay+rand(Rand), <90, 5, -280>
    140+delay+rand(Rand), <80, 5, -480>
}
#end

#local julian_path = RightPath(0, 1)
#local fab_path = RightPath(10, 2)

object {
    racer_lukas
    Spline_Trans (lukas_path, clock, y, 15, 0.15)
}

object {
    racer_julian
    Spline_Trans (julian_path, clock, y, 15, 0.15)
}

object {
    racer_fabian
    Spline_Trans (fab_path, clock, y, 15, 0.15)
}
