//
// Created by Leonardo Sinibaldi on 11/02/25.
//

#ifndef SPHERE_H
#define SPHERE_H



class sphere : public hittable {
public:
    sphere(const point3& center, double radius) : center(center), radius(radius) {}

    bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
        vec3 oc = center - r.origin();
        double a = r.direction().length_squared();
        double b = dot(r.direction(), oc);
        double c = oc.length_squared() - radius * radius;

        double discriminant = b*b - a*c;
        if ( discriminant < 0.0 ) {
            return false;
        }
        double sqrt_discriminant = sqrt(discriminant);

        // nearest root that is in the range t_min t_max
        double root = (b-sqrt_discriminant)/a;
        if (!ray_t.surrounds(root)) {
            root = (b + sqrt_discriminant)*a;
            if (!ray_t.surrounds(root)) {
                return false;
            }
        }

        rec.t = root;
        rec.p = r.at(rec.t);
        vec3 outward_normal = (rec.p - center) / radius;
        rec.set_face_normal(r, outward_normal);

        return true;
    };

private:
    point3 center;
    double radius;
};


#endif //SPHERE_H
