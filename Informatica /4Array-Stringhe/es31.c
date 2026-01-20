#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

int main(){
    int dim = 200;
    string s1 = NULL;
    int scelta;

    string = (string)malloc(dim * sizeof(char));

    if(s1 == NULL){
        printf("Errore di allocazione");
        return 1;
    }

    printf("Inserisci stringa: ");
    fgets(s1, dim+1, stdin);


    do{
        printf(" ----PROGRAMMA----");
        printf("1. Conta parole nella stringa. ");
        scanf("%d", &scelta);


        switch (scelta)
        {
        case 1:
            
            break;
        
        default:
            break;
        }
    }while(scelta != 5)

    
}

int contaParole(string s1, int dim){
    int i;
    int cont = 0;
    string parola;
    
    for(i=0; i<dim; i++){
        if(s1[i] == ' '){
            if(s1[i+1] != ' '){
                cont++;
            }
        }
    }
}

string parolaLunga(string s1, int dim){
    int i;
    int cont = 0;
    int grande;
    string parola;
    
    for(i=0; i<dim; i++){
        if(s1[i] == ' '){
            if(s1[i+1] != ' '){
                while(s1[i+1] != ' '){
                    grande++;
                    if()
                }
            }
        }
    }
}

int contaOccorrenze(string s1, int dim){
    string s2 = NULL;
    int dim2 = 30;
    int cnt;

    s2 = (string)malloc(dim2 * sizeof(char));
    
    printf("Inserisci s2: ");
    fgets(s2, dim+1; stdin);

    for(int i=0; i<dim; i++){
        if(s2[i] == s1[i]){
            for(int j=0; j<dim2; j++){
                while(s2[j] != s1[i]){
                    cnt++;
                }
            }
        }
    }

    if(cnt < dim2-1){
        printf("Non ci sono occorrenze");
    }
}