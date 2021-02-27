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

int main() {
    MyClass instance;

    for(int i = 0; i < instance.getMyStrings().size(); i++) {
        std::cout << instance.getMyStrings()[i] << std::endl;
    }
}