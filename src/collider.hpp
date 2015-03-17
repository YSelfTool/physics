#pragma once
#include "vector3.hpp"
#include "collidertype.hpp"
#include <vector>

class Collider {
    private:
    
    protected:
    virtual Vector3 maxcenter() const = 0;
    virtual float maxradius() const = 0;
    
    virtual bool testcontains(const Vector3& point) const = 0;
    virtual bool testcontains(const Collider& collider) const = 0;
    virtual bool testintersects(const Collider& collider) const = 0;
    
    Vector3 distantpoint() const;
    
    public:
    Collider();
    virtual ~Collider();
    
    virtual ColliderType type() const = 0;
    
    bool contains(const Vector3& point) const;
    bool contains(const Collider& collider) const;
    bool intersects(const Collider& collider) const;
    
    virtual std::vector<Vector3> points(const int order) const = 0;
    
};
