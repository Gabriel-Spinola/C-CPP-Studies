#include <iostream>

using namespace std;

int main()
{
    /**
     * Pointers are memory addresses
     * 
     * every variable stored in memory have a addres (a unique id)
     * 
     * if you get the memory address of a variable like the age variable, and 
     * seach on your computer you'll find 19
    */

    // storing a values in memory
    int age = 19; 
    double gpa = 2.7;
    string name = "Mike";

    cout << &age << endl << endl; // prints the memory address (pointer) of the age variable

    cout << "Age Memory address: " << &age << endl;
    cout << "Gpa Memory address: " << &gpa << endl;
    cout << "Name Memory address: " << &name << endl;

    // ------------------------------------------------------
    // Pointers Variables
    int* pAge = &age; // store a pointer into a pointer variable
    double* pGpa = &gpa; // store a pointer into a pointer variable
    string* pName = &name;

    // Get the memory address
    cout << pAge << endl;  // returns a HexaDecimal

    // When you dirreference a point you get the actual value inside the memory address.
    cout << *pAge << endl; // returns a 19

    // Extra
    cout << *&gpa; // returns 2.7
}