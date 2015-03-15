#pragma once
#include "vector3.hpp"
#include "line.hpp"
#include <utility>

class Rectangle {
    private:
    Vector3 _point;
    Vector3 _direction1, _direction2;
    
    std::pair<float, float> getintersectionpointparams(const Line& line) const;
    
    public:
    Rectangle();
    Rectangle(const Vector3& point, const Vector3& direction1, const Vector3& direction2);
    Rectangle(const Vector3& point, const Vector3& direction1, const float length1, 
        const Vector3& direction2, const float length2);
    Rectangle(const Rectangle& rectangle);
    
    ~Rectangle();
    
    Vector3& point();
    Vector3& direction1();
    Vector3& direction2();
    
    Vector3 getpoint() const;
    Vector3 getdirection1() const;
    Vector3 getdirection2() const;
    
    Vector3 normal() const;
    
    Vector3 getintersectionpoint(const Line& line) const;
    bool isintersectionpointinrectangle(const Line& line) const;
    
};
