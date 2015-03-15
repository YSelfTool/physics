#pragma once

class Vector3 {
    private:
    float _x = 0.0, _y = 0.0, _z = 0.0;
    
    public:
    Vector3();
    Vector3(const float x, const float y, const float z);
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
    Vector3 normalize() const;
    
    bool operator==(const Vector3& vector) const;
    bool operator!=(const Vector3& vector) const;
    bool operator<(const Vector3& vector) const;
    bool operator>(const Vector3& vector) const;
    bool operator<=(const Vector3& vector) const;
    bool operator>=(const Vector3& vector) const;
    
    bool iszero() const;
    bool isparallel(const Vector3& vector) const;
    bool isorthogonal(const Vector3& vector) const;
    
    static Vector3 zero();
    static Vector3 unitx();
    static Vector3 unity();
    static Vector3 unitz();
    static Vector3 infinity();
};
