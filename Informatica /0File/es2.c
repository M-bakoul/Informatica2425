// Crea file C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
typedef FILE* file;


void InserisciLettera(){
    file f;
    f = fopen("file.py", "w");
    if(f == NULL){
        ("Errore apertura file");
        exit(1);
    }

    fprintf(f, "a = 10\n");
    fprintf(f, "b = 20\n");
    fprintf(f, "c = a+b\n");
    fprintf(f, "print(c)\n");


    fprintf(f, "\n");
    fclose(f);
}


int main(){
    InserisciLettera();

}