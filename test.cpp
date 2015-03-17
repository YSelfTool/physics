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
    
//    std::vector<Vector3> cuboidpoints = cuboid.points(5);
    std::vector<Vector3> spherepoints = sphere.points(5);
    
//    std::cout << "Cuboid Points: " << cuboidpoints.size() << std::endl;
//    for (std::vector<Vector3>::iterator iter = cuboidpoints.begin();
//        iter != cuboidpoints.end(); iter++) {
//        std::cout << *iter << std::endl;
//    }
    std::cout << "Sphere Points: " << spherepoints.size() << std::endl;
    for (std::vector<Vector3>::iterator iter = spherepoints.begin();
        iter != spherepoints.end(); iter++) {
        std::cout << *iter << std::endl;
    }
}
