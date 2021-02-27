#include <iostream>
#include <vector>

// * The arr parameter can be write like this: const int* arr; as a pointer
// * Like the replaceArr function example
// =======================================================================
// ! I used the const keyword on the arr parameter cause we're just printing,
// ! and there's no need to change that variable value
void printArr(const int& size, const int arr[]) {
    for(size_t i = 0; i < size; i++) {
        std::cout << arr[i] << ' ';
    }

    std::cout << std::endl;
}

void replaceArr(const int& size, int* arr, const int& value) {
    for(size_t i = 0; i < size; i++) {
        arr[i] = value;
    }
}

void printVector(const std::vector<int>& vec) {

}

int main() {
    const int arraySize = 10;

    int arr[arraySize] = {
        0, 1, 2, 3, 4,
        5, 6, 7, 8, 9
    };

    replaceArr(arraySize, arr, 200);
    printArr(arraySize, arr);
}