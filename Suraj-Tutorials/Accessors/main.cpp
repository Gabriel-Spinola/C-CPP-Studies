#include <iostream>
#include <string>

class Person {
    private:
        // Atributes
        std::string name;
        int age;
        bool gender;

        // Methods

    public:
        // Atributes
        

        // Methods
    
    public:
        // Constructors
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
        inline const int& getAge() const { return this->age; }
        inline const bool& getGender() const { return this->gender; }

        // Modifiers
        inline void setName(const std::string& name) { this->name = name; }
        inline void setAge(const int& age) { this->age = age; }
        inline void setGender(const bool& gender) { this->gender = gender; }
};

int main() {
    Person person;

    std::cout << person.getName() << std::endl;

    person.setName("Gabriel");
    
    std::cout << person.getName() << std::endl;
}