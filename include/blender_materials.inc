#version 3.7;

#declare Sand=
  texture{
    pigment{
      color rgb <.518, .339, .138>
    }
    normal{
      bumps 5
      scale 0.01
    }
    finish{
      specular .3
      roughness .8
    }
  }

  texture{
    pigment{
      wrinkles
      scale 0.01
      color_map{
    	[0.0 color rgbt <1, .847, .644, 0>]
    	[0.2 color rgbt <.658, .456, .270, 1>]
    	[0.4 color rgbt <.270, .191, .067, .25>]
    	[0.6 color rgbt <.947, .723, .468, 0>]
    	[0.8 color rgbt <.356, .250, .047, 1>]
    	[1.0 color rgbt <.171, .136, .1, 1>]
      }
    }
  }
