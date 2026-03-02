/*Scrivi un programma che chieda all'utente di inserire una 
frase da tastiera e la salvi in un file chiamato diario.txt.
*/

#include <stdio.h>
#include <stdlib.h>


int main(){
    FILE* file = NULL;
    char frase[100];

    printf("Inserisci frase: ");
    fgets(frase, 100, stdin);

    file = fopen("diaro.txt", "w");
    if(file == NULL){
        printf("Errore di apertura file");
        return 1;
    }

    fputs(frase, file);

    return 0;
}