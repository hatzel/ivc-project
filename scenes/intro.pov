#version 3.7;
// 8 frames nix
// 12 frames long ago fade-in
// @4s fade-out, 12 frames
// 76 frames black
// povracing logo starting at 1.5x screen height, stars come in at the same time
// moving back in space
// @17s, crawl in from bottom, logo fades to black in ~55 frames at ~1/20x screen height
// @1m26s, crawl fades out

#include "stars.inc"
#include "colors.inc"
#include "textures.inc"

#local s = 24;
/* #local frame = 65*s; */
#local frame = clock;

#local logo_in = 6*s;
#local crawl_in = 15*s;
#local crawl_out = 30*s;

#local CameraXRot = spline {
    linear_spline
    0 0
    crawl_out + 1*s 0
    crawl_out + 8*s 30
    /* 70.1*s 30 */
}

camera {
    perspective
    right <16/9, 0, 0>
    sky <0, 1, 0>
    location <0, 0, 0>
    look_at <0, 0, 9>
    rotate <CameraXRot(frame).x, 0, 0>
}

sky_sphere {
	pigment {
		bozo
		color_map {
			[0.0 White*3]
			[0.17 Black]
			[1.0 Black]
		}
		scale .006
	}
}

sphere {
    <0, -10100, 0>, 10000
    pigment {
        aoi
        pigment_map {
            [0.5 rgb<0.9, 0.5, 1>]
            [0.55 rgb<0.38, 0.1, 0.68>]
            [0.6 rgb<0.3, 0, 0.6>]
        }
    }
    rotate <30, 0, 0>
}

#local LongTimeAlpha = spline {
    linear_spline
           0  0
           7  0
          19  1
         4*s  1
    4*s + 12  0
}

box {
    <-8, -4.5, 9.1>, <8, 4.5, 9.1>
    texture {
        pigment {
            image_map {
                png "img/long_time_ago"
                once
                interpolate 2
                transmit all 1 - LongTimeAlpha(frame).x
            }
            translate <-0.5, -0.5, 0>
            scale <16,9,1>
        }
       finish { emission 1 }
    }
    no_shadow
}

#local PovracingAlpha = spline {
    linear_spline
              0  0
    logo_in - 1  0
        logo_in  1
       crawl_in  1
  crawl_in + 55  0
}
#local PovracingZ = spline {
    linear_spline
    logo_in - 1 3
    logo_in 3
    crawl_in + 55 80
}

box {
    <-8, -4.5, PovracingZ(frame).x>, <8, 4.5, PovracingZ(frame).x>
    texture {
        pigment {
            /* rgb<0.3, 0, 0> */
            image_map {
                png "img/povracing"
                once
                interpolate 2
                transmit all 1 - PovracingAlpha(frame).x
            }
            translate <-0.5, -0.5, 0>
            scale <16,9,1>
        }
       finish { emission 1 }
    }
    no_shadow
}

#local CrawlYOffset = spline {
    linear_spline
    0 0
    crawl_in 0
    crawl_out 20
};

#local CrawlAlpha = spline {
    linear_spline
    0 1
    crawl_out - 55 1
    crawl_out 0
}

box {
    /* <-1, -1, 9.101>, <1, 1, 9.101> */
    /* <-8, -4.5, 9.1>, <8, 4.5, 9.1> */
    <-8, 0, 0>, <8, -48, 0>
    texture {

        pigment {
            /* rgb<0.1, 0, 0> */
            image_map {
                png "img/crawl"
                once
                interpolate 2
                transmit all 1 - CrawlAlpha(frame).x
            }
            translate <-0.5, -1, 0>
            scale <16,48,1>
        }
       finish { emission 1 }
    }
    translate <0, CrawlYOffset(frame).x + 1, 0>
    rotate x * 65
    translate z * 9.101
    translate y * -4
    no_shadow
}
