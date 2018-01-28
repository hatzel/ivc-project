#include "include/track/track.inc"
#include "include/grandstand.inc"
#include "include/house.inc"
#include "include/racer.inc"

camera {
  location <100, 40, 170 - clock>
  look_at <0, 10, 0>
  right x * 16/9
}


Track(0, <890, 60, 710>)

object {
    racer_lukas
    rotate y*180
    translate <-17, 5, 20>
}

object {
    racer_julian
    rotate y*180
    translate <17, 5, 20>
}

object {
    racer_fabian
    rotate y*180
    translate <0, 5, 50>
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

