#include <iostream>

using namespace std;

class Chef
{
    public:
        void makeChicken() {
            cout << "The chef makes Chicken" << endl;
        }

        void makeSalad() {
            cout << "The chef makes Salad" << endl;
        }

        void makeSpecialDish() {
            cout << "The chef makes Special Dish" << endl;
        }
};

class ItalianChef : public Chef { };

int main() {
    ItalianChef italianChef;
    italianChef.makeChicken();
}