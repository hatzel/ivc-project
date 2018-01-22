

#macro RoundBoi(Position)
    sphere {
        Position + <0, 3 + 1 * (0.5 + 0.5 * sin(clock / 60 * (2 * pi))), 0>, 2.7
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
