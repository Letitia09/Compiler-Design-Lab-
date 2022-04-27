#include <stdio.h>
#include <ctype.h>
#include <string.h>

int L();
int Lprime();

int i = 0, f = 0;
char str[30];

int main()
{
    int len=3;
    scanf("%s", str);
    len = strlen(str);
    str[len] = '$';
    L();
    if ((str[i] == '$') || (f == 0))
        printf("String sucessfully parsed!");
    else
        printf("syntax Error!");
    return 0;
}


int L()
{
    printf("L->xL'y");
    i++;
    Lprime();
    return 0;
}

int Lprime()
{
    if (str[i] == 'y')
    {
        printf("L'->yz");
        i+=2;
    }
    else if(str[i] == 'z')
    {
        printf("L'->z");
    }
    else
    {
        f = 1;
    }
    return 0;
}
