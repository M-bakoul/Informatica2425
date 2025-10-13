/*  
    Scrivi un programma in C che:
    1. Chiede all’utente quanti numeri interi vuole inserire;
    2. Alloca dinamicamente un array di quella dimensione con malloc();
    3. Permette all’utente di inserire i numeri;
    4. Chiede all’utente se vuole aumentare la dimensione dell’array;
        - Se sì, richiede la nuova dimensione e usa realloc() per ridimensionarlo;
        - Permette quindi di inserire i nuovi valori negli spazi aggiunti;
    5. Infine, stampa tutti gli elementi dell’array.
*/

#include <stdio.h>
#include <stdlib.h>

typedef int* array;

int* creaVett(int n){
    array vett = (array)malloc(n * sizeof(int));


    if(vett==NULL){
        printf("Errore di allocazione");
        return NULL;
    }
    return vett;
}

int* inserisciElementi(array vett, int* n){
    char risposta;
    int ris=0;


    for(int i=0; i< *n; i++){
        printf("Inserisci l'elemento %d", i);
        scanf("%d", &vett[i]);
    }

    printf("Vuoi aumentare la dimensione? s/n ");
    scanf(" %c", &risposta);

    if (risposta=='s'){
        printf("di quanto?");
        scanf("%d", &ris);
        vett = (array)realloc(vett, (*n+ris) * sizeof(int));

        if(vett == NULL){
            printf("errore di reallocazione");
            return NULL;
        }

        for(int i= *n; i< *n+ris; i++){
            printf("Inserisci l'elemento %d: ", i);
            scanf("%d", &vett[i]);
        }

        *n += ris;
    }else if (risposta == 'n'){

    }else{
        printf("Errore");
    }

    return vett;

}



int main(){
    array vett = NULL;
    int n;

    do{
        printf("Inserisci la quantità degli elementi: ");
        scanf("%d", &n);
    }while(n<0);

    vett=creaVett(n);
    vett = inserisciElementi(vett, &n);

    printf("Gli elementi inseriti sono:\n");
    for(int i = 0; i < n; i++){
        printf("%d ", vett[i]);
    }
    printf("\n");

    free(vett);
    return 0;
}