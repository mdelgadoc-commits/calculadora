%{
#include <iostream>
#include <string>
#include <cstring>
#include "calc.tab.h"

int num_linea = 1;
extern int total_errores_lexicos;
%}

%%

"entero"        { return TENTERO; }
"decimal"       { return TDECIMAL; }
"texto"         { return TTEXTO; }
"si"            { return SI; }
"sino"          { return SINO; }
"mientras"      { return MIENTRAS; }
"para"          { return PARA; }
"funcion"       { return FUNCION; }
"retornar"      { return RETORNAR; }
"mostrar"       { return MOSTRAR; }
"datoingresado" { return DATOINGRESADO; }
"verdadero"     { return VERDADERO; }
"falso"         { return FALSO; }

"<<"  { return SALIDA; }
">>"  { return ENTRADA; }
"<="  { return LE; }
">="  { return GE; }
"=="  { return EQ; }
"!="  { return NE; }
"&&"  { return AND; }
"||"  { return OR; }
"!"   { return NOT; }
"<"   { return LT; }
">"   { return GT; }

[0-9]+\.[0-9]+\.[0-9]+ {
    std::cerr << "\n[ERROR LEXICO] Linea " << num_linea
              << ": numero invalido '" << yytext << "'\n"
              << "  Solucion: usa solo un punto decimal. Ej: 1.22\n\n";
    total_errores_lexicos++;
}

[0-9]+(\.[0-9]+)? {
    yylval.num = atof(yytext);
    return NUM;
}

\"[^\"]*\" {
    yylval.str = strdup(yytext);
    return TEXTO_VAL;
}

[a-zA-Z_][a-zA-Z0-9_]* {
    yylval.str = strdup(yytext);
    return ID;
}

\n     { num_linea++; }
[ \t]  ;

"+"  { return '+'; }
"-"  { return '-'; }
"*"  { return '*'; }
"/"  { return '/'; }
"%"  { return '%'; }
"="  { return '='; }
";"  { return ';'; }
","  { return ','; }
"("  { return '('; }
")"  { return ')'; }
"{"  { return '{'; }
"}"  { return '}'; }
"["  { return '['; }
"]"  { return ']'; }

. {
    std::cerr << "\n[ERROR LEXICO] Linea " << num_linea
              << ": caracter desconocido '" << yytext << "'\n"
              << "  Solucion: revisa que el caracter pertenezca al lenguaje.\n\n";
    total_errores_lexicos++;
}

%%

int yywrap() { return 1; }