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
    return this->_point();
}

Vector3 Line::getdirection() const {
    return this->_direction();
}

Vector3 Line::pointonline(float param) const {
    return this->getpoint() + this->getdirection() * param;
}
