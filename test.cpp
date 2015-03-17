#include "PhysicsConfig.hpp"
#include "vector3.hpp"
#include "cuboidcollider.hpp"
#include "spherecollider.hpp"
#include <vector>
#include <iostream>

int main() {
    CuboidCollider cuboid;
    SphereCollider sphere;
    
    std::cout << "Cuboid: " << &cuboid << std::endl;
    std::cout << "Sphere: " << &sphere << std::endl;
    std::cout << "Cuboid: " << cuboid << std::endl;
    std::cout << "Sphere: " << sphere << std::endl;
    
    std::cout << "Intersects: " << cuboid.intersects(sphere) << std::endl;
    std::cout << "Sphere contains Cuboid: " << sphere.contains(cuboid) << std::endl;
    std::cout << "Cuboid contains Sphere: " << cuboid.contains(sphere) << std::endl;
    std::cout << "Sphere contains Sphere: " << sphere.contains(sphere) << std::endl;
    std::cout << "Cuboid contains Cuboid: " << cuboid.contains(cuboid) << std::endl;
    
}
