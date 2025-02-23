#include "ray.h"

Ray::Ray() {}
Ray::Ray(const point3& origin, const vec3& direction) : o(origin), dir(direction) {}
Ray::~Ray() {}
const point3& Ray::origin() const { return o; }
const vec3& Ray::direction() const { return dir; }
point3 Ray::at(double t) const { return o + t * dir; }