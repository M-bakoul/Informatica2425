#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int dato;
    struct Nodo* next;
} Nodo;

typedef struct Stack{
    Nodo* top;
    int lunghezza;
} Stack;

// crea stack
// push / inserimento in cima
// pop / estrazione dalla cima
// peek / visualizazione dell elemento in cima
// stampaPila
// libera pila

void liberaStack(Stack* stack){
    Nodo* current = stack->top;
    
    while(current != NULL){
        Nodo* speed = current;
        current = current->next;
        free(speed);
    }

    free(stack);
}

void stampaStack(Stack* stack){
    Nodo* current = stack->top;
    int i=0;

    while(current != NULL){
        printf("nodo: %d, dato: %d\n", i+1, current->dato);
        current= current->next;
        i++;
    }
}

int peek(Stack* stack){
    if(stack->top == NULL){
        printf("Lista vuota");
        return -1;
    }

    return stack->top->dato;
}

int pop(Stack* stack){

    if(stack->top== NULL){
        printf("Lista vuota");
        return -1;
    }

    int valore = stack->top->dato;

    Nodo* current = stack->top;
    stack->top = stack->top->next;
    free(current);
    stack->lunghezza--;

    return valore;
}

void push(Stack* stack){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    printf("Inserisci dato: ");
    scanf("%d", &nodo->dato);

    nodo->next = stack->top;
    stack->top = nodo;
    stack->lunghezza++;
}

Stack* crea_stack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    
    stack->top = NULL;
    stack->lunghezza = 0;
    return stack;
}


int main(){
    Stack* stack = crea_stack();
    int scelta;

    do{
        printf("\n--- STACK ---\n");
        printf("1. Inserisci nodo nello stack\n");
        printf("2. Elimina e ritorna ultimo nodo dello stack\n");
        printf("3. Mostra primo nodo\n");
        printf("4. Stampa intero stack\n");
        printf("0. Esci ed elimina intero stack\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                push(stack);
                break;
            case 2:
                int l;
                l = pop(stack);
                printf("%d", l);
                break;
            case 3:
                int x;
                x = peek(stack);
                printf("%d", x);
                break;
            case 4: 
                stampaStack(stack);
                break;
            case 0:
                printf("Uscita...");
                liberaStack(stack);
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
                break;
        }
    }while(scelta != 0);
}