#include "line.hpp"

Line::Line() : _point(Vector3::zero()), _direction(Vector3::unitx()) {
    
}

Line::Line(const Vector3& point, const Vector3& direction) 
    : _point(point), _direction(direction) {
    
}

Line::Line(const Line& line) : _point(line.getpoint()), 
    _direction(line.getdirection()) {
    
}

Line::~Line() {
    
}

Vector3& Line::point() {
    return this->_point;
}

Vector3& Line::direction() {
    return this->_direction;
}

Vector3 Line::getpoint() const {
    return this->_point;
}

Vector3 Line::getdirection() const {
    return this->_direction;
}

Vector3 Line::point(const float param) const {
    return this->getpoint() + this->getdirection() * param;
}
    
float Line::closestparam(const Vector3& point) const {
    return (this->getpoint() - point) * this->getdirection() 
        / this->getdirection().normsquare();
}

Vector3 Line::closest(const Vector3& point) const {
    float param = this->closestparam(point);
    float paraminside = (0 < param) ? ((param < 1) ? param : 1) : 0;
    return this->point(paraminside);
}

float Line::distance(const Vector3& point) const {
    return (this->closest(point) - point).norm();
}
