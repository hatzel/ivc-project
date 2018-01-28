#version 3.7;

#include "shapes3.inc"
#include "include/round_boi.inc"

#declare Concrete =
    texture { pigment { granite turbulence 1.5 color_map {
    [0  .25 color White color Gray75] [.25  .5 color White color Gray75]
    [.5 .75 color White color Gray75] [.75 1.1 color White color Gray75]}}
    finish { ambient 0.2 diffuse 0.3 crand 0.03 reflection 0 } normal {
    dents .5 scale .5 }}

#declare Concrete1 =
    texture { pigment { granite turbulence 1.5 color_map {
    [0  .25 color White color Gray95] [.25  .5 color White color White]
    [.5 .75 color White color White] [.75 1.1 color White color Gray85]}}
    finish { ambient 0.2 diffuse 0.3 crand 0.003 reflection 0 } normal {
    dents .5 scale .5 }}

#macro _Grandstand_segment_ins(Angle, FromBottom, ToDepth, OuterIns, HeightIns)
    object {
        #local top = 40;
        #local height = (1 - FromBottom) * top;
        Segment_of_CylinderRing(/* R_out */ 600 + OuterIns, /* R_in */ 600 - ToDepth * 50, /* Height_in_Y */ height, /* Segment_Angle */ Angle)
        rotate <0, -(Angle / 2), 0>
        translate <-575, top - height + HeightIns, 0>
    }
#end

#macro _Grandstand_segment(Angle, FromBottom, ToDepth)
    _Grandstand_segment_ins(Angle, FromBottom, ToDepth, 0, 0)
#end

#macro Grandstand(Detail, Seed)
    #local Rand = seed(Seed);
    union {
        difference {
            _Grandstand_segment_ins(29.9, 0, 1, -0.1, -0.1)
            #for (Step, 0.1, 0.9, 0.1)
                _Grandstand_segment(30, Step, Step)
                #if (Detail)
                    _Grandstand_segment(28, Step - 0.01, Step - 0.01)
                #end
            #end
            texture { Concrete }
        }
        #for (Step, 0.2, 0.9, 0.1)
            #for (Seat, -13, 13, 0.5)
                #if (rand(Rand) < 0.7)
                    object {
                        RoundBoiOffset(<0, 0, 0>, rand(Rand))
                        translate <600 - (Step - 0.05) * 50, Step * 40, 0>
                        rotate <0, Seat, 0>
                        translate <-575, 0, 0>
                    }
                #end
            #end
        #end

    }
#end
