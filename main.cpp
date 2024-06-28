#include "rtweekend.h"

#include "hittable.h"
#include "hittable_list.h"
#include "sphere.h"
#include "camera.h"

#include <iostream>


int main() {
    // World
    hittable_list world;

    // world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));
    world.add(make_shared<sphere>(point3(0,-0.25,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,0.25,-1.2), 0.5));

    camera cam;

    cam.aspect_ratio = 16.0 / 9.0;
    cam.image_width = 400;
    cam.samples_per_pixel = 10;
    cam.max_depth = 50;

    cam.render(world);
}

// stop here
// Fixing Shadow Acne

// link:
// https://raytracing.github.io/books/RayTracingInOneWeekend.html