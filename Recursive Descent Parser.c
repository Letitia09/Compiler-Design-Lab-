#include <stdio.h>
#include<string.h>
int i=0,f=0;
char str[30];

void E();
void Eprime();
void T();
void Tprime();
void F();

void E(){
    printf("E->TE'");
    T();
    Eprime();
}

void Eprime(){
    if (str[i]=='+'){
        printf("E'->+TE'");
        i++;
        T();
        Eprime();
    }
    else if((str[i]==')')||(str[i]=='$')){
        printf("E'->^");
    }
}

void T(){
    printf("T->FT'");
    F();
    Tprime();
}

void Tprime(){
    if(str[i]=='*'){
        printf("T'->*FT'");
        i++;
        F();
        Tprime();
    }
    else if((str[i]==')')||(str[i]=='+')||(str[i]=='$')){
        printf("T'->^");
    }
}

void F(){
    if(str[i]=='a'){
        printf("F->a");
        i++;
    }
    else if(str[i]=='('){
        printf("T'->^");
        i++;
        E();
        if(str[i]==')'){
            i++;
        }
    }
    else{
        f=1;
    }
}

int main(){
    int len;
    scanf("%s",str);
    len=strlen(str);
    str[len]='$';
    E();
    if((str[i]=='$') && (f==0)){
        printf("string sucessfully parsed!");
    }
    else{
        printf("syntax Error!");
    }
}
