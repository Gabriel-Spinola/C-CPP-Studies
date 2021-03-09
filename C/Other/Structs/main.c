#include <stdio.h>

/**
 * A struct in the C programming language is a composite data type
 * declaration that defines a physically grouped list of variables under one name in a block of memory,
 * allowing the different variables to be accessed via a single pointer or by the struct declared name which returns the same address 
*/
typedef struct 
{
    int x, y;
    short life;
    char* name;
} Man;

void structs() {
    // Construct
    Man man, man2;

    // Declaring the values.
    man.x = 30;
    man.y = 45;
    man.life = 100;
    man.name = "Jorge";

    man2.x = 60;
    man2.y = 145;
    man2.life = 855;
    man2.name = "Dani";

    printf("name of man: %s\n", man.name);

    Man man3[100];

    for(short i = 0; i < 100; i++) {
        if(1 < 50)
            man3[i].x = 0;
        else
            man3[i].x = 200;

        man3[i].y = i * 8;
        man3[i].life = i;
        man3[i].name = "man";
    }
}

int main(int argc, char* argv[]) {
    structs();
}