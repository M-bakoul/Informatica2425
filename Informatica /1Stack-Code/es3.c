#include <stdio.h>
#include <stdlib.h>

typedef struct PilaArray{
    int* elementi;
    int top;
    int capacita;
} PilaArray;

PilaArray* creaPilaArray(int dim){
    PilaArray* pila = (PilaArray*)malloc(sizeof(PilaArray));
    pila->elementi = (int*)malloc(dim * sizeof(int));
    pila->top = -1;
    pila->capacita = dim;

    return pila;
}

void push(PilaArray* pila){
    if(pila->top >= pila->capacita - 1){
        printf("Pila piena");
        return;
    }

    int valore;
    printf("Inserisci dato: ");
    scanf("%d", &valore);

    pila->top++;
    pila->elementi[pila->top] = valore;
}

int pop(PilaArray* pila){
    if(pila->top < 0){
        printf("Pila vuota");
        return -1;
    }

    return pila->elementi[pila->top--];
}


int main(){
    int dim1;
    printf("Inserisci dim: ");
    scanf("%d", &dim1);

    PilaArray* pila = creaPilaArray(dim1);
    int scelta;

    do{
        printf("\n--- PILA ---\n");
        printf("1. Inserisci nodo\n");
        printf("2. Elimina e ritorna ultimo nodo\n");
        printf("0. Esci ed elimina intera pila\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                push(pila);
                break;
            case 2:
                int l;
                l = pop(pila);
                printf("%d", l);
                break;
            case 0:
                printf("Uscita...");
                free(pila);
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
                break;
        }
    }while(scelta != 0);
}