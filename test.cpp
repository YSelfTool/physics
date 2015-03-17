#include "PhysicsConfig.hpp"
#include "vector3.hpp"
#include "cuboidcollider.hpp"
#include <vector>
#include <iostream>

int main() {
    CuboidCollider coll;
    std::vector<Vector3> corners = coll.corners();
    for (std::vector<Vector3>::iterator iter = corners.begin();
        iter != corners.end(); iter++) {
        std::cout << *iter << std::endl;
    }
    
}
