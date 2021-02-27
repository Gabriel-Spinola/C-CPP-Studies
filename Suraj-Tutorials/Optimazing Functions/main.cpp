#include <iostream>
#include <string>

/**
 * ! Get a variable as a reference and change replace its value with
 * ! another value 
 * 
 * * About the optimization:
 *  Using a parameters as reference helps the computer to get
 *  the value without actually saving them, the computer just
 *  need to get the memory addres that this value is stored
 *  a that helps a lot with memory allocation.
 * 
 *  Also using constant helps the computer to understand what value
 *  will change or not
 * 
 * ? Does a value need to be changed? If not; make it const, else just make it a reference.
*/
void func1(int& valueToChange, const int& value) {
    valueToChange = value;
}

const float median(const int& a, const int& b, const int& c) {
    return (a + b + c) / 3.f;
}

int main() {
    int a = 20;
    int b = 10;

    func1(a, b);

    std::cout << a << std::endl;

    system("PAUSE");
}