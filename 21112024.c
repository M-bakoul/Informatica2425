#include <stdio.h>

int main(){
    int num;
    int somma;
    
    somma=(1000/10) % 10+
          (100/10) % 10+
          (10/10) % 10+
           10 % 10;
        
    if(somma%3 == 0){
        printf("Il numero e divisibile per 3");
    }else
        printf("Il numero non e divisibile per 3");
        
    return 0;
    
    }