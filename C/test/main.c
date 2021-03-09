#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } bool;

int main() {
    bool appLoop = true;

    while(appLoop == true) {
        char input[255]; 

        printf("Sevens :: ");
        scanf("%s",input);

        if(strcmp(input, "_e0"))
            appLoop = false;
    }

    return 0;
}
