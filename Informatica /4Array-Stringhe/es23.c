/* Verificare se una stringa è palindroma */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

int lunghezza(string s){
    int i=0;
    while(s[i]!='\0'){
        i++;
    }
    return i-1;
}

int Palindroma(string s, int len){
    int flag=0, i, j;

    for(i=0; j=dim-1; i<dim/2; i++, j--){
        if(s[i] != s[j])
            flag=1;
    }return flag;

}

int main(){
    int dim=0;
    

    string s = (string)malloc(sizeof(50) * sizeof(char));
    printf("Inserisci una stringa");
    fgets(s, 50, stdin);
    printf("\n%s", s);
    dim=lunghezza(s);
    printf("\n%d", dim);
    palindroma= Palindroma(s, palindroma);

}