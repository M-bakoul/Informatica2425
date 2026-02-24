#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


// LISTA
typedef struct Nodo {
    char dato;
    struct Nodo* next;
} Nodo;

typedef struct Pila{
    Nodo* top;
    int lunghezza;
} Pila;


Pila* creaPila(){
    Pila* stack = (Pila*)malloc(sizeof(Pila));
    stack->top = NULL;
    stack->lunghezza = 0;
    return stack;
}

void push(Pila* stack, char valore){
    Nodo* nodo = (Nodo*)malloc(sizeof(Nodo));
    nodo->dato = valore;
    nodo->next = stack->top;
    stack->top = nodo;
    stack->lunghezza++;
}



bool pilaVuota(Pila* stack){
    if(stack->top==NULL){
        return true;
    }else{
        return false;
    }
}

void liberaPila(Pila* stack){
    Nodo* current = stack->top;
    
    while(current != NULL){
        Nodo* speed = current;
        current = current->next;
        free(speed);
    }

    free(stack);
}

char pop(Pila* stack){

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


bool parentesiBalanciate(char* espressione) {
    Pila* pila = creaPila();
    
    for (int i = 0; espressione[i] != '\0'; i++) {
        char c = espressione[i];
        
        // Parentesi di apertura
        if (c == '(' || c == '{' || c == '[') {
            push(pila, c);
        }

        // Parentesi di chiusura
        else if (c == ')' || c == '}' || c == ']') {
            if (pilaVuota(pila)) {
                liberaPila(pila);
                return 0;  // Non bilanciato
            }
            
            int top = pop(pila);
            
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '[')) {
                liberaPila(pila);
                return 0;  // Non bilanciato
            }
        }
    }
    
    bool risultato = pilaVuota(pila);
    liberaPila(pila);
    return risultato;
}




int main(){
    char espressione[30];

    printf("Inserisci espressione: ");
    scanf("%s", &espressione);

    bool r = parentesiBalanciate(espressione);
    printf("%d", r);
}
