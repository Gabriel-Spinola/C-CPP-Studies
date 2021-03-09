#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char s[100];

    scanf("%[^\n]%*c",&s); // & is used to reference the scanf result to the s variable

    printf("Hello, World\n%s",s); // Prints s variable.

    return 0;
}