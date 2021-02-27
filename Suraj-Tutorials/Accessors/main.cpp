#include <iostream>
#include <string>

/**
 * * The inline command makes the compiler places a copy of the code of that function at each point where the function is called at compile time
 * * The double const keyword in a functions is used when a that function will not change anything. (just have permition to get)
*/

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
        const std::string toString() const {
            return (
                "Name: " + this->name + " | " +
                "Age: " + std::to_string(this->age) + " | " +
                "Gender: " + std::to_string(this->gender)
            );
        }
    
    public:
        // Constructors
        Person() {
            std::cout << "Class Constructed!" << std::endl;

            this->name = "none";
            this->age = -1;
            this->gender = false;
        }

        Person(std::string name, int age, bool female) {
            std::cout << "Class Constructed!" << std::endl;

            this->name = name;
            this->age = age;
            this->gender = female;
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

    std::cout << person.toString() << std::endl;
}