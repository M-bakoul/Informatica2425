/* 
CASA 
CIAO
CCAISAAO
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

int main(){
    string s1 = NULL;
    string s2 = NULL;

    string s3 = NULL;

    int dim1, dim2;

    printf("Inserisci dim s1: ");
    scanf("%d", &dim1);
    printf("Inserisci dim s2: ");
    scanf("%d", &dim2);

    s1 = (string)malloc(dim1+1 * sizeof(char));
    s2 = (string)malloc(dim2+1 * sizeof(char));

    printf("Inserisci stringa1: ");
    getchar();
    fgets(s1, dim1+1, stdin);

    printf("Inserisci stringa2: ");
    getchar();
    fgets(s2, dim2+1, stdin);

    s3 = (string)malloc((dim1+dim2+1) * sizeof(char));


    int dim3 = dim1+dim2;

    int i=0, j=0, k=0;


    while(s1[i] != '\0' && s2[j] != '\0'){
        s3[k] = s1[i];
        k++;
        i++;
        s3[k]=s2[j];
        k++;
        j++;
    }


    while(s1[j] != '\0'){
        s3[k] = s1[i]; 
        k++;
        i++;
    }


    while(s2[j] != '\0'){
        s3[k] = s2[j]; 
        k++;
        j++;
    }

    s3[k] = '0';

    printf("Risultato: %s", s3);
}