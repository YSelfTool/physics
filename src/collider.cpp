#include "collider.hpp"

Collider::Collider() {
    
}

Collider::~Collider() {
   
}

bool Collider::contains(const Vector3& point) const {
    if ((this->center() - point).normsquare() > 
        (this->maxradius() * this->maxradius())) {
        return false;
    }
    return this->testcontains(point);
}

bool Collider::contains(const Collider& collider) const {
    float tmr = this->maxradius();
    float cmr = collider.maxradius();
    if ((this->center() - collider.center()).normsquare() > 
        (tmr+cmr) * (tmr+cmr)) {
        return false;
    }
    return this->testcontains(collider);
}

bool Collider::intersects(const Collider& collider) const {
    float tmr = this->maxradius();
    float cmr = collider.maxradius();
    if ((this->center() - collider.center()).normsquare() > 
        (tmr+cmr) * (tmr+cmr)) {
        return false;
    }
    return this->testintersects(collider);
}

Vector3 Collider::distantpoint() const {
    return this->center() + 10 * this->maxradius() * Vector3::unitx();
}
