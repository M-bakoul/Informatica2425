/* Scrivi un  programma in C che gestisca un insieme di numeri interi
usano un array dinamico.
Il programma deve permettere, tramite menu:
1. Aggiungere un numero (espandendo l'array con realloc)
2. Visualizzare tutti i numeri
3. Cercare un numero specifico 
4. Ordinare i numeri in ordine creascente
5. Eliminare un numero scelto
6. Uscire
*/


#include <stdio.h>
#include <stdlib.h>



int* creaVett(int _n){

    int *_vettore = (int*)malloc(_n *sizeof(int));

    if(_vettore==NULL){
        printf("Errore di allocazione!\n");
        return 1;
    }
    return _vettore;
}

int* inserisciValori(int *_vettore, int _n){

    for(int i=0; i<_n; i++){
        printf("Inserisci l'elemento: ");
        scanf("%d", &_vettore[i]);
    }
    return _vettore;
}

void stampaVett(int *_vettore, int _n){
    printf("Hai inserito i seguenti elementi: ");
    for(int i=0; i<_n; i++);
    {
        printf("%d", _vettore);
    }
}

void calcola(int *_vettore, int _n){
    for (int i=0; i<_n; i++){
        if (_vettore[i]%3){
            printf("il vettore e divisibile per 3");
        }else {
            printf("non è divisibile per 3");
        }
    }
}

int main(){
    int *vettore = NULL; //puntatore al vettore
    int n;

    do{
        printf("Inserisci la quantità degli elementi: ");
        scanf("%d", &n);
    }while(n<0);

    vettore = creaVett(n);
    vettore = inserisciValori(vettore, n);
    stampaVett(vettore, n);

}