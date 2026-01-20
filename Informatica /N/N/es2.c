// Crea file C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
typedef FILE* file;


void InserisciLettera(){
    file f;
    f = fopen("lettera.c", "w");
    fprintf(f, "#include <stdio.h>");
    fprintf(f, "\n\n");
    fprintf(f, "int main(){ ");
    fprintf(f, "\n\n");
    fprintf(f, "    int n = 10; ");
    fprintf(f, "\n");
    fprintf(f, "}");
    fclose(f);


}


int main(){
    InserisciLettera();

}