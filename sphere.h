#ifndef SHAPE_H
#define SHAPE_H

#include "hittable.h"
#include "vec3.h"


class sphere : public hittable {
public:
    sphere(const point3& center, double radius) : center_(center),  radius_(fmax(0,radius)) {}

    bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override {
        vec3 oc = center_ - r.origin();
        auto a = r.direction().length_squared();
        auto h = dot(r.direction(), oc);
        auto c = oc.length_squared() - radius_ * radius_;
        auto discriminant = h * h - a * c;
        if(discriminant < 0){
            return false;
        }

        auto sqrtd = sqrt(discriminant);

        // Find the nearest root that lies in the acceptable range.
        auto root = (h - sqrtd) / a;
        if(root <= t_min || root >= t_max){
            root = (h + sqrtd) / a;
            if(root <= t_min || root >= t_max){
                return false;
            }
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center_) / radius_;
        rec.set_face_normal(r, outward_normal);
        return true;
    }

private:
    point3 center_;
    double radius_;
};

#endif