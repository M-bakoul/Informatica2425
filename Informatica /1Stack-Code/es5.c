#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* next;
} Nodo;

typedef struct Coda{
    Nodo* head;
    Nodo* tail;
    int lunghezza;
} Coda;

Coda* creaCoda() {
    Coda* coda = (Coda*)malloc(sizeof(Coda));
    coda->head = NULL;
    coda->tail = NULL;
    coda->lunghezza = 0;
    return coda;
}

// Head → A, B, C ← Tail
// enqueue / inserimento
// dequeue / estrazione testa
// front / visualizzazione testa
// rear / visualizzazione coda
// stampa coda
// libera coda

void liberaMemoria(Coda* coda){
    Nodo* current = coda->head;

    while(current != NULL){
        Nodo* speed = current;
        current = current->next;
        free(speed);
    }
    free(coda);
}

void stampaCoda(Coda* coda){
    if(coda->tail == NULL){
        printf("Coda vuota");
        return;
    }

    Nodo* current = coda->head;
    while(current != NULL){
        printf("%d", current->dato);
        current = current->next;
    }

}

int rear(Coda* coda){
    if(coda->tail == NULL){
        printf("Cosa vuota");
        return -1;
    }

    return coda->tail->dato;
}


int front(Coda* coda){
    if(coda->head == NULL){
        printf("Cosa vuota");
        return -1;
    }

    return coda->head->dato;
}

int dequeue(Coda* coda){
    if(coda->tail == NULL){
        printf("Coda vuota");
        return -1;
    }
    int valore = coda->head->dato;
    Nodo* current = coda->head;
    coda->head = coda->head->next;
    free(current);
    coda->lunghezza--;

    if(coda->head == NULL){
        coda->tail = NULL;
    }

    return valore;

}

void enqueue(Coda* coda){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    
    if(coda == NULL || nodo == NULL){
        printf("Errore");
        return;
    }
    printf("Inserisci dato: ");
    scanf("%d", &nodo->dato);

    if(coda->tail==NULL){
        coda->head = nodo;
        coda->tail = nodo;
    }else{
        coda->tail->next = nodo;
        coda->tail = nodo;
        
    }
    coda->lunghezza++;
}

int main(){
    Coda* coda = creaCoda();
    int scelta;

    do{
        printf("\n--- CODA ---\n");
        printf("1. Inserisci nodo\n");
        printf("2. Elimina e ritorna primo nodo\n");
        printf("3. Mostra primo nodo\n");
        printf("4. Mostra ultimo nodo\n");
        printf("5. Stampa coda\n");
        printf("0. Esci ed elimina intera coda\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                enqueue(coda);
                break;
            case 2:
                int l;
                l = dequeue(coda);
                printf("%d", l);
                break;
            case 3:
                int x;
                x = front(coda);
                printf("%d", x);
                break;
            case 4: 
                int f;
                f = rear(coda);
                printf("%d", f);
                break;
            case 5: 
                stampaCoda(coda);
                break;
            case 0:
                printf("Uscita...");
                liberaMemoria(coda);
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
                break;
        }
    }while(scelta != 0);
}