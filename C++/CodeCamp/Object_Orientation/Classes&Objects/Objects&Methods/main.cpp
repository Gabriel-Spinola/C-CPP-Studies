#include <iostream>

using namespace std;

class Student 
{
    public:
        // Attributes
        string name;
        string major;

        double gpa;
        
        // Constructor | runs when the book is instantiated and can create the classes parematers
        Student(string aName, string aMajor, double aGpa) 
        {
            this->name = aName;
            this->major = aMajor;
            this->gpa = aGpa;
        }

        // Methods
        bool hasHonor() {
            return gpa >= 3.5;
        }
};

int main()
{
    Student student1("Jim", "Business", 2.4);
    Student student2("Pam", "Art", 3.6);

    cout << student1.hasHonor() << endl;
    cout << student2.hasHonor() << endl;
}