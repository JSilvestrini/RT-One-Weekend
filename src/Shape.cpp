#include "Shape.h"

Shape::Shape() noexcept : 
    Ka(vec3()),
    Kd(vec3()),
    Ks(vec3()),
    Km(vec3()),
    n(0),
    render(true) {}

Shape::Shape(vec3 Ka, vec3 Kd, vec3 Ks, vec3 Km, float n, bool render) noexcept : 
    Ka(Ka),
    Kd(Kd),
    Ks(Ks),
    Km(Km),
    n(n),
    render(render) {}

Shape::Shape(const Shape& shape) noexcept :
    Ka(shape.Ka),
    Kd(shape.Kd),
    Ks(shape.Ks),
    Km(shape.Km),
    n(shape.n),
    render(shape.render) {}

Shape::Shape(Shape&& shape) noexcept :
    Ka(std::move(shape.Ka)),
    Kd(std::move(shape.Kd)),
    Ks(std::move(shape.Ks)),
    Km(std::move(shape.Km)),
    n(std::move(shape.n)),
    render(std::move(shape.render)) {
        shape.Ka = vec3();
        shape.Kd = vec3();
        shape.Ks = vec3();
        shape.Km = vec3();
        shape.n = -1;
        shape.render = false;
    }

Shape& Shape::operator=(const Shape& shape) noexcept {
    if (this == &shape) {
        return *this;
    }

    Ka = shape.Ka;
    Kd = shape.Kd;
    Ks = shape.Ks;
    Km = shape.Km;
    n = shape.n;
    render = shape.render;

    return *this;
}

Shape& Shape::operator=(Shape&& shape) noexcept {
    if (this == &shape) {
        return *this;
    }

    Ka = std::move(shape.Ka);
    Kd = std::move(shape.Kd);
    Ks = std::move(shape.Ks);
    Km = std::move(shape.Km);
    n = std::move(shape.n);
    render = std::move(shape.render);

    shape.Ka = vec3();
    shape.Kd = vec3();
    shape.Ks = vec3();
    shape.Km = vec3();
    shape.n = -1;
    shape.render = false;

    return *this;
}

Shape::~Shape() {}

vec3 Shape::getKa() const noexcept { return Ka; }
vec3 Shape::getKd() const noexcept { return Kd; }
vec3 Shape::getKs() const noexcept { return Ks; }
vec3 Shape::getKm() const noexcept { return Km; }
float Shape::getN() const noexcept { return n; }
bool Shape::getRender() const noexcept { return render; }
vec3 Shape::getNormal(const vec3& point) const { return vec3(); }
double Shape::intersect(const Ray& r) const { return -1.0; }
bool Shape::setKa(const vec3& ka) {
    Ka = ka;
    return (Ka == ka);
}

bool Shape::setKd(const vec3& kd) {
    Kd = kd;
    return (Kd == kd);
}

bool Shape::setKs(const vec3& ks) {
    Ks = ks;
    return (Ks == ks);
}

bool Shape::setKm(const vec3& km) {
    Km = km;
    return (Km == km);
}

bool Shape::setN(const float& n) {
    this->n = n;
    return (this->n == n);
}

bool Shape::setRender(const bool& render) {
    this->render = render;
    return (this->render == render);
}