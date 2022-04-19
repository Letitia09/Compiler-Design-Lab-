/*
S->(E)|b
E->SE'
E'->,SE'|^

....production rules
*/

#include <stdio.h>
#include <string.h>
int i = 0, f = 0;
char str[30];

int S();
int E();
int Eprime();

int S()
{
    if (str[i] == '(')
    {
        printf("S->(E)");
        i++;
        E();
        if(str[i]==')'){
            i++;
        }
    }
    else if ((str[i] == 'b')){
        printf("S->b");
        i++;}
    else{
        f=1;
    }
    return 0;
}

int E()
{
    printf("E->SE'");
    S();
    Eprime();
    return 0;
}

int Eprime()
{
    if (str[i] == ',')
    {
        printf("E'->,SE'");
        i++;
        S();
        Eprime();
    }
    else if ((str[i] == '^')||(str[i]==')')){
        printf("E'->^");
    }
    return 0;
}



int main()
{
    int len;
    scanf("%s", str);
    len = strlen(str);
    str[len] = '$';
    S();
    if ((str[i] == '$') && (f == 0))
        printf("string sucessfully parsed!");
    else
        printf("syntax Error!");
    return 0;
}
