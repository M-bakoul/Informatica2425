/* 
    Esempio di malloc e realloc insieme
    Scrivere un programma in linguaggio C che:
    1. Allochi dinamicamente un array iniziale di n numeri interi con malloc;
    2. inserimento dei valori;
    3. stampi l'array;
    4. calcoli la somma dei valori multipli di 3;
    5. creiamo un nuovo array con solo i numeri dispari

*/ 

#include <stdio.h>
#include <stdlib.h>

typedef int* array;

int main(){    
    array vett = NULL;
    


}

array creaVett (int dim ){
    array vett=(vett)malloc(dim * sizeof(int));

    if(vett==NULL){
        printf("Errore di allocazione");
        return 1;
    }

    for(int i=0; i<dim; i++){
        printf("Inserisci posizione array %d" i);
        scanf("%d", &vett[i]);
    }

    for(int i=0; i<dim; i++){
        printf("%d", &vett[i]");
    }


}

array sommaMultipli(array vett, int dim){
    int cont;
    
    for(int i = 0; i<0; i++){
        
    }

}