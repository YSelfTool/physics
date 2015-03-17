#include "cuboidcollider.hpp"
#include "spherecollider.cpp"
#include "notimplementedexception.hpp"

CuboidCollider::CuboidCollider() : _point(Vector3::zero()), 
    _direction1(Vector3::unitx()), _direction2(Vector3::unity()), 
    _direction3(Vector3::unitz()) {
    
}

CuboidCollider::CuboidCollider(const Vector3& center, 
    const float lengthx, const float lengthy, const float lengthz)
    : _point(center - 0.5 * lengthx * Vector3::unitx() 
        - 0.5 * lengthy * Vector3::unity() - 0.5 * lengthz * Vector3::unitz()),
    _direction1(Vector3::unitx() * lengthx), _direction2(Vector3::unity() * lengthy),
    _direction3(Vector3::unitz() * lengthz) {
    
}

CuboidCollider::CuboidCollider(const Vector3& center, const Vector3& direction1, 
    const Vector3& direction2, const Vector3& direction3) 
    : _point(center - 0.5 * direction1 - 0.5 * direction2 - 0.5 * direction3),
    _direction1(direction1), _direction2(direction2), _direction3(direction3) {
    
}

CuboidCollider::CuboidCollider(const Vector3& center, 
    const Vector3& direction1, const float length1,
    const Vector3& direction2, const float length2,
    const Vector3& direction3, const float length3)
    : CuboidCollider(center, direction1.normalize() * length1,
        direction2.normalize() * length2, direction3.normalize() * length3) {
    
}

CuboidCollider::~CuboidCollider() {
    
}

Vector3& CuboidCollider::point() {
    return this->_point;
}

Vector3& CuboidCollider::direction1() {
    return this->_direction1;
}

Vector3& CuboidCollider::direction2() {
    return this->_direction2;
}

Vector3& CuboidCollider::direction3() {
    return this->_direction3;
}

Vector3 CuboidCollider::getpoint() const {
    return this->_point;
}

Vector3 CuboidCollider::getdirection1() const {
    return this->_direction1;
}

Vector3 CuboidCollider::getdirection2() const {
    return this->_direction2;
}

Vector3 CuboidCollider::getdirection3() const {
    return this->_direction3;
}

ColliderType CuboidCollider::type() const {
    return CuboidColliderType;
}

Vector3 CuboidCollider::maxcenter() const {
    return this->getpoint() + 0.5 * this->getdirection1() + 0.5 * this->getdirection2() 
        + 0.5 * getdirection3();
}

float CuboidCollider::maxradius() const {
    float ls1 = this->getdirection1().normsquare(), 
        ls2 = this->getdirection2().normsquare(),
        ls3 = this->getdirection3().normsquare();
    return (ls1 > ls2) ? (ls1 > ls3 ? ls1 : ls3) : (ls2 > ls3 ? ls2 : ls3);
}

Vector3 CuboidCollider::corner111() const {
    return getpoint();
}

Vector3 CuboidCollider::corner112() const {
    return getpoint() + getdirection3();
}

Vector3 CuboidCollider::corner121() const {
    return getpoint() + getdirection2();
}

Vector3 CuboidCollider::corner122() const {
    return getpoint() + getdirection2() + getdirection3();
}

Vector3 CuboidCollider::corner211() const {
    return getpoint() + getdirection1();
}

Vector3 CuboidCollider::corner212() const {
    return getpoint() + getdirection1() + getdirection3();
}

Vector3 CuboidCollider::corner221() const {
    return getpoint() + getdirection1() + getdirection2();
}

Vector3 CuboidCollider::corner222() const {
    return getpoint() + getdirection1() + getdirection2() + getdirection3();
}

std::vector<Vector3> CuboidCollider::corners() const {
    return std::vector<Vector3> { corner111(), corner112(), corner121(), corner122(),
        corner211(), corner212(), corner221(), corner222() };
}

Line CuboidCollider::edge1() const {
    return Line(corner111(), getdirection1());
}

Line CuboidCollider::edge2() const {
    return Line(corner211(), getdirection2());
}

Line CuboidCollider::edge3() const {
    return Line(corner221(), -getdirection1());
}

Line CuboidCollider::edge4() const {
    return Line(corner121(), -getdirection2());
}

Line CuboidCollider::edge5() const {
    return Line(corner112(), getdirection1());
}

Line CuboidCollider::edge6() const {
    return Line(corner212(), getdirection2());
}

Line CuboidCollider::edge7() const {
    return Line(corner222(), -getdirection1());
}

Line CuboidCollider::edge8() const {
    return Line(corner122(), -getdirection2());
}

Line CuboidCollider::edge9() const {
    return Line(corner111(), getdirection3());
}

Line CuboidCollider::edge10() const {
    return Line(corner121(), getdirection3());
}

Line CuboidCollider::edge11() const {
    return Line(corner221(), getdirection3());
}

Line CuboidCollider::edge12() const {
    return Line(corner211(), getdirection3());
}

std::vector<Line> CuboidCollider::edges() const {
    return std::vector<Line> { edge1(), edge2(), edge3(), edge4(),
        edge5(), edge6(), edge7(), edge8(), edge9(), edge10(), edge11(), edge12() };
}

Rectangle CuboidCollider::face1() const {
    return Rectangle(corner111(), getdirection1(), getdirection2());
}

Rectangle CuboidCollider::face2() const {
    return Rectangle(corner111(), getdirection1(), getdirection3());
}

Rectangle CuboidCollider::face3() const {
    return Rectangle(corner111(), getdirection2(), getdirection3());
}

Rectangle CuboidCollider::face4() const {
    return Rectangle(corner222(), -getdirection1(), -getdirection2());
}

Rectangle CuboidCollider::face5() const {
    return Rectangle(corner222(), -getdirection1(), -getdirection3());
}

Rectangle CuboidCollider::face6() const {
    return Rectangle(corner222(), -getdirection2(), -getdirection3());
}

std::vector<Rectangle> CuboidCollider::faces() const {
    return std::vector<Rectangle> { face1(), face2(), face3(), face4(), 
        face5(), face6() };
}

bool CuboidCollider::testcontains(const Vector3& point) const {
    int intersectioncount = 0;
    Line line(this->distantpoint(), point - this->distantpoint());
    std::vector<Rectangle> faces = this->faces();
    for (std::vector<Rectangle>::iterator iter = faces.begin(); 
        iter != faces.end(); iter++) {
        if (iter->isintersectionpointinrectangle(line)) {
            intersectioncount++;
        }
    }
    return (intersectioncount % 2) == 1;
}


bool CuboidCollider::testcontains(const Collider& collider) const {
    switch (collider.type()) {
        case CuboidColliderType:
            return this->testcontainscuboid(static_cast<const CuboidCollider&>(collider));
        case SphereColliderType:
            return this->testcontainssphere(static_cast<const SphereCollider&>(collider));
        default:
            throw NotImplementedException("Unknown Collider Type");
    }
}

bool CuboidCollider::testcontainscuboid(const CuboidCollider& collider) const {
    std::vector<Vector3> corners = collider.corners();
    for (std::vector<Vector3>::iterator iter = corners.begin(); 
        iter != corners.end(); iter++) {
        if (!(this->testcontains(*iter))) {
            return false;
        }
    }
    return true;
}

bool CuboidCollider::testcontainssphere(const SphereCollider& collider) const {
    if (!(this->contains(collider.getcenter()))) {
        return false;
    }
    std::vector<Rectangle> faces = this->faces();
    for (std::vector<Rectangle>::iterator face = faces.begin();
        face != faces.end(); face++) {
        if (face->distance(collider.getcenter()) < collider.getradius()) {
            return false;
        }
    }
    return true;
}

bool CuboidCollider::testintersects(const Collider& collider) const {
    switch(collider.type()) {
        case CuboidColliderType:
            return this->testintersectscuboid(
                static_cast<const CuboidCollider&>(collider));
        case SphereColliderType:
            return collider.intersects(*this);
        default:
            throw NotImplementedException("Unknown Collider Type");
    }
}

bool CuboidCollider::testintersectscuboid(const CuboidCollider& collider) const {
    if (this->testcontainscuboid(collider)) {
        return true;
    }
    std::vector<Line> edges = collider.edges();
    std::vector<Rectangle> faces = this->faces();
    for (std::vector<Rectangle>::const_iterator face = faces.begin(); 
        face != faces.end(); face++) {
        for (std::vector<Line>::const_iterator edge = edges.begin();
            edge != edges.end(); edge++) {
            if (face->isintersectionpointinrectangle(*edge)) {
                return true;
            }
        }
    }
    return false;
}

std::vector<Vector3> CuboidCollider::points(const int order) const {
    std::vector<Vector3> arr;
    arr.reserve((order+1) * (order+1) * (order+1));
    Vector3 vec0 = this->getpoint();
    for (unsigned int c1 = 0; c1 <= order; c1++) {
        Vector3 vec1 = vec0 + (((float)c1)/order) * this->getdirection1();
        for (unsigned int c2 = 0; c2 <= order; c2++) {
            Vector3 vec2 = vec1 + (((float)c2)/order) * this->getdirection2();
            for (unsigned int c3 = 0; c3 <= order; c3++) {
                arr.push_back(vec2 + (((float)c3)/order) * this->getdirection3());
            }
        }
    }
    return arr;
}

std::ostream& operator<<(std::ostream& stream, const CuboidCollider& collider) {
    stream << "cuboid from " << collider.getpoint() << ", -> " << collider.getdirection1()
        << ", -> " << collider.getdirection2() << ", -> " << collider.getdirection3();
    return stream;
}
