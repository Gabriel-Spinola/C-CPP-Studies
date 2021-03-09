#include <iostream>
#include <ctime>
#include <vector>
#include <string>

// Optimal compilation: g++ -o main.exe main.cpp -O2
// Debug compilation: g++ -o main.exe main.cpp

// when using iterators ++i is faster than i++

int main() {
    std::vector<int> intarr(1000000, 1);
    int sum = 0;
    
    int start_t = clock();

        // Normal Loop (avr: 0.004)
        for(int i = 0; i < intarr.size(); i++) {
            sum += intarr[i];
        }
        
        // C++ 11 foreach loop (arv: 0.011)
        for(auto& i : intarr) {
            sum += intarr[i];
        }

        // Iterator range loop (avr: 0.0065)
        const std::vector<int>::const_iterator end = cend(intarr); // iterator caching

        for(std::vector<int>::const_iterator it = cbegin(intarr); it != end; ++it) {
            sum += *it;
        }

    int end_t = clock();

    std::cout << "Time: " << (end_t - start_t) / double(CLOCKS_PER_SEC) << std::endl;
    std::cout << "Sum: " << sum << std::endl;

    system("pause");
}