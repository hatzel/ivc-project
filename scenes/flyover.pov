#include "include/track/track.inc"
#include "include/grandstand.inc"
#include "include/house.inc"
#include "include/racer.inc"

camera {
  location <950, 80, 820 - clock/2>
  look_at <890, 80, 710>
  right x * 16/9
}


Track(0, <0, 0, 0>)

object {
    racer_lukas
    translate <880, 65, 700>
}

object {
    racer_julian
    translate <900, 65, 710>
}

object {
    racer_fabian
    translate <900, 65, 710>
}

object {
    Grandstand(/*Detail*/ 1, /*Seed*/ 42)
    translate <820, 55, 660>
}

object {
    House()
    rotate <0, -70, 0>
    translate <950, 61, 670>
}

object {
    RoundBoi(<0, 0, 0>)
    translate <942, 60.5, 687>
}

