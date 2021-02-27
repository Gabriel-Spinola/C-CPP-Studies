#include <iostream>

class Person {
    public:
        int age1 = 10;

    private:
        std::string name = "hello";
        int age;
        bool female;

    public:
        Person() {
            std::cout << "Constructor yoo!" << std::endl;

            this->name = "none";
            this->age1 = -1;
            this->female = false;
        }
    
        Person(std::string name, int age, bool female) {
            std::cout << "Constructor yoo!" << std::endl;

            this->name = name;
            this->age1 = age;
            this->female = female;
        }

        ~Person() {
            std::cout << "Destructor!" << std::endl;
        }
};

int main() {
    Person();
    Person person1;
    Person person2("Gabi", 25, true);
    Person* person3 = new Person();

    std::cout << std::endl;

    std::cout << person1.age1 << std::endl;
    std::cout << person2.age1 << std::endl;
    std::cout << person3->age1 << std::endl;

    std::cout << std::endl;
}
