#pragma once
#include "collider.hpp"
#include "vector3.hpp"
#include "rectangle.hpp"
#include "line.hpp"
#include <vector>

class SphereCollider;

class CuboidCollider : public Collider {
    private:
    Vector3 _point;
    Vector3 _direction1, _direction2, _direction3;
    
    bool testcontainscuboid(const CuboidCollider& collider) const;
    bool testcontainssphere(const SphereCollider& collider) const;
    
    bool testintersectscuboid(const CuboidCollider& collider) const;
    
    protected:
    virtual Vector3 maxcenter() const;
    virtual float maxradius() const;
    
    virtual bool testcontains(const Vector3& point) const;
    virtual bool testcontains(const Collider& collider) const;
    virtual bool testintersects(const Collider& collider) const;
    
    public:
    CuboidCollider();
    CuboidCollider(const Vector3& center, 
        const float lengthx, const float lengthy, const float lengthz);
    CuboidCollider(const Vector3& center, 
        const Vector3& direction1, const Vector3& direction2, const Vector3& direction3);
    CuboidCollider(const Vector3& center, 
        const Vector3& direction1, const float length1,
        const Vector3& direction2, const float length2, 
        const Vector3& direction3, const float length3);
    
    ~CuboidCollider();
    
    Vector3& point();
    Vector3& direction1();
    Vector3& direction2();
    Vector3& direction3();
    
    Vector3 getpoint() const;
    Vector3 getdirection1() const;
    Vector3 getdirection2() const;
    Vector3 getdirection3() const;
    
    virtual ColliderType type() const;
    
    virtual std::vector<Vector3> points(const int order) const;
    
    Vector3 corner111() const;
    Vector3 corner112() const;
    Vector3 corner121() const;
    Vector3 corner122() const;
    Vector3 corner211() const;
    Vector3 corner212() const;
    Vector3 corner221() const;
    Vector3 corner222() const;
    
    std::vector<Vector3> corners() const;
    
    Line edge1() const;
    Line edge2() const;
    Line edge3() const;
    Line edge4() const;
    Line edge5() const;
    Line edge6() const;
    Line edge7() const;
    Line edge8() const;
    Line edge9() const;
    Line edge10() const;
    Line edge11() const;
    Line edge12() const;
    
    std::vector<Line> edges() const;
    
    Rectangle face1() const;
    Rectangle face2() const;
    Rectangle face3() const;
    Rectangle face4() const;
    Rectangle face5() const;
    Rectangle face6() const;
    
    std::vector<Rectangle> faces() const;
    
};

std::ostream& operator<<(std::ostream& stream, const CuboidCollider& collider);
