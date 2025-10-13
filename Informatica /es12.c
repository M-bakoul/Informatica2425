/* 
 Crea un array dinamico di interi con malloc. Poi chiedi all’utente
 di inserire altri elementi uno alla volta. Ad ogni inserimento, espandi
 l’array con realloc. Infine, stampa tutti gli elementi.
*/


#include <stdio.h>
#include <stdlib.h>

typedef int* array;

int main(){
    array vett= NULL;
    int dim;
    int dim1;


    printf("Inserisci dim: ");
    scanf("%d", &dim);

    vett=(array)malloc(dim * sizeof (int));

    if(vett==NULL){
        printf("Errore di allocazione");
        return 1;
    }

    for(int i=0; i<dim; i++){
        printf("Inserisci elemento %d: ", i);
        scanf("%d", &vett[i]); 
    }

    printf("Inserisci nuova dim: ");
    scanf("%d", &dim1);

    vett=(array)realloc(vett, (dim + dim1) *sizeof (int));

    if(vett==NULL){
        printf("Errore di allocazione");
        return 1;
    }

    for(int i = dim; i< dim+dim1; i++){
        printf("Inserisci dim %d: ", i);
        scanf("%d", &vett[i]);
    }


    for(int i=0; i<dim+dim1; i++){
        printf("%d", vett[i]);
    }

    free(vett);

}
