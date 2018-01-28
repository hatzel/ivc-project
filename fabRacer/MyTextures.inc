#version 3.7
#include "colors.inc"

#declare WhiteTexture = texture {
  pigment { White }
  
  normal {
    bumps 0.2
    scale 0.8
  }
  
  finish {
    diffuse 0.9
    phong 1.0
    emission 0.1
  }
}

#declare OrangeTexture = texture {
  pigment { Orange }
  
  normal {
    bumps 0.2
    scale 0.8
  }
  
  finish {
    diffuse 0.9
    phong 1.0
    emission 0.2
  }
}

#declare GrayTexture = texture {
  pigment { Gray }
  
  normal {
    bumps 0.2
    scale 0.8
  }
  
  finish {
    diffuse 0.9
    phong 1.0
    emission 0.1
  }
}

#declare DarkGrayTexture = texture {
  pigment { DarkSlateGray }
  
  normal {
    bumps 0.2
    scale 0.8
  }
  
  finish {
    diffuse 0.9
    phong 1.0
    emission 0.1
  }
}

#declare BlackTexture = texture {
  pigment { Black }
  
  normal {
    bumps 0.2
    scale 0.8
  }
  
  finish {
    diffuse 0.9
    phong 1.0
    emission 0.1
  }
}

#declare SilverTexture = texture {
  pigment { Silver }
  
  normal {
    bumps 0.2
    scale 0.8
  }
  
  finish {
    diffuse 0.9
    phong 1.0
    emission 0.2
  }
}

#declare BrownTexture = texture {
  pigment { Brown }
  
  normal {
    bumps 0.2
    scale 0.8
  }
  
  finish {
    diffuse 0.9
    phong 1.0
    emission 0.1
  }
}
