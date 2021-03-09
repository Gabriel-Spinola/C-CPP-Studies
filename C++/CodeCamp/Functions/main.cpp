#include <iostream>
#include <cmath>

using namespace std;

void sayHi(string name, int age) {
    cout << "Hi " << name << ' ' << age;
}

double getPi() {
    return 3.14159;
}

int cube(int num) {
    int result = pow(num, 3);

    return result;
}

string Hallo() {
    return "HALlo";
}

int main()
{
    string name;
    int age;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Enter your age: ";
    cin >> age;

    sayHi(name, age);

    cout << "The Value of PI is " << getPi() << endl;
    cout << cube(3) << endl;

    cout << Hallo();
}