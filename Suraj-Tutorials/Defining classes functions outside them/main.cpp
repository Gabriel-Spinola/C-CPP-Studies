#include <iostream>
#include <string>
#include <vector>

class MyClass {
    private:
        // Atributes
        std::vector<std::string> myStrings;

    public:
        // Methods
        void add(const std::string str);
        
        const std::string toString() const;

    public:
        MyClass();

        // Accessors
        inline const std::vector<std::string>& getMyStrings() const;
};

MyClass::MyClass() {
    this->myStrings.push_back("Hi");
}

inline const std::vector<std::string>& MyClass::getMyStrings() const { return this->myStrings; }

void MyClass::add(const std::string str) {
    this->myStrings.push_back(str);
}

const std::string MyClass::toString() const {
    std::string finalString;

    for(int i = 0; i < this->myStrings.size(); i++) {
        finalString += std::to_string(i) + ": " + this->myStrings[i] + "\n";
    }

    return finalString;
}

int main() {
    MyClass instance;
    
    std::cout << instance.toString() << std::endl;
    
    instance.add("Cool");

    std::cout << instance.toString() << std::endl;

    /*
    for(int i = 0; i < instance.getMyStrings().size(); i++) {
        // * Both makes the same thing
        std::cout << instance.getMyStrings()[i] << std::endl;
        std::cout << instance.getMyStrings().at(i) << std::endl;
    }
    */
}