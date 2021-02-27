#include <iostream>
#include <vector>

int main() {
    std::vector<int> myIntVec;

    myIntVec.push_back(3);
    myIntVec.push_back(56);
    myIntVec.push_back(15);
    
    // Go through all vector values and puts it all in the i
    for(auto& i : myIntVec) {
        std::cout << i << std::endl; // 3  56  15
    }
}