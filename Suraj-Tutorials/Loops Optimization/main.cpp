#include <iostream>
#include <ctime>
#include <string>

int main() {
    int start_t = clock();



    int end_t = clock();

    std::cout << "Time: " << (end_t - start_t) / double(CLOCKS_PER_SEC) << std::endl;
    std::cout << "Hello?";

    system("pause");
}