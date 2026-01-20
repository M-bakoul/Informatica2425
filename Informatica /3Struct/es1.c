#include <stdio.h>
#include <stdlib.h>

int main(){

    struct Persona{
        char nome[10];
        char cognome[10];
        int eta;
    };

    struct Persona persona1;
    persona1.eta = 80;

    printf("%d\n", persona1.eta);
}