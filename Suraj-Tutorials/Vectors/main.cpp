#include <iostream>
#include <string>
#include <vector>

int main() {
    // Container class that store integers
    std::vector<int> myIntVec;
    std::vector<std::string> myStringVec;
    std::vector<float> myFloatVec;

    // Pushing values to the vector
    myIntVec.push_back(23);
    myIntVec.push_back(53);
    myIntVec.push_back(108);
    myIntVec.push_back(562);

    myStringVec.push_back("Hello,");
    myStringVec.push_back("World");

    myFloatVec.push_back(10.f);
    myFloatVec.push_back(25.f);

    // Removes the 2nd value of the integer vector; positions -> 0° 1st 2nd 3rd
    // The begin() function gets the first value. (and correspond as a iterator)
    myIntVec.erase(myIntVec.begin() + 2);

    // The end() function gets the last value
    myStringVec.erase(myStringVec.end());

    // Remove all values of the float vector
    myFloatVec.clear();

    // Also erase everything in the vector
    for(size_t i = 0; i < myFloatVec.size(); i++) {
        myFloatVec.erase(myFloatVec.begin() + i);
    }

    // Good Way to remove elements in a vector with more control
    // You can also use break.
    bool erased = false;
    bool somethingHappens = true;

    for(size_t i = 0; i < myFloatVec.size() && !erased; i++) {
        myFloatVec.erase(myFloatVec.begin() + i);

        if(somethingHappens)
            erased = true;
    }

    // Like this
    float floatToRemove = 2.f;

    for(size_t i = 0; i < myFloatVec.size(); i++) {
        if(myFloatVec[i] == floatToRemove) {
            myFloatVec.erase(myFloatVec.begin() + i);

            break;
        }
    }

    // Running a loop in the vector
    for(size_t i = 0; i < myIntVec.size(); i++) {
        std::cout << myIntVec[i] << ' ';
    }

    std::cout << std::endl;
    
    for(size_t i = 0; i < myStringVec.size(); i++) {
        std::cout << myStringVec[i] << ' ';
    }

    std::cout << std::endl;
    
    for(size_t i = 0; i < myFloatVec.size(); i++) {
        std::cout << myFloatVec[i] << ' ';
    }

    std::cout << std::endl;

    std::cout << "The size of the int vector is: " << myIntVec.size() << std::endl;
    std::cout << "The size of the string vector is: " << myStringVec.size() << std::endl;
    std::cout << "The size of the float vector is: " << myFloatVec.size() << std::endl;

    system("PAUSE");
}