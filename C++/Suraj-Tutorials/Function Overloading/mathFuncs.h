#ifndef MATHFUNCS_H
    #define MATHFUNCS_H

    #include <iostream>
    #include <string>

    int add(int a, int b) {
        std::cout << "Hello from int add function!" << std::endl;

        return a + b;
    }

    float add(float a, float b) {
        std::cout << "Hello from float add function!" << std::endl;

        return a + b;
    }

    float add(float a) {
        std::cout << "Hello from float add function 2!" << std::endl;

        return a + 1;
    }
#endif // !MATHFUNCS_H