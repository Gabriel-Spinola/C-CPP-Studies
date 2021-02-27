#include <iostream>

using namespace std;

class Movie 
{
    private:
        string rating;

    public:
        // Attributes
        string title;
        string director;

        // Constructor | runs when the book is instantiated and can create the classes parematers
        Movie(string aTitle, string aDirector, string aRating) 
        {
            this->title = aTitle; 
            this->director = aDirector;
            this->setRating(aRating);
        }

        // Methods
        void setRating(string aRating) {
            this->rating = aRating == "G" || aRating == "PG" || aRating == "PG-13" ? aRating : "NM";
        }

        string getRating() {
            return this->rating;
        }
};

int main()
{
    Movie movie1("Jim", "Business", "G");
    Movie movie2("Pam", "Art", "PG");

    movie1.setRating("s");

    cout << movie1.getRating();
}