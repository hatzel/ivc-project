#macro _fan_FanBlade()
    #local bezC = 0.55191502449;
    #local bezCN = 1 - bezC;

    #local fanThickness = 0.004;
    #local fanWidth = 0.075;
    #local fanRound = 0.004;

    #local fanRoundC = fanRound * bezCN;
    prism {
        conic_sweep
        bezier_spline
        0.04, 3.8,
        32,
        // top
        <-(fanWidth - fanRound), fanThickness>, <-(fanWidth - fanRound), fanThickness>, <fanWidth - fanRound, fanThickness>, <fanWidth - fanRound, fanThickness>,
        // top right
        <fanWidth - fanRound, fanThickness>, <fanWidth - fanRoundC, fanThickness>, <fanWidth, fanThickness - fanRoundC>, <fanWidth, fanThickness - fanRound>,
        // right
        <fanWidth, fanThickness - fanRound>, <fanWidth, fanThickness - fanRound>, <fanWidth, -(fanThickness - fanRound)>, <fanWidth, -(fanThickness - fanRound)>,
        // bot right
        <fanWidth, -(fanThickness - fanRound)>, <fanWidth, -(fanThickness - fanRoundC)>, <fanWidth - fanRoundC, -fanThickness>, <fanWidth - fanRound, -fanThickness>,
        // bot
        <fanWidth - fanRound, -fanThickness>, <fanWidth - fanRound, -fanThickness>, <-(fanWidth - fanRound), -fanThickness>, <-(fanWidth - fanRound), -fanThickness>,
        // bot left
        <-(fanWidth - fanRound), -fanThickness>, <-(fanWidth - fanRoundC), -fanThickness>, <-fanWidth, -(fanThickness - fanRoundC)>, <-fanWidth, -(fanThickness - fanRound)>,
        // left
        <-fanWidth, -(fanThickness - fanRound)>, <-fanWidth, -(fanThickness - fanRound)>, <-fanWidth, fanThickness - fanRound>, <-fanWidth, fanThickness - fanRound>,
        // top left
        <-fanWidth, fanThickness - fanRound>,  <-fanWidth, fanThickness - fanRoundC>,  <-(fanWidth - fanRoundC), fanThickness>, <-(fanWidth - fanRound), fanThickness>
        rotate 15 * z + 90 * x

        texture {
            pigment { color rgb<0.01, 0.01, 0.01> }
            finish {
                phong 0.5
                reflection 0.02
            }
        }
    }
#end

#macro Fan(Radius, Position, Direction)
    #local numblades = 50;
    union {
        #for (i, 0, numblades, 1)
            object {
                _fan_FanBlade()
                rotate 360 / numblades * i * y
            }
        #end
        #local s = 1/3.8 * Radius;
        scale <s, s, s>
        Reorient_Trans(<0, 0, 1>, Direction)
        translate Position
    }
#end
