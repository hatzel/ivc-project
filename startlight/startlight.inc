#include "metals.inc"
#include "colors.inc"
#include "textures.inc"
#include "../include/blender_materials.inc"

#declare arc = torus {
    30, 1
    rotate x*-90
    scale <1, 0.7, 1>
    texture {
        Rust
    }
}

#macro StartArch(waiting)
    #local num_lights = 5;
    #local dist = 3;
    union {
        object { arc }
        union {
            #for (i, 0, num_lights, 1)
            object {
                StartLight(waiting)
                translate <i*dist, 30*0.7-5, -1>
            }
            #end
            translate x*-num_lights/2*dist
        }
    }
#end


#declare display = union {
    cylinder {
        <0, 5, 0>,
        0,
        1
    }
    sphere {
        <0, 5, 0>,
        1
    }
    sphere {
        <0, 0, 0>,
        1
    }
}

#declare cutof = box {
    <-1, -1, 0>,
    <1, 6, 2>
}




#declare no_lights = intersection {
    object { display }
    object { cutof }
    texture { Rubber }
}

#macro Lightdisk(mat, enabled)
#local cyl = cylinder {
    <0, 0, 0>,
    <0, 0, 0.7>,
    0.8
    material { mat }
}

#local netural_light = union {
    object { cyl }
    difference {
        torus {
            0.8, 0.2
            rotate x*-90
            translate <0, 0, 0.1>
            scale <1, 1, 2.5>
            texture { Rubber }
        }
        cyl
    }
}
netural_light
#end

#macro StartLight(waiting)
#local green_light = object {
    Lightdisk(material { M_Green_Glass }, 1)
    translate <0, 5/4, 0.3>
}

#local red_light = object {
    Lightdisk(material { M_Ruby_Glass }, 1)
    translate <0, 5-5/4, 0.3>
}

union {
    difference {
        object {no_lights}
        object {green_light}
        object {red_light}
    }
    green_light
    #if (!waiting)
    light_source {
      <0,5/4, 0.9>, rgb <5,40,0.5> //a green light
    }
    #end
    red_light
    #if (waiting)
    light_source {
      <0,5-5/4, 0.9>, rgb <50,10,1> //a red light
    }
    #end
    rotate y*180
}
#end
