#include "rectangle.hpp"
#include <cmath>

Rectangle::Rectangle() : _point(Vector3::zero()), _direction1(Vector3::unitx()),
    _direction2(Vector3::unity()) {
    
}

Rectangle::Rectangle(const Vector3& point, const Vector3& direction1, 
    const Vector3& direction2) 
    : _point(point), _direction1(direction1), _direction2(direction2) {
    
}

Rectangle::Rectangle(const Vector3& point, const Vector3& direction1, const float length1,
    const Vector3& direction2, const float length2) 
    : _point(point), _direction1(direction1 / length1), 
    _direction2(direction2 / length2) {
    
}

Rectangle::Rectangle(const Rectangle& rectangle) : _point(rectangle.getpoint()),
    _direction1(rectangle.getdirection1()), _direction2(rectangle.getdirection2()) {
    
}

Rectangle::~Rectangle() {
    
}

Vector3& Rectangle::point() {
    return this->_point;
}

Vector3& Rectangle::direction1() {
    return this->_direction1;
}

Vector3& Rectangle::direction2() {
    return this->_direction2;
}

Vector3 Rectangle::getpoint() const {
    return this->_point;
}

Vector3 Rectangle::getdirection1() const {
    return this->_direction1;
}

Vector3 Rectangle::getdirection2() const {
    return this->_direction2;
}

Vector3 Rectangle::point(float param1, float param2) const {
    return this->getpoint() + this->getdirection1() * param1
        + this->getdirection2() * param2;
}

Vector3 Rectangle::normal() const {
    return this->getdirection1().cross(this->getdirection2());
}

std::pair<float, float> Rectangle::closestparams(const Vector3& point) const {
    Vector3 a = this->getpoint(), b = this->getdirection1(), c = this->getdirection2();
    Vector3 p = point;
    float u = (a*b - b*p + b.normsquare()/(b*c)*(p*c - a*c)) / 
        ((b.normsquare()*c.normsquare())/(b*c) - b*c);
    float t = (p*c - u*c.normsquare() - a*c) / (b*c);
    return std::pair<float, float>(t, u);
}

Vector3 Rectangle::closest(const Vector3& point) const {
    std::pair<float, float> params = this->closestparams(point);
    std::pair<float, float> paramsinside = std::pair<float, float>(
        (params.first > 0) ? ((params.first < 1) ? params.first : 1) : 0,
        (params.second > 0) ? ((params.second < 1) ? params.second : 1) : 0);
    return this->point(paramsinside.first, paramsinside.second);
}

float Rectangle::distance(const Vector3& point) const {
    return (point - this->closest(point)).norm();
}

Vector3 Rectangle::getintersectionpoint(const Line& line) const {
    const Vector3 n = this->normal();
    if (n.isorthogonal(line.getdirection())) {
        return Vector3::infinity();
    }
    return line.getpoint() + line.getdirection() * 
        (((this->getpoint() - line.getpoint()) * n))
        / (line.getdirection() * n);
}

std::pair<float, float> Rectangle::getintersectionpointparams(const Line& line) const {
    Vector3 difference = this->getintersectionpoint(line) - this->getpoint();
    return std::pair<float, float>(difference * this->getdirection1(), 
        difference * this->getdirection2());
}

bool Rectangle::isintersectionpointinrectangle(const Line& line) const {
    std::pair<float, float> params = this->getintersectionpointparams(line);
    return (0 <= params.first && params.first <= 1 && 
        0 <= params.second && params.second <= 1);
}
