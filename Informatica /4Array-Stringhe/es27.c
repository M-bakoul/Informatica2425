#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

int main(){
    int dim, i=0;
    string s1 = NULL;
    string password = NULL;
    int fatt_cifratura;
    int scelta;
    int confronta;
    int cnt_p = 0;


    printf("Inserisci dim password: \n");
    scanf("%d", &dim);

    s1=(string)malloc(dim+1 * sizeof(char));

    if(s1 == NULL){
        printf("Errore di allocazione");
    }

    printf("Insersci password: ");
    getchar();
    fgets(s1, dim+1, stdin);

    printf("Inserisci fattore di cifratura: ");
    scanf("%d", &fatt_cifratura);

    for(int i=0; i<dim; i++){
        s1[i] += fatt_cifratura;
        if(s1[i] > 122){
            cnt_p= s1[i]-122;
            s1[i] = 'a';
            s1[i] += cnt_p;
        }
    }

    printf("%s\n", s1);


    password = (string) malloc (dim+1 * sizeof(char));

    if(password == NULL){
        printf("Errore di allocazione");
    }

    for(int i=0; i<dim; i++){
        s1[i] -= fatt_cifratura;
        if(s1[i] < 97){
            cnt_p= 97 - s1[i];
            s1[i] = 'z';
            s1[i] -= cnt_p;
        }
    }

    printf("Inserisci la password per accedere: ");
    getchar();
    fgets(password, dim+1, stdin);

    
    confronta = strcmp(password, s1);

    if ( confronta == 0 )
      printf( "Password corretta" );
    else
      printf( "Password sbagliata" );

}
    