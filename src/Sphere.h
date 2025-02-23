#ifndef SPHERE_H
#define SPHERE_H

#include "Shape.h"

class Sphere : public Shape {
    private:
        vec3 center;
        vec3 radius;

    public:
        Sphere() noexcept;
        Sphere(vec3 center, vec3 radius) noexcept;
        Sphere(vec3 Ka, vec3 Kd, vec3 Ks, vec3 Km, float n, bool render, vec3 center, vec3 radius) noexcept;
        Sphere(const Sphere& Sphere) noexcept;
        Sphere(Sphere&& Sphere) noexcept;
        Sphere& operator=(const Sphere& Sphere) noexcept;
        Sphere& operator=(Sphere&& Sphere) noexcept;
        ~Sphere();
        vec3 getCenter() const noexcept;
        vec3 getNormal(const vec3& point) const override;
        double intersect(const Ray& r) const override;
        vec3 getRadius() const noexcept;
        bool setCenter(const vec3& center);
        bool setRadius(const vec3& radius);
};

#endif