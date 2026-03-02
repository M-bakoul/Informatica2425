#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo{
    int dato;
    struct Nodo* next;
} Nodo;

typedef struct Lista{
    Nodo* head;
    int lunghezza;
} Lista;

Lista* creaLista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->head = NULL;
    lista->lunghezza = 0;
    return lista;
}



void creaNodoTesta(Lista* lista){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    printf("Inserisci valore al nodo: ");
    scanf("%d", &nodo->dato);

    if(lista->head == NULL){ 
        nodo->next = nodo;
        lista->head = nodo;
    } else {
        Nodo* temp = lista->head;
        while(temp->next != lista->head) temp = temp->next; 
        nodo->next = lista->head;
        temp->next = nodo;
        lista->head = nodo;
    }
    lista->lunghezza++;
}


void creaNodoCoda(Lista* lista){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    printf("Inserisci valore al nodo: ");
    scanf("%d", &nodo->dato);

    if(lista->head == NULL){ 
        nodo->next = nodo;
        lista->head = nodo;
    } else {
        Nodo* temp = lista->head;
        while(temp->next != lista->head) temp = temp->next;
        temp->next = nodo;
        nodo->next = lista->head;
    }
    lista->lunghezza++;
}

void cercaValoreLista(Lista* lista, int valore){
    if(lista->head == NULL){
        printf("Lista vuota\n");
        return;
    }

    Nodo* temp = lista->head;
    int posizione = 0;

    do {
        if(temp->dato == valore){
            printf("Valore trovato %d, posizione: %d\n", temp->dato, posizione+1);
            return;
        }
        temp = temp->next;
        posizione++;
    } while(temp != lista->head);

    printf("Valore non trovato\n");
}

void eliminaNodoLista(Lista* lista){
    if(lista->head == NULL){
        printf("Lista vuota\n");
        return;
    }

    char scelta;
    printf("Vuoi eliminarlo in testa o coda? (t/c): ");
    scanf(" %c", &scelta);

    if(scelta == 't'){
        Nodo* temp = lista->head;
        if(lista->head->next == lista->head){ 
            lista->head = NULL;
        } else {
            Nodo* last = lista->head;
            while(last->next != lista->head) last = last->next;
            lista->head = lista->head->next;
            last->next = lista->head;
        }
        free(temp);
        lista->lunghezza--;
    } else if(scelta == 'c'){
        if(lista->head->next == lista->head){ 
            free(lista->head);
            lista->head = NULL;
        } else {
            Nodo* temp = lista->head;
            while(temp->next->next != lista->head) temp = temp->next;
            Nodo* last = temp->next;
            temp->next = lista->head;
            free(last);
        }
        lista->lunghezza--;
    } else {
        printf("Scelta non valida\n");
    }
}

void liberaLista(Lista* lista){
    if(lista->head == NULL){
        free(lista);
        return;
    }

    Nodo* temp = lista->head;
    Nodo* nextNode;

    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while(temp != lista->head);

    free(lista);
}

int main(){
    int scelta;
    Lista* lista = creaLista();
    int val;

    do{
        printf("\nMenu:\n");
        printf("1. Crea Nodo in testa\n");
        printf("2. Crea Nodo in coda\n");
        printf("3. Cerca valore nella lista\n");
        printf("4. Elimina Nodo in testa o coda\n");
        printf("5. Libera Lista e esci\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                creaNodoTesta(lista);
                break;
            case 2:
                creaNodoCoda(lista);
                break;
            case 3:
                printf("Inserisci valore da cercare: ");
                scanf("%d", &val);
                cercaValoreLista(lista, val);
                break;
            case 4:
                eliminaNodoLista(lista);
                break;
            case 5:
                liberaLista(lista);
                lista = creaLista();
                break;
            case 0:
                printf("Uscita dal programma...\n");
                break;
            default:
                printf("Scelta non valida\n");
        }
    } while(scelta != 0);

    liberaLista(lista);
    return 0;
}
