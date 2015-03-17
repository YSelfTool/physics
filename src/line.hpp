#pragma once
#include "vector3.hpp"

class Line {
    private:
    Vector3 _point;
    Vector3 _direction;
    
    float closestparam(const Vector3& point) const;
    
    public:
    Line();
    Line(const Vector3& point, const Vector3& direction);
    Line(const Line& line);
    
    ~Line();
    
    Vector3& point();
    Vector3& direction();
    
    Vector3 getpoint() const;
    Vector3 getdirection() const;
    
    Vector3 point(const float param) const;
    
    Vector3 closest(const Vector3& point) const;
    float distance(const Vector3& point) const;
    
};
