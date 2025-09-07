%{
    #include<stdio.h>
    #include<stdlib.h>
    #include "y.tab.h"
    #include "tree.h"
    int line_no=1;
    int number;
%}

%option yylineno
%option noyywrap

letter          [a-zA-Z]
digit           [0-9]
id              {letter}({letter}|{digit})*
num             {digit}+
relop           "<"|">"|"<="|">="|"=="|"!="

%%

"BcsMain"   { return BCSMAIN; }
"if"        { return IF; }
"else"      { return ELSE; }
"while"     { return WHILE; }
"int"       { return INT; }
"bool"      { return BOOL; }
{id}        { yylval.no=makeLeafNode(0,yytext); return ID; }
{num}       { number=atoi(yytext);yylval.no=makeLeafNode(number,yytext);return NUM; }
{relop}     { return RELOP; }
[ \t]+      ; // ignore whitespace
[\n]        { line_no++; }
";"         { return SEMICOLON; }
"="         { return ASSIGN; }
"{"         { return LBRACE; }
"}"         { return RBRACE; }
"("         { return LPAREN; }
")"         { return RPAREN; }
"+"         { return ADD; }
"*"         { return MULTIPLY; }

%%

