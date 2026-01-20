/*DATA UNA STRINGA TROVARE LA SOTTOSTRINGA*/

#include <stdio.h>
#include <stdlib.h>


int lunghezza(char* s){
    int dim=0;
    while(s[dim]!='\0') dim++;
    
    return dim;
}

int funzione(char* s1, char* s2){
    int dim1=lunghezza(s1);
    int dim2=lunghezza(s2);

    int flag=0;
    int cnt=0;

    for(int i=0; i<dim1-dim2+1; i++){
        if(s1[i] == s2[0]){
            flag = 1;
            for(int j=1; j<dim2; j++){
                if(s1[i+j] != s2[j]){
                    flag = 0;
                    break;
                }
            }
            cnt+= flag;
        }

    }

    printf("%d\n", cnt);

}

int main(){
    int dim;
    int dim_sotto;
    char* s1 = NULL;
    char* s2 = NULL;



    printf("Inserisci dim stringa: ");
    scanf("%d", &dim);

    printf("Inserisci dim sottostringa : ");
    scanf("%d", &dim_sotto);



    s1=(char*)malloc(dim+1 * sizeof(char));
    s2=(char*)malloc(dim_sotto+1 * sizeof(char));



    if(s1 == NULL){
        printf("Errore di allocazione");
    }
    
    if(s2 == NULL){
        printf("Errore di allocazione");
    }


    printf("Inserisci stringa: ");
    getchar();
    fgets(s1, dim+1, stdin);
    printf("Inserisci sottostringa: ");
    getchar();
    fgets(s2, dim_sotto+1, stdin);

    funzione(s1, s2);



}