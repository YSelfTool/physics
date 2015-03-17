#pragma once
#include "collider.hpp"
#include "cuboidcollider.hpp"
#include "vector3.hpp"

class SphereCollider : public Collider {
    private:
    Vector3 _center;
    float _radius;
    
    bool testcontainssphere(const SphereCollider& collider) const;
    bool testcontainscuboid(const CuboidCollider& collider) const;
    
    bool testintersectssphere(const SphereCollider& collider) const;
    bool testintersectscuboid(const CuboidCollider& collider) const;
    
    protected:
    virtual Vector3 maxcenter() const;
    virtual float maxradius() const;
    
    virtual bool testcontains(const Vector3& point) const;
    virtual bool testcontains(const Collider& collider) const;
    virtual bool testintersects(const Collider& collider) const;
    
    public:
    SphereCollider();
    SphereCollider(const Vector3& center, const float radius);
    
    ~SphereCollider();
    
    Vector3& center();
    float& radius();
    
    Vector3 getcenter() const;
    float getradius() const;
    
    virtual ColliderType type() const;
}
