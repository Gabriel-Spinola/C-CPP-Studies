#include <iostream>

using namespace std;

class Book 
{
    public:
        // Attributes
        string title;
        string author;

        int pages;
        
        // Constructor | runs when the book is instantiated and can create the classes parematers
        Book() {
            title = "No Title";
            author = "No Author";

            pages = 0;
        }

        Book(string aTitle, string aAuthor, int aPages) {
            title = aTitle;
            author = aAuthor;
            pages = aPages;
        }
};

int main()
{
    Book book1("Harry Potter", "JK Rowling", 500);
    Book book2("Lord of the Rings", "Tolkein", 700);
    Book book3;

    // book1.title = "Harry Potter";
    // book1.author = "JK Rowling";
    // book1.pages = 500;

    // book2.title = "Lord of the Rings";
    // book2.author = "Tolkein";
    // book2.pages = 700;

    cout << book1.title << endl;
    cout << book2.title << endl;
    cout << book3.title << endl;
}