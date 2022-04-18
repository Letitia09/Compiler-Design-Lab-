%{
 #include<stdio.h>
extern int yylex(void);
void yyerror(char *);
int x=0;
%}
%token INT
%%
S:
S E '\n'                   {printf("%d\n",$2);}
|            
;
E:              
|E '+' E   {$$=$1+$3;}
|E '-' E   {$$=$1-$3;}
|E '*' E   {$$=$1*$3;}
|E '/' E   {$$=$1/$3;}
|'(' E ')' {$$=$2;}
|INT       {$$=$1;}  
%%
void yyerror(char *s)
{
printf("%s",s);
}
int main()
{
yyparse();
return 0;
}
