#include "vec3.h"

double& vec3::operator[](unsigned int i) { return e[i]; }
double vec3::operator[](unsigned int i) const { return e[i]; }
double vec3::x() const { return e[0]; }
double vec3::y() const { return e[1]; }
double vec3::z() const { return e[2]; }
double vec3::r() const { return e[0]; }
double vec3::g() const { return e[1]; }
double vec3::b() const { return e[2]; }
double& vec3::x() { return e[0]; }
double& vec3::y() { return e[1]; }
double& vec3::z() { return e[2]; }
double& vec3::r() { return e[0]; }
double& vec3::g() { return e[1]; }
double& vec3::b() { return e[2]; }

vec3::vec3() : e{0.0, 0.0, 0.0} {}
vec3::vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

vec3::vec3(const vec3& v) {
    e[0] = v.e[0];
    e[1] = v.e[1];
    e[2] = v.e[2];
}

vec3::vec3(vec3&& v) {
    e[0] = std::move(v.e[0]);
    e[1] = std::move(v.e[1]);
    e[2] = std::move(v.e[2]);
}

vec3& vec3::operator=(const vec3& v) {
    if (this == &v) {
        return *this;
    }

    e[0] = v.e[0];
    e[1] = v.e[1];
    e[2] = v.e[2];

    return *this;
}

vec3& vec3::operator=(vec3&& v) {
    if (this == &v) {
        return *this;
    }

    e[0] = std::move(v.e[0]);
    e[1] = std::move(v.e[1]);
    e[2] = std::move(v.e[2]);

    return *this;
}

vec3::~vec3() {}

vec3& vec3::operator+=(const vec3& v) {
    e[0] += v.x();
    e[1] += v.y();
    e[2] += v.z();
    return *this;
}

vec3& vec3::operator-=(const vec3& v) {
    e[0] -= v.x();
    e[1] -= v.y();
    e[2] -= v.z();
    return *this;
}

vec3& vec3::operator*=(double t) {
    e[0] *= t;
    e[1] *= t;
    e[2] *= t;
    return *this;
}

bool vec3::operator==(const vec3& v) {
    return (e[0] == v.e[0] &&
            e[1] == v.e[1] &&
            e[2] == v.e[2]);
}

vec3& vec3::operator/=(double t) {
    return (*this *= (1/t));
}

double vec3::length() const {
    return std::sqrt(length_squared());
}

double vec3::length_squared() const {
    return (e[0] * e[0] + e[1] * e[1] + e[2] * e[2]);
}