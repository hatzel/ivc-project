#version 3.7;
#include "colors.inc"

#declare hull_texture = texture {
    pigment { color red 0.1 blue 0.1 green 0.1 transmit 0 }
    finish {
      ambient 0.1
      reflection { 0.5 metallic }
      roughness 0.001
      phong 0.5
      specular 1
    }
    normal {
      bumps 0.04
      scale 0.02
    }
  }

#declare turbine_end_texture = texture {
    pigment { color LightSteelBlue }
    finish {
      ambient 0.1
      diffuse 0.1
      /*phong .75*/
      reflection { 0.75 metallic }
      specular 1
      roughness 0.001
    }
    normal {
      bumps 0.01
      scale 0.09
    }
}

#declare flaps_texture = texture {
  pigment { color red 0.1 blue 0.05 green 0.05 transmit 0 }
  normal {
    bumps 0.5
    scale 0.5
  }
}

#declare rings_texture = texture {
  pigment { color red 0.01 blue 0.01 green 0.01 transmit 0 }
  normal {
    bumps 0.5
    scale 0.5
  }
}

#declare inner_texture = texture {
  pigment { color red 1.0 blue 0 green 0 transmit 0.3*clock}
  finish {
    ambient 0.1
    emission 1
    diffuse 0.1
    phong 0.1
  }
}
