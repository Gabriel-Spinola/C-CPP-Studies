#include "mathFuncs.h"

int main() {
    // The computer will use the necessary function based on the context
    // in this case is the parameters.
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.f, 3.f) << std::endl;
    std::cout << add(1.f) << std::endl;

    system("pause");
}