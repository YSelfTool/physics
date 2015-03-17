#include "spherecollider.hpp"
#include "cuboidcollider.hpp"
#include "notimplementedexception.hpp"
#include <vector>
#include <cmath>

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

float SphereCollider::maxradius() const {
    return this->getradius();
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

std::vector<Vector3> SphereCollider::points(const unsigned int order) const {
    std::vector<Vector3> arr;
    arr.reserve(4 * (order+1) * order * order);
    Vector3 c = this->getcenter();
    for (unsigned int c1 = 0; c1 < order; c1++) {
        float r = this->getradius() * std::cbrt(((float)c1)/order);
        for (unsigned int c2 = -order; c2 < order; c2++) {
            
            for (unsigned int c3 = -order; c3 <= order; c3++) {
                if (c2*c2 + c3*c3 < order*order) {
                    float x2 = ((float)c2) / order,
                        x3 = ((float)c3) / order;
                    arr.push_back(Vector3(2 * r * x2 * std::sqrt(1 - x2*x2 - x3*x3),
                        2 * r * x3 * std::sqrt(1 - x2*x2 - x3*x3),
                        r * (1 - 2 * (x1*x1 + x2*x2))));
                }
                
            }
        }
    }
    return arr;
}

std::ostream& operator<<(std::ostream& stream, const SphereCollider& collider) {
    stream << "sphere around " << collider.getcenter() << ", r=" << collider.getradius();
    return stream;
}
