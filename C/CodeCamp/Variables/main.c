#include <stdio.h>
#include <stdlib.h>

int main() {
    char characterName[] = "John";
    int characterAge = 35;
    float nums = 35.f;
    char grade = 'A';

    printf("There once was as man named %s\n", characterName);
    printf("He was %d years old.\n", characterAge);
    printf("He really liked the name %s\n", characterName);
    printf("but did not like being %d.\n");

    printf("%f\n", nums);
    printf("%c\n", grade);

    /**
     * %s = string, %d = integers,
     * %f = decimal numbers, %c = single character
    */
    return 0;
}