#include <iostream>
#include <string>

class Person {
    private:
        // Atributes
        std::string name;
        bool female;
        int age;

        // Methods

    public:
        // Atributes
        

        // Methods
    
    public:
        // Constructor
        Person() {
            std::cout << "Class Constructed!" << std::endl;

            this->name = "none";
            this->age = -1;
            this->female = false;
        }

        Person(std::string name, int age, bool female) {
            std::cout << "Class Constructed!" << std::endl;

            this->name = name;
            this->age = age;
            this->female = female;
        }

        // Destructor
        ~Person() {
            std::cout << "class Destroyed" << std::endl;
        }   

        // Accessors
        inline const std::string& getName() const { return this->name; }

        // Modifiers
};

int main() {
    Person person;

    std::cout << person.getName() << std::endl;
}