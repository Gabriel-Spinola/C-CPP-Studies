#include <iostream>

using namespace std;

int main()
{
    char chars[10];
    int luckyNums[] = { 4, 8, 3, 4, 5, 6, 7, 8 }; // unlimited values
    int coolNums[5] = { 7, 2, 5, 6, 4 }; // max of 5 values

    coolNums[0] = 15;

    const int nLength = 3;
    const int mLength = 2;

    float numberGrid[nLength][mLength] = {
        { 1.f, 2.f },
        { 3.f, 2.f },
        { 4.f, 6.f },
    };

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 2; j++)
            cout << numberGrid[i][j];
}