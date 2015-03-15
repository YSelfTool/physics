#pragma once

class Vector3 {
    private:
    float _x = 0.0, _y = 0.0, _z = 0.0;
    
    public:
    Vector3();
    Vector3(float x, float y, float z);
    Vector3(const Vector3& vector);
    
    ~Vector3();
    
    float& x();
    float& y();
    float& z();
    
    float getx() const;
    float gety() const;
    float getz() const;
    
    Vector3 operator+() const;
    Vector3 operator-() const;
     
    Vector3 operator+(const Vector3& vector) const;
    Vector3 operator-(const Vector3& vector) const;
    Vector3 operator*(const float scalar) const;
    Vector3 operator/(const float scalar) const;
    
    Vector3& operator=(const Vector3& vector);
    
    Vector3& operator+=(const Vector3& vector);
    Vector3& operator-=(const Vector3& vector);
    Vector3& operator*=(const float scalar);
    Vector3& operator/=(const float scalar);
    
    float dot(const Vector3& vector) const;
    float operator*(const Vector3& vector) const;
    Vector3 cross(const Vector3& vector) const;
    
    float norm() const;
    float normsquare() const;
    
    bool operator==(const Vector3& vector) const;
    bool operator!=(const Vector3& vector) const;
    bool operator<(const Vector3& vector) const;
    bool operator>(const Vector3& vector) const;
    bool operator<=(const Vector3& vector) const;
    bool operator>=(const Vector3& vector) const;
};
