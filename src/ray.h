#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class Ray {
    private:
        point3 o;
        vec3 dir;
    public:
        Ray();
        Ray(const point3& origin, const vec3& direction);
        ~Ray();
        const point3& origin() const;
        const vec3& direction() const;
        point3 at(double t) const;
};

#endif