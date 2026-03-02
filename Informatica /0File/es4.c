/* Crea un programma che legga il contenuto di un file esistente
(es. sorgente.txt) e ne crei una copia identica chiamata 
copia.txt.*/

#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE* file = NULL;
    char buffer[200];
    char copia[200];


    file = fopen("sorgente.txt", "r");
    if(file == NULL){
        printf("Errore di apertura file");
        return 1;
    }

    while( fgets(buffer, 200, file) != NULL) {}

    for(int i = 0; i<200; i++){
        copia[i] = buffer[i];
    }
    
    printf("%s", copia);

    fclose(file);

    return 0;
}