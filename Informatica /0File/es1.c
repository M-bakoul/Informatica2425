// POSTA

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
typedef FILE* file;


void InserisciLettera(string t){
    file f;

    f = fopen("lettera1.txt", "w");
    fprintf(f, "%s", t);
    fclose(f);
}


int main(){
    string testo = (string)malloc(30+1 * sizeof(char));

    printf("Inserisci messaggio che vuoi mettere nel file: ");
    fgets(testo, 31, stdin);
    InserisciLettera(testo);
}