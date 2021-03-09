#include <stdio.h>
#include <stdlib.h>

int main() 
{
    char ch[255];
    char s[255];
    char sen[255];

    scanf("%c",&ch);
    scanf("%s",&s);
    scanf("%s",&sen);

    printf("%c\nLanguage\n%s\n%s",ch[0],s,sen);
}