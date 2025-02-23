#ifndef SHAPE_H
#define SHAPE_H

#include "vec3.h"
#include "ray.h"
#include <algorithm>

class Shape {
    private:
        vec3 Ka;
        vec3 Kd;
        vec3 Ks;
        vec3 Km;
        float n;
        bool render;
    public:
        Shape() noexcept;
        Shape(vec3 Ka, vec3 Kd, vec3 Ks, vec3 Km, float n, bool render) noexcept;
        Shape(const Shape& shape) noexcept;
        Shape(Shape&& shape) noexcept;
        Shape& operator=(const Shape& shape) noexcept;
        Shape& operator=(Shape&& shape) noexcept;
        ~Shape();
        vec3 getKa() const noexcept;
        vec3 getKd() const noexcept;
        vec3 getKs() const noexcept;
        vec3 getKm() const noexcept;
        float getN() const noexcept;
        bool getRender() const noexcept;
        virtual vec3 getNormal(const vec3& point) const;
        virtual double intersect(const Ray& r) const;
        bool setKa(const vec3& ka);
        bool setKd(const vec3& kd);
        bool setKs(const vec3& ks);
        bool setKm(const vec3& km);
        bool setN(const float& n);
        bool setRender(const bool& render);
};

#endif