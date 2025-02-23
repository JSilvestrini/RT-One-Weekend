#include "Plane.h"

Plane::Plane() noexcept : Shape(), normal(vec3(0.0f, 1.0f, 0.0f)), point(0.0f, 0.0f, 0.0f) {}

Plane::Plane(vec3 normal, vec3 point) noexcept : Shape(), normal(normal), point(normal) {}

Plane::Plane(vec3 Ka, vec3 Kd, vec3 Ks, vec3 Km, float n, bool render, vec3 normal, vec3 point) noexcept :
    Shape(Ka, Kd, Ks, Km, n, render),
    normal(normal),
    point(point) {}

Plane::Plane(const Plane& plane) noexcept : Shape(plane), normal(plane.normal), point(plane.point) {}

Plane::Plane(Plane&& plane) noexcept : Shape(plane), normal(std::move(plane.normal)), point(std::move(plane.point)) {
    plane.normal = vec3();
    plane.point = vec3();
}

Plane Plane::operator=(const Plane& plane) noexcept {
    if (this == &plane) {
        return *this;
    }

    Shape::operator=(plane);

    normal = plane.normal;
    point = plane.point;

    return *this;
}

Plane Plane::operator=(Plane&& plane) noexcept {
    if (this == &plane) {
        return *this;
    }

    Shape::operator=(plane);

    normal = std::move(plane.normal);
    point = std::move(plane.point);

    plane.normal = vec3();
    plane.point = vec3();

    return *this;
}

Plane::~Plane() {}

// getters
vec3 Plane::getNormal(const vec3& point) const { return normal; }
vec3 Plane::getPoint() const noexcept { return point; }

// setters
bool Plane::setNormal(const vec3& normal) {
    this->normal = normal;
    return (this->normal == normal);
}

bool Plane::setPoint(const vec3& point) {
    this->point = point;
    return (this->point == point);
}

double Plane::intersect(const Ray& r) const {
    return 0.0;
}