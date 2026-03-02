/*DATA UNA LISTA DI NUMERI ORDINATI Es: 4->6->8->11
COMPLETARE LA LISTA CON I NUMERI MANCANTI 
Es: 4->5->6->7->8->9->10->11   */

#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int num;
    struct Nodo* next;
}Nodo;

typedef struct Lista{
    Nodo* testa;
    int lunghezza;
}Lista;

Lista* creaLista(){
    Lista* lista =(Lista*)malloc(sizeof(Lista));
    lista->testa = NULL;
    lista->lunghezza = 0;
    return lista;
}

void inserisciNodo(Lista* lista){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    printf("Inserisci numero: ");
    scanf("%d", &nodo->num);

    if(lista->testa == NULL){
        nodo->next = lista->testa;
        lista->testa = nodo;
    }else{
        Nodo* current = lista->testa;
        while(current->next != NULL){
            current = current->next;
        }
        nodo->next = current->next;
        current->next = nodo;
    }

    lista->lunghezza++;
}

void func(Lista* lista){
    Nodo* current = lista->testa;
    while(current->next != NULL){
        if(current->num+1 != current->next->num && current != NULL){
            Nodo* numero = (Nodo*)malloc(sizeof(Nodo));
            numero->num = current->num+1;
            numero->next = current->next;
            current->next = numero;
            lista->lunghezza++;
        }
        current = current->next;
    }
}

void libera(Lista* lista){
    Nodo* current = lista->testa;
    while(current != NULL){
        Nodo* temp = current;
        current = current->next;
        free(temp);
    }
    free(lista);
}
 
void stampa(Lista* lista){
    Nodo* temp = lista->testa;
    while(temp != NULL){
        printf("%d -> ", temp->num);
        temp = temp->next;
    }
    printf("\n lunghezza: %d", lista->lunghezza);
}

int main(){
    Lista* lista = creaLista();

    int scelta;

    do {
        printf("\n--- LISTA ---\n");
        printf("1. Inserisci numero\n");
        printf("2. funzione\n");
        printf("3. stampa\n");
        printf("0. Esci\n");

        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar(); // pulisci buffer input

        switch (scelta) {
            case 1:
                inserisciNodo(lista);
                break;
            case 2:
                func(lista);
                break;
            case 0:
                libera(lista);
                printf("Uscita...\n");
                break;
            case 3:
                stampa(lista);
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 0);
    

    return 0;
}