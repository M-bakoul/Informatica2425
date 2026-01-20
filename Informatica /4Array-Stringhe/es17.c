#include <stdio.h>
#include <stdlib.h>

typedef int* array;

int main(){
    array vett = NULL;
    array disp = NULL;
    int dim;
    int somma = 0;

    printf("Inserisci dim: ");
    scanf("%d", &dim);

    vett = (array)malloc(dim* sizeof(int));
    
    if(vett==NULL){
        printf("Errore di allocazione");
        return 1;
    }

    for(int i=0; i<dim; i++){
        printf("Inserisci elemento %d: ", i);
        scanf("%d". &vett[i]);
    }


    for(int i=0; i<dim; i++){
        printf("%d", vett[i]);
    }
    
    for(int i=0; i<dim; i++){
        if(vett[i]%3) {
            somma+=vett[i];
        }
    }

    printf("%d", somma);

    if(disp==NULL){
        printf("Errore di allocazione");
        return 1;
    }

    disp = (array)malloc(dim* sizeof(int));
    
    for(int i=0; i<dim; i++){
        if(vett[i]%2 != 0){
            disp[i] == vett[i];
        }
    }

}