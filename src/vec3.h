#ifndef VEC3_H
#define VEC3_H

#include <iostream>

class vec3 {
    public:
        double e[3];

        double& operator[](unsigned int i);
        double operator[](unsigned int i) const;

        double x() const;
        double y() const;
        double z() const;
        double r() const;
        double g() const;
        double b() const;

        double& x();
        double& y();
        double& z();
        double& r();
        double& g();
        double& b();

        vec3();
        vec3(double e0, double e1, double e2);
        vec3(const vec3& v);
        vec3(vec3&& v);
        vec3& operator=(const vec3& v);
        vec3& operator=(vec3&& v);
        ~vec3();

        vec3& operator-() const;
        vec3& operator+=(const vec3& v);
        vec3& operator-=(const vec3& v);
        vec3& operator*=(double t);
        vec3& operator/=(double t);
        bool operator==(const vec3& v);

        double length() const;
        double length_squared() const;
};

using point3 = vec3;

inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << "[" << v.x() << ", " << v.y() << ", " << v.z() << "]";
}

inline vec3 operator+(const vec3& v, const vec3& u) {
    return vec3(v.x() + u.x(), v.y() + u.y(), v.z() + u.z());
}

inline vec3 operator-(const vec3& v, const vec3& u) {
    return vec3(v.x() - u.x(), v.y() - u.y(), v.z() - u.z());
}

inline vec3 operator*(const vec3& v, const vec3& u) {
    return vec3(v.x() * u.x(), v.y() * u.y(), v.z() * u.z());
}

inline vec3 operator*(double t, const vec3& v) {
    return vec3(v.x() * t, v.y() * t, v.z() * t);
}

inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/ t) * v;
}

inline double dot(const vec3& v, const vec3& u) {
    return (v.x() * u.x() + v.y() * u.y() + v.z() * u.z());
}

inline vec3 cross(const vec3& v, const vec3& u) {
    return vec3(u.y() * v.z() - u.z() * v.y(),
                u.z() * v.x() - u.x() * v.z(),
                u.x() * v.y() - u.y() * v.x());
}

inline vec3 normalize(const vec3& v) {
    return vec3(v / v.length());
}

#endif