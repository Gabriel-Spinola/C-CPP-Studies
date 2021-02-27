#include <iostream>

using namespace std;

int main()
{
    int num1, num2;
    char operator1;

    cout << "Enter first number: ";
    cin >> num1;

    cout << "Enter the operator: ";
    cin >> operator1;

    cout << "Enter Second number: ";
    cin >> num2;

    switch (operator1)
    {
        case '+':
            cout << num1 + num2;
        break;

        case '-':
            cout << num1 - num2;
        break;

        case '/':
            cout << num1 / num2;
        break;

        case '*':
            cout << num1 * num2;
        break;
    
        default:
            cout << "Enter a valid input";
        break;
    }
}