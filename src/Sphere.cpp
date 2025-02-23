#include "Sphere.h"

Sphere::Sphere() noexcept : Shape(), center(vec3()), radius(vec3()) {}

Sphere::Sphere(vec3 center, vec3 radius) noexcept : Shape(), center(center), radius(radius) {}

Sphere::Sphere(vec3 Ka, vec3 Kd, vec3 Ks, vec3 Km, float n, bool render, vec3 center, vec3 radius) noexcept : 
    Shape(Ka, Kd, Ks, Km, n, render),
    center(center),
    radius(radius) {}

Sphere::Sphere(const Sphere& sphere) noexcept : Shape(sphere), center(sphere.center), radius(sphere.radius) {}

Sphere::Sphere(Sphere&& sphere) noexcept : Shape(sphere), center(std::move(sphere.center)), radius(std::move(sphere.radius)) {
    sphere.center = vec3();
    sphere.radius = vec3();
}

Sphere& Sphere::operator=(const Sphere& sphere) noexcept {
    if (this == &sphere) {
        return *this;
    }

    Shape::operator=(sphere);

    center = sphere.center;
    radius = sphere.radius;

    return *this;
}

Sphere& Sphere::operator=(Sphere&& sphere) noexcept {
    if (this == &sphere) {
        return *this;
    }

    Shape::operator=(sphere);

    center = std::move(sphere.center);
    radius = std::move(sphere.radius);

    sphere.center = vec3();
    sphere.radius = vec3();

    return *this;
}

Sphere::~Sphere() {}

// getters
vec3 Sphere::getCenter() const noexcept { return center; }
vec3 Sphere::getRadius() const noexcept { return radius; }

vec3 Sphere::getNormal(const vec3& point) const {
    return normalize((point - center));
}

double Sphere::intersect(const Ray& r) const {
    vec3 oc = center - r.origin();
    double a = r.direction().length_squared();
    double h = dot(r.direction(), oc);
    double c = oc.length_squared() - (radius.x() * radius.x());
    double d = (h * h) - (a * c);

    return (h - sqrt(d)) / (a);
}

// setters
bool Sphere::setCenter(const vec3& center) {
    this->center = center;
    return (this->center == center);
}

bool Sphere::setRadius(const vec3& radius) {
    this->radius = radius;
    return (this->radius == radius);
}