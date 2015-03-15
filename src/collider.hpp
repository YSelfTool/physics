#pragma once
#include "vector3.hpp"

class Collider {
    private:
    
    protected:
    virtual Vector3 center() const = 0;
    virtual float maxradius() const = 0;
    
    virtual bool testcontains(const Vector3& point) const = 0;
    virtual bool testcontains(const Collider& collider) const = 0;
    virtual bool testintersects(const Collider& collider) const = 0;
    
    public:
    Collider();
    ~Collider();
    
    bool contains(const Vector3& point) const;
    bool contains(const Collider& collider) const;
    bool intersects(const Collider& collider) const;
    
    
};
