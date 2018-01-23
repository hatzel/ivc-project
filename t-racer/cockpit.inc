#include "t-racer_textures.inc"

#declare c_inner_radius = 4.3;
/* #declare c_inner_radius = 5.3; */
#declare c_outer_radius = 5.3;
#declare seatheight = c_inner_radius/4;

#declare cockpitsupport = union {
  #for (i, 0, shutter_steps, 1)
  cylinder {<0,-c_outer_radius,0> <0,0,0> 0.3 translate -1*c_inner_radius*y rotate 360/shutter_steps*i*x}
  #end
}

#declare screen = union {
  box {<0,0,0> <0.9*c_outer_radius/3,0.2,0.5*c_outer_radius/3> }
}
#declare seat = union {
  #local seat_width = 1;
  #local seat_depth = 0.5*c_inner_radius;
  difference {
    box { <-seat_width,-c_inner_radius,0>, <seat_width,-seat_depth,seat_depth> texture { connector_texture } translate 0*y}
    box { <-0.8*seat_width,-1.5*seat_depth,-1>, <0.8*seat_width,-0.5*seat_depth,0.9*seat_depth> texture { connector_texture } }
  }
  box { <-1,-0.7*c_inner_radius,0>, <1,-0.5*c_inner_radius,1*c_inner_radius> texture { connector_texture } translate -seatheight*2.3*z rotate -60*x }
}

#declare cockpit = union {
  #local width_scale = c_outer_radius/3;
  difference {
    torus {
      c_outer_radius width_scale
      rotate 90*z
    }
    difference {
      cylinder {
        <-width_scale,0,0> <width_scale,0,0> c_outer_radius
        texture { hull_texture }
      }
      /* cylinder {
        <-2,0,0> <2,0,0> 1
        texture { hull_texture }
      } */
    }
    /* sphere {
      <0,1,0> 0.5
    }
    sphere {
    <0,0,0> 1
    scale <1,1,3>
    } */
    texture { turbine_end_texture }
        /* pigment { color P_Chrome5} */
    /* } */
  }
  difference {
    cylinder {
      <-width_scale,0,0> <width_scale,0,0> c_outer_radius-0.5*width_scale/2
      texture { hull_texture }
    }
    cylinder {
      <-2*width_scale,0,0> <2*width_scale,0,0> c_inner_radius
      texture { hull_texture }
    }
  }
  object { cockpitsupport }
  object { screen rotate 90*x rotate 10*x translate -0.9*x+-0.95*c_inner_radius*z+1*y}
  object { seat }
  /* sphere {0 0.5} */
  RoundBoi(<0,-c_inner_radius,0>)
}
