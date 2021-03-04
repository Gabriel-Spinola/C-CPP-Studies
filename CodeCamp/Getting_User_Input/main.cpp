#include <iostream>

using namespace std;

int main()
{
    string name;
    int age;

    cout << "Enter your name: " << endl;
    getline(cin, name); // get a string from the user

    cout << "Enter your age: " << endl;
    cin >> age;
    
    cout << "Hello " << name << " " << endl;
    cout << "Your age is " << age;
}
