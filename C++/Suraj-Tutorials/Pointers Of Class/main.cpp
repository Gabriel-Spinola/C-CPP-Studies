#include <iostream>
#include <ctime>
#include <random>
#include <string>

class Person {
    private:
        std::string name;
        int age;

    public:
        const std::string toString() const {
            return (
                "Name: " + this->name + " | " +
                "Age: " + std::to_string(this->age)
            );
        }

    public:
        Person(std::string name, int age) {
            this->name = name;
            this->age = age;
        }
};

int main() {
    srand(time(NULL));

    Person me("Suraj", 28);
    Person fr("Daniel", 15);

    Person* seat = nullptr;

    if(rand() % 2 > 0) {
        seat = &me;
    }
    else {
        seat = &fr;
    }

    std::cout << seat->toString() << std::endl;

    // ==========================================================

    Person* newPerson = new Person("Dude", 50);

    std::cout << newPerson->toString() << std::endl;

    // Deleting pointer to counter memory leaks
    delete newPerson;
}