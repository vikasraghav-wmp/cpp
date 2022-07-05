#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void removeChar(char *str, char garbage)
{

    char *src, *dst;
    for (src = dst = str; *src != '\0'; src++)
    {
        *dst = *src;
        if (*dst != garbage)
            dst++;
    }
    *dst = '\0';
}
int main(void)
{
    char ch;
    char *str = malloc(sizeof(char));
    printf("Enter string : ");
    fgets(str, 20, stdin);
    printf("Enter character to remove from string : ");
    scanf("%c", &ch);
    removeChar(str, ch);
    printf("%s", str);
    free(str);
    return 0;
}