#include <iostream>
#include <array>
#include <string>

int main() {
    const int arrSize = 5;
    int arr[arrSize]; // [1][2][3][4][5]

    int twoDimensionalArray[arrSize][arrSize]; // [1][2][3][4][5]
                                               // [1][2][3][4][5]

    for(int i = 0; i < arrSize; i++) {
        for(int j = 0; j < arrSize; j++) {
            std::cout << twoDimensionalArray[i][j];
        }
    }

    system("PAUSE");
}