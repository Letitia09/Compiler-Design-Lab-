%option noyywrap
%{
#include<stdio.h>
%}
letter [a-zA-Z]
digit [0-9]
operator [-+*/=%]
relop [<>]
special [;:.'"]
ws [\n \t]
%%
int|main|float|printf|return printf("%s is a keyword\n",yytext);
{letter}({letter}|{digit})* printf("%s is a variable\n",yytext);
{digit}+.{digit}+ printf("%s is a floating point number\n",yytext);
{digit}+ printf("%s is an integer number\n",yytext);
{operator} printf("%s is an operator\n",yytext);
{relop} printf("%s is a relational operator\n",yytext);
{special} printf("%s is a special character\n",yytext);
\{ printf("%s is a set open bracket\n",yytext);
\} printf("%s is a set close bracket\n",yytext);
\( printf("%s is a open bracket\n",yytext);
\) printf("%s is a close bracket\n",yytext);
{ws};
%%
int main(int argc,char *argv[]){
FILE *fp;
fp=fopen("input.txt","r");
if(fp==NULL) printf("no file exists");
else {
yyin=fp;
yylex();
return 0;
}
}
