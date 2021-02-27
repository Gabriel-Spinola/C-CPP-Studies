#include <iostream>
#include <vector>

int getArrayLength(int* arr);
int getArrayLength(float* arr);
int getArrayLength(double* arr);
int getArrayLength(long* arr); 
int getArrayLength(std::string* arr);
int getArrayLength(bool* arr);

// * The sizeof(array) / sizeof(data type) gets the length of the array

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
    for(size_t i = 0; i < vec.size(); i++) {
        std::cout << vec[i] << ' ';
    }

    std::cout << std::endl;
}

int main() {
    int arr[] = {
        0, 1, 2, 3, 4,
        5, 6, 7, 8, 9
    };

    replaceArr(getArrayLength(arr), arr, 200);
    printArr(getArrayLength(arr), arr);

    std::vector<int> myVec;

    for(size_t i = 1; i <= 20; i++) {
        myVec.push_back(i);
    }

    printVector(myVec);

    // you can also use the replace arr to vectors
    replaceArr(myVec.size(), myVec.data(), 100);
    printVector(myVec);
}

inline int getArrayLength(int* arr) { return sizeof(arr) / sizeof(int); }
inline int getArrayLength(float* arr) { return sizeof(arr) / sizeof(float); }
inline int getArrayLength(double* arr) { return sizeof(arr) / sizeof(double); }
inline int getArrayLength(long* arr) { return sizeof(arr) / sizeof(long); }
inline int getArrayLength(std::string* arr) { return sizeof(arr) / sizeof(std::string); }
inline int getArrayLength(bool* arr) { return sizeof(arr) / sizeof(bool); }