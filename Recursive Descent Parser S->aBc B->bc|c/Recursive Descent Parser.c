#include <stdio.h>
#include <ctype.h>
#include <string.h>

int S();
int B();

int i = 0, f = 0;
char str[30];

int main()
{
    int len=3;
    scanf("%s", str);
    len = strlen(str);
    str[len] = '$';
    S();
    if ((str[i] == '$') || (f == 0))
        printf("String sucessfully parsed!");
    else
        printf("syntax Error!");
    return 0;
}


int S()
{
    printf("S->aBc");
    i++;
    B();
    return 0;
}

int B()
{
    if (str[i] == 'b')
    {
        printf("B->bc");
        i+=2;
    }
    else if(str[i] == 'c')
    {
        printf("B->c");
    }
    else
    {
        f = 1;
    }
    return 0;
}
