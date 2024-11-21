#include <stdio.h>

int main(){
    int num;
    int somma;
    
    printf("Inserisci un numero");
    scanf("%d", &num);
    
    somma=(num / 1000) % 10+
          (num / 100) % 10+
          (num / 10) % 10+
           num % 10;
        
    if(somma%3 == 0){
        printf("Il numero e divisibile per 3");
    }else
        printf("Il numero non e divisibile per 3");
        
    return 0;
    
    }