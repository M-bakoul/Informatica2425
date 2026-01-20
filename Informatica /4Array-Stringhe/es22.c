/* Eliminare gli spazi da una stringa */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef char* string;

void compatta(string buffer, int len){

    if(len>0 && buffer[len-1]=='\n'){
        buffer[len-1] = '\0';
        len--;                     
    }
}

void eliminaSpazi(string frase){
        

}
    
    


int main(){
    string frase=NULL;
    char buffer[200];
    printf("Inserisci una stringa: ");
    fgets(buffer, sizeof(buffer), stdin);
    int len = strlen(buffer);
    compatta(buffer, len);
    frase=(String)malloc((len+1)*sizeof(char));
    if(frase==NULL){
        printf("C'è un errore\n");
        return 1;
    }

    eliminaSpazi(frase);
    printf("%s", frase);



    free(frase);
    return 0;

}


    
