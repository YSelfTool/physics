#include "spherecollider.hpp"
#include "notimplementedexception.hpp"
#include <vector>

SphereCollider::SphereCollider() : _center(Vector3::zero()), _radius(1.0f) {
    
}

SphereCollider::SphereCollider(const Vector3& center, const float radius) 
    : _center(center), _radius(radius) {
    
}

SphereCollider::~SphereCollider() {
    
}

Vector3& SphereCollider::center() {
    return this->_center;
}

float& SphereCollider::radius() {
    return this->_radius;
}

Vector3 SphereCollider::getcenter() const {
    return this->_center;
}

float SphereCollider::getradius() const {
    return this->_radius;
}

ColliderType SphereCollider::type() const {
    return SphereColliderType;
}

Vector3 SphereCollider::maxcenter() const {
    return this->getcenter();
}

bool SphereCollider::testcontains(const Vector3& point) const {
    return (this->getcenter() - point).normsquare() <= 
        this->getradius() * this->getradius();
}

bool SphereCollider::testcontains(const Collider& collider) const {
    switch (collider.type()) {
        case SphereColliderType:
            return this->testcontainssphere(static_cast<const SphereCollider&>(collider));
        case CuboidColliderType:
            return this->testcontainscuboid(static_cast<const CuboidCollider&>(collider));
        default:
            throw NotImplementedException("Unknown Collider Type");
    }
}

bool SphereCollider::testcontainssphere(const SphereCollider& collider) const {
    float radiusdiff = this->getradius() - collider.getradius();
    return (this->getcenter() - collider.getcenter()).normsquare() <= 
        radiusdiff * radiusdiff;
}

bool SphereCollider::testcontainscuboid(const CuboidCollider& collider) const {
    std::vector<Vector3> corners = collider.corners();
    for (std::vector<Vector3>::const_iterator corner = corners.begin();
        corner != corners.end(); corner++) {
        if (!(this->testcontains(*corner))) {
            return false;
        }
    }
    return true;
}

bool SphereCollider::testintersects(const Collider& collider) const {
    switch (collider.type()) {
        case SphereColliderType:
            return this->testintersectssphere(
                static_cast<const SphereCollider&>(collider));
        case CuboidColliderType:
            return this->testintersectscuboid(
                static_cast<const CuboidCollider&>(collider));
        default:
            throw NotImplementedException("Unknown Collider Type");
    }
}

bool SphereCollider::testintersectssphere(const SphereCollider& collider) const {
    float radiussum = this->getradius() + collider.getradius();
    return (this->getcenter() - collider.getcenter()).normsquare() <=
        radiussum * radiussum;
}

bool SphereCollider::testintersectscuboid(const CuboidCollider& collider) const {
    if (collider.contains(this->getcenter())) {
        return true;
    }
    std::vector<Rectangle> faces = collider.faces();
    for (std::vector<Rectangle>::iterator face = faces.begin();
        face != faces.end(); face++) {
        if (face->distance(this->getcenter()) <= this->getradius()) {
            return true;
        }
    }
    return false;
}
