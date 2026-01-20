#include <stdio.h>
#include <stdlib.h>

int main(){
    char *stringa;
    int n;
    char lettera='a';


    do{
        printf("Inserisci un numero: ");
        scanf("%d", &n);
    }while(n<=0 || n>26);

    stringa=(char *)malloc((n+1)*sizeof(char));

    for(int i=0; i<n; i++){
        stringa[i]=lettera++;
        
    }
    
    stringa[n]='\0';
    printf("%s", stringa);
}