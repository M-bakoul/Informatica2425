#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int dato;
    struct Nodo* next;
}Nodo;

typedef struct {
    Nodo* top;
    int lunghezza;
} Pila;

void push(Pila* pila, int valore){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));

    if(nodo == NULL){
        printf("Errore di allocazione");
        return ;
    }

    nodo->dato = valore;
    nodo->next = pila->top;
    pila->top = nodo;
    pila->lunghezza++;
}

int pop(Pila* pila){
    if(pila->top == NULL){
        printf("Errore, stack vuoto");
        return -1;
    }
    int valore = pila->top->dato;
    Nodo* temp = pila->top;
    pila->top=pila->top->next;
    free(temp);
    pila->lunghezza--;

    return valore;
}

int peek(Pila* pila){
    if(pila->top == NULL){
        printf("Errore, stack vuoto");
        return -1;
    }

    return pila->top->dato;
}

void stampaStack(Pila* pila){
    if(pila->top == NULL){
        printf("Errore, stack vuoto");
        return;
    }

    Nodo* temp = pila->top;
    int i=0;
    while(temp != NULL){
        printf("messaggio %d: %d\n", i+1, temp->dato);
        temp = temp->next;
        i++;
    }
}

void liberaStack(Pila* pila){
    if(pila->top == NULL){
        printf("Errore, lista vuota");
        return;
    }

    while(pila->top != NULL){
        Nodo* temp = pila->top;
        pila->top = pila->top->next;
        free(temp);
    }
    pila->lunghezza=0;
}

int main(){
    Pila* pila = (Pila*)malloc(sizeof(Pila));
    pila->top=NULL;
    pila->lunghezza=0;
    int scelta;

    do {
        printf("\n--- STACK ---\n");
        printf("1. Inserisci nuovo messaggio alla lista\n");
        printf("2. Elimina e ritorna ultimo messaggio della lista\n");
        printf("3. Mostra primo messaggio\n");
        printf("4. Stampa intera Chat\n");
        printf("5. Elima intera chat\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                int val;
                printf("Inserisci messaggio: \n");
                scanf("%d", &val);
                push(pila, val);
                break;
            case 2:
                int l;
                l = pop(pila);
                printf("%d", l);
                break;
            case 3:
                int x;
                x = peek(pila);
                printf("%d", x);
                break;
            case 4: 
                stampaStack(pila);
                break;
            case 5:
                liberaStack(pila);
                break;
            case 0:
                free(pila);
                printf("Uscita...");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
                break;
        }

    } while (scelta != 0);
}