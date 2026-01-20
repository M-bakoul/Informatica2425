#include <stdio.h>
#include <stdlib.h>

typedef char* string;

typedef struct{
    string* targa;
    string* marca;
    string* modello;
    int prezzoNoleggio;
}Auto;

Auto* inserisciAuto(Auto* parco, int* n){
    parco=(int*)realloc((n+1) * sizeof(int));
    Auto nuovaAuto;
    parco[n] = nuovaAuto;
    n += 1;

    printf("Inserisci targa: ");
    fgets(nuovaAuto.targa, 30, stdin);
    printf("Inserisci marca: ");
    fgets(nuovaAuto.marca, 30, stdin);    
    printf("Inserisci modello: ");
    fgets(nuovaAuto.modello, 30, stdin);    
    printf("Inserisci prezzoNoleggio: ");
    scanf("%d", &prezzoNoleggio);

    return nuovaAuto;
}

void stampaAuto(Auto* parco, int* n){
    for(int i=0; parco[i] != '\0'; i++){
        printf("%d", parco[i]);
    }
}
int main(){
    int parco = (int*)malloc(1*sizeof(int));
    int scelta;

    printf("1. Inserisci auto");
    printf("2. Stampa auto");
    printf("3. Cerca Auto");
    scanf("%d", %scelta);

    switch (scelta){
    case 1:
        inserisciAuto(parco, n);
        break;
    case 2:
        stampaAuto(parco, n);
    default:
        break;
    }

    
}