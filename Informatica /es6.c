/*  
    Scrivi un programa in C che :
    1.chide all'utente quanti numeri interi vuole inserire;
    2.Alloca dinamicamente un array di quella dimensione con malloc()
    3.Permette all'utente di inserire i numeri;
    4.chiede all'utente se vuole aumentare la dimensionedfell'array
        -sesi , richoedere nuava dimensione realloc() per ridimensionarlo 
        -permettere quindi di inserire i nuovi valori negli spazzi aggiunti
    5.Infine, stampa tutti gli elemnti dell'array
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int *vettore = NULL;
    int n;

    do{
        printf("Inserisci la quantità degli elementi: ");
        scanf("%d", &n);
    }while(n<0);



}