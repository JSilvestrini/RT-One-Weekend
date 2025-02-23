#ifndef PLANE_H
#define PLANE_H

#include "Shape.h"

class Plane : public Shape {
    private:
        vec3 normal;
        vec3 point;
    public:
        Plane() noexcept;
        Plane(vec3 normal, vec3 point) noexcept;
        Plane(vec3 Ka, vec3 Kd, vec3 Ks, vec3 Km, float n, bool render, vec3 normal, vec3 point) noexcept;
        Plane(const Plane& plane) noexcept;
        Plane(Plane&& plane) noexcept;
        Plane operator=(const Plane& plane) noexcept;
        Plane operator=(Plane&& plane) noexcept;
        ~Plane();
        vec3 getNormal(const vec3& point) const override;
        vec3 getPoint() const noexcept;
        double intersect(const Ray& r) const override;
        bool setNormal(const vec3& normal);
        bool setPoint(const vec3& point);
};

#endif