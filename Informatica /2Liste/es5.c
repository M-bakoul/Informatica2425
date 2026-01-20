#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Nodo{
    int dato;
    struct Nodo* next;
}Nodo;

typedef struct Lista{
    Nodo* head;
    int lunghezza;
}Lista;

Lista* creaLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->head = NULL;
    lista->lunghezza = 0;
    return lista;
}

void creaNodoTesta(Lista* lista){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    printf("Inserisci valore al nodo");
    scanf("%d", &nodo->dato);

    nodo->next = lista->head;
    lista->head = nodo;
    lista->lunghezza++;
}

void creaNodoCoda(Lista* lista){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));

    printf("Inserisci valore al nodo");
    scanf("%d", &nodo->dato);
    
    if(lista->head == NULL){
        nodo->next = lista->head;
        lista->head = nodo;
    }else{
        Nodo* temp = lista->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = nodo;
        nodo->next = NULL;
    }
    lista->lunghezza++;
}


void cercaValoreLista(Lista* lista, int valore){
    Nodo* temp = lista->head;
    int posizione = 0;

    while(temp->next != NULL){
        if(temp->dato == valore){
            printf("Valore trovato %d, posizione: %d", &temp->dato, posizione+1);
            return;
        }
        temp = temp->next;
        posizione++;
    }
}

void eliminaNodoLista(Lista* lista){
    char scelta;
    printf("Vuoi eliminarlo in testa o coda? (t/c)");
    scanf(" %c", &scelta);

    if(lista->head == NULL){
        printf("Lista vuota");
        return;
    }

    if(scelta == 't'){
        Nodo* temp = lista->head;
        lista->head = lista->head->next;
        free(temp);
        lista->lunghezza--;
    }else if(scelta == 'c'){

        if(lista->head->next == NULL){
            Nodo* Cenat = lista->head;
            lista->head = NULL;
            free(Cenat);
            lista->lunghezza--;
            return;
        }

        Nodo* temp = lista->head;
        while(temp->next->next != NULL){
            temp = temp->next;
        }
        Nodo* speed = temp->next;
        temp->next = NULL;
        free(speed);
        lista->lunghezza--;
    }
}

void liberaLista(Lista* lista){
    Nodo* temp = lista->head;

    while(temp != NULL){
        Nodo* del = temp;
        temp = temp->next;
        free(del);
    }

    free(lista);

}


int main(){
    int scelta;
    Lista* lista = creaLista();
    int val;



    do{
        printf("1. Crea Nodo in testa");
        printf("2. Crea Nodo in coda");
        printf("3. Cerca valore nella lista");
        printf("4. Elimina Nodo nella lista per valore ");
        printf("5. Libera Lista");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                creaNodoTesta(lista);
                break;
            case 2:
                creaNodoCoda(lista);
                break;
            case 3:
                printf("Inserisci valore da cercare");
                scanf("%d", &val);
                cercaValoreLista(lista, val);
                break;
            case 4:
                eliminaNodoLista(lista);
                break;
            case 0:
                printf("Uscita dal programma...\n");
                break;
            default:
                printf("Scelta non valida\n");
        }
    }while(scelta != 0);

    liberaLista(lista);

}