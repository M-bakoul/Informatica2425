/* DATA UNA STRINGA SCRIVILA AL CONTRARIO*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

char* funzione(char* s1, int dim){

    char* s2 = (char*) malloc(dim* sizeof(char));

    for(int k=0; k<dim; k++){
        s2[k] = s1[k];
    }

    for(int i=0; i<dim; i++){
        s1[i] = s2[dim - 1 - i];
    }
    s1[dim] = '\0';


    // 0 1 2 3 4 
    // 4 3 2 1 0
    // 
    

    return s1;
}

int main(){
    int dim;
    string s1 = NULL;


    printf("Inserisci dim stringa: ");
    scanf("%d", &dim);


    s1=(string)malloc(dim+1 * sizeof(char));


    if(s1 == NULL){
        printf("Errore di allocazione");
    }


    printf("Inserisci stringa: ");
    getchar();
    fgets(s1, dim+1, stdin);

    funzione(s1, dim);

    printf("%s", s1);

}