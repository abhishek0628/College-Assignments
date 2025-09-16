%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "tree.c"
    #include "tree.h"
    void yyerror(const char *s);
    int yylex();
    extern int yylineno;
    extern char *yytext;
    extern FILE *yyin;
    FILE *output;
    int count=-1;
    char* newTemp() {
    count++;
    char* buffer = (char*)malloc(10); 
    if (!buffer) {
        perror("Memory allocation failed");
        exit(1);
    }
    sprintf(buffer, "t%d", count); 
    return buffer; 
}
%}

%token BCSMAIN IF ELSE WHILE INT BOOL ID NUM RELOP SEMICOLON ASSIGN LBRACE RBRACE LPAREN RPAREN ADD MULTIPLY

%union{
	struct tnode *no;
	
}

%type <no> term  factor aexpr  stmtlist 
%left ADD 
%left MULTIPLY

%%

program: BCSMAIN LBRACE declist stmtlist RBRACE
    {
        printf("Parsing Successful\n");
        printf("Answer : %d\n",evaluate($<no>4));
				
		exit(0);
    }
;

declist: declist decl
    | decl
;

decl: type ID SEMICOLON
;

type: INT
    | BOOL

stmtlist: stmtlist SEMICOLON stmt {$<no>$ = $<no>3;}
    | stmt {$<no>$ = $<no>1;}
    


stmt: ID ASSIGN aexpr {$<no>$ = $<no>3; fprintf(output,"%s = %s\n",$<no>1->addr,$<no>3->addr);}
    | IF LPAREN expr RPAREN LBRACE stmtlist RBRACE ELSE LBRACE stmtlist RBRACE
    | WHILE LPAREN expr RPAREN LBRACE stmtlist RBRACE
;
expr: aexpr RELOP aexpr
    | aexpr

aexpr: aexpr ADD term {
                       char* temp=newTemp();
                       $<no>$ = makeOperatorNode('+',$<no>1,$<no>3,temp);
                       fprintf(output,"%s = %s + %s\n",temp,$<no>1->addr,$<no>3->addr);

                       }
    | term            {$<no>$ = $<no>1;}
;

term: term MULTIPLY factor {
                            char* temp=newTemp();
                            $<no>$ = makeOperatorNode('*',$<no>1,$<no>3,temp);
                            fprintf(output,"%s = %s * %s\n",temp,$<no>1->addr,$<no>3->addr);
                           }
    | factor               {$<no>$ = $<no>1;}
;

factor: ID {$<no>$ = $<no>1;}
    | NUM {$<no>$ = $<no>1;}
;

%%

int main(int argc, char *argv[]) 
{
    if (argc < 2) 
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(1);
    }
    FILE *file = fopen(argv[1], "r");
    if (!file) 
    {
        perror("Error opening file");
        exit(1);
    }
    output = fopen("output", "w");
    yyin = file;
    yyparse();
    fclose(file);
    fclose(output);
    return 0;
}

void yyerror(const char *s) 
{
    printf(" %d %s Syntax Error\n",yylineno,yytext);
    exit(1);
}