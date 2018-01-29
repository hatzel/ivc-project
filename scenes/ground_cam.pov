#include "include/track/track.inc"
#include "include/racer.inc"
#include "include/grandstand.inc"
#include "include/house.inc"

#local Rand = seed(123);

#local camera_shake = spline {
    linear_spline
    0, 0
    60, 0
    62, 2
    64, -1,
    65, -2,
    67, 1
    69, 0
}

camera {
  location <0, 0.5, -400>
  look_at <0, 10, 20>
  /* angle 70 + min(clock, 80) * 0.4 */
  right x * 16/9
  rotate <0, 0, camera_shake(clock).x>
}

#macro StartPath(start, delay)
spline {
    natural_spline
    -10 + delay, start + <0, 0, -60>
    0 + delay, start + <0, 0, 5>
    60 + delay, start + <rand(Rand) - 0.5, 0, -500>
    100 + delay, start + <rand(Rand) - 0.5, 0, -1000>
}
#end

#local lukas_start = <-17, 5, 20>;
#local lukas_path = StartPath(lukas_start, 0)
#local julian_start = <17, 5, 20>;
#local julian_path = StartPath(julian_start, 5)
#local fab_start = <0, 5, 50>;
#local fab_path = StartPath(fab_start, 6)

object {
    racer_lukas
    /* #if (clock < 80)
        rotate y*180
        translate lukas_start
    #else */
        Spline_Trans (lukas_path, clock, y, 15, 0.15)
    /* #end */
}

object {
    racer_julian
    /* #if (clock < 80)
        rotate y*180
        translate julian_start
    #else */
        Spline_Trans (julian_path, clock, y, 15, 1)
    /* #end */
}

object {
    racer_fabian
    /* #if (clock < 80)
        rotate y*180
        translate fab_start
    #else */
        Spline_Trans (fab_path, clock, y, 15, 1)
    /* #end */
}

object {
    Grandstand(/*Detail*/ 1, /*Seed*/ 42)
    translate <-80, 0, 0>
}

object {
    House()
    rotate <0, -70, 0>
    translate <60, 1, -40>
}

object {
    RoundBoi(<0, 0, 0>)
    translate <52, sin(clock / 2)*0.25 + 0.5, -23>
}

Track(0, <890, 60, 710>)
