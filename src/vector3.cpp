#include "vector3.hpp"
#include <cmath>

Vector3::Vector3() : _x(0.0f), _y(0.0f), _z(0.0f) {
    
}

Vector3::Vector3(const float x, const float y, const float z) : _x(x), _y(y), _z(z) {
    
}

Vector3::Vector3(const Vector3& vector) : 
    _x(vector.getx()), _y(vector.gety()), _z(vector.getz()) {
    
}

Vector3::~Vector3() {

}

float& Vector3::x() {
    return _x;
}

float& Vector3::y() {
    return _y;
}

float& Vector3::z() {
    return _z;
}

float Vector3::getx() const {
    return _x;
}

float Vector3::gety() const {
    return _y;
}

float Vector3::getz() const {
    return _z;
}

Vector3 Vector3::operator+() const {
    return Vector3(this->getx(), this->gety(), this->getz());
}

Vector3 Vector3::operator-() const {
    return Vector3(-this->getx(), -this->gety(), -this->getz());
}

Vector3 Vector3::operator+(const Vector3& vector) const {
    return Vector3(this->getx() + vector.getx(),
        this->gety() + vector.gety(),
        this->getz() + vector.getz());
}

Vector3 Vector3::operator-(const Vector3& vector) const {
    return Vector3(this->getx() - vector.getx(),
        this->gety() - vector.gety(),
        this->getz() - vector.getz());
}

Vector3 Vector3::operator*(const float scalar) const {
    return Vector3(this->getx() * scalar,
        this->gety() * scalar,
        this->getz() * scalar);
}

Vector3 Vector3::operator/(const float scalar) const {
    return Vector3(this->getx() / scalar,
        this->gety() / scalar,
        this->getz() / scalar);
}

Vector3& Vector3::operator=(const Vector3& vector) {
    this->x() = vector.getx();
    this->y() = vector.gety();
    this->z() = vector.getz();
    return *this;
}

Vector3& Vector3::operator+=(const Vector3& vector) {
    this->x() = this->getx() + vector.getx();
    this->y() = this->gety() + vector.gety();
    this->z() = this->getz() + vector.getz();
    return *this;
}

Vector3& Vector3::operator-=(const Vector3& vector) {
    this->x() = this->getx() - vector.getx();
    this->y() = this->gety() - vector.gety();
    this->z() = this->getz() - vector.getz();
    return *this;
}

Vector3& Vector3::operator*=(const float scalar) {
    this->x() = this->getx() * scalar;
    this->y() = this->gety() * scalar;
    this->z() = this->getz() * scalar;
    return *this;
}

Vector3& Vector3::operator/=(const float scalar) {
    this->x() = this->getx() / scalar;
    this->y() = this->gety() / scalar;
    this->z() = this->getz() / scalar;
    return *this;
}

float Vector3::dot(const Vector3& vector) const {
    return this->getx() * vector.getx() + this->gety() * vector.gety() + 
        this->getz() * vector.getz();
}

float Vector3::operator*(const Vector3& vector) const {
    return this->dot(vector);
}

Vector3 Vector3::cross(const Vector3& vector) const {
    return Vector3(this->gety() * vector.getz() - this->getz() * vector.gety(),
        this->getz() * vector.getx() - this->getz() * vector.getx(),
        this->getx() * vector.gety() - this->gety() * vector.getx());
}

float Vector3::normsquare() const {
    return this->dot(*this);
}

float Vector3::norm() const {
    return std::sqrt(this->normsquare());
}

Vector3 Vector3::normalize() const {
    return (*this) / this->norm();
}

bool Vector3::operator==(const Vector3& vector) const {
    return (this->getx() == vector.getx()) && 
        (this->gety() == vector.gety()) && (this->getz() == vector.getz());
}

bool Vector3::operator!=(const Vector3& vector) const {
    return (this->getx() != vector.getx()) || 
        (this->gety() != vector.gety()) || (this->getz() != vector.getz());
}

bool Vector3::operator<(const Vector3& vector) const {
    return this->normsquare() < vector.normsquare();
}

bool Vector3::operator>(const Vector3& vector) const {
    return this->normsquare() > vector.normsquare();
}

bool Vector3::operator<=(const Vector3& vector) const {
    return this->normsquare() <= vector.normsquare();
}

bool Vector3::operator>=(const Vector3& vector) const {
    return this->normsquare() >= vector.normsquare();
}

bool Vector3::iszero() const {
    return (this->getx() == 0.0f) && (this->gety() == 0.0f) && (this->getz() == 0.0f);
}

bool Vector3::isparallel(const Vector3& vector) const {
    return std::abs((*this).normalize() * vector.normalize()) == 1;
}

bool Vector3::isorthogonal(const Vector3& vector) const {
    return ((*this) * vector) == 0;
}

Vector3 Vector3::zero() {
    return Vector3(0.0f, 0.0f, 0.0f);
}

Vector3 Vector3::unitx() {
    return Vector3(1.0f, 0.0f, 0.0f);
}

Vector3 Vector3::unity() {
    return Vector3(0.0f, 1.0f, 0.0f);
}

Vector3 Vector3::unitz() {
    return Vector3(0.0f, 0.0f, 1.0f);
}

Vector3 Vector3::infinity() {
    return Vector3(INFINITY, INFINITY, INFINITY);
}

Vector3 operator*(const float scalar, const Vector3& vector) {
    return vector * scalar;
}

std::ostream& operator<<(std::ostream& stream, const Vector3& vector) {
    stream << "(" << vector.getx() << ", " << vector.gety() << ", " << vector.getz() << ")";
    return stream;
}
