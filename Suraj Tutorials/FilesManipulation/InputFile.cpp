#include <iostream>
#include <string>

// file stream
#include <fstream>

using namespace std;

int main() {
    const char* fileName = "myFile.txt";

    ifstream inFile(fileName);

    if(inFile.is_open()) {
        cout << "Files is open!\n";
    }
    else
        cout << "Could not Open file: " << fileName;

    inFile.close();

    system("PAUSE");
}