#version 3.7;

#macro RoundBoiOffset(Position, Offset)
    sphere {
        Position + <0, 3 + 1 * (0.5 + 0.5 * sin((clock / 60 + Offset) * (2 * pi))), 0>, 2.7
        scale <0.5, 1, 0.5>

        texture {
            pigment {
                color rgb<0.2, 0.1, 1>
            }
            finish {
                ambient 0.5
                specular 0.3
            }
        }
    }
#end

#macro RoundBoi(Position)
    RoundBoiOffset(Position, 0)
#end
