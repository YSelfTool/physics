#pragma once

class Line {
    private:
    Vector3 _point;
    Vector3 _direction;
    
    public:
    Line();
    Line(const Vector3& point, const Vector3& direction);
    Line(const Line& line);
    
    ~Line();
    
    Vector3& point();
    Vector3& direction();
    
    Vector3 getpoint() const;
    Vector3 getdirection() const;
    
    Vector3 pointonline(float param) const;
    
};
