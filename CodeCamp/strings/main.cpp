#include <iostream>

using namespace std;

int main()
{
    string phrase = "Giraffe Academy";
    char phraseFirstLetter = phrase[0]; // get the first letter of phrase variable

    cout << phraseFirstLetter << endl;

    cout << phrase.find("ffe", 0) << endl; // find the "ffe" in the phrase variable

    cout << phrase.substr(0, 3); // get a subsection of strings in the phrase variable
}