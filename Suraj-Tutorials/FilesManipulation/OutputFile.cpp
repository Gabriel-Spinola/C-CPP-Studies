#include <iostream>
#include <string>

// file stream
#include <fstream>

using namespace std;

/**
 * ====OUTPUT TO FILE====
 * - IF FILE DOESN'T EXIST WITH A CERTAIN NAME IT WILL BE CREATED
 * - TEXT OR BINARY
 * - FILE-TYPE DOESN'T REALLY MATTER, IT WILL BE TEXT ANYWAY
 * - FLAGS
 * - BE CAREFUL WITH OPENING FILES AND SAVING STUFF
 * - BE CAREFUL WITH WHILE LOOPS
*/
int main() {
    string data = "DATA \n New Line 2.";
    int i = 23;

    string fileName = "File.expf";

    ofstream outFile;

    // Create and Open File
    outFile.open(fileName);

    if(outFile.is_open()) {
        // (outFile <<) = Writing data (w)
        // (outFile >>) = Reading data (r)
        
        // Add Data to the file
        outFile << data << " " << i;
    }
    else {
        cout << "n\n";
    }

    outFile.close();

    system("PAUSE");
}