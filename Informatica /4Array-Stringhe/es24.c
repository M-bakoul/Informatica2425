/* CALCOLA LUNGHEZZA STRINGA
 CONTROLLO STRINGHE UGUALI
 COPIARE UNA STRINGA
 CERCARE UN CARATTERE E COMUNICARE FREQUENZA
 CONCATENARE DUE STRINGHE
 RICERCA DI UNA STRINGA NELL'ALTRA
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;

int calcolaLunghezza(string str){

    int lunghezza;
    lunghezza = strlen(str);
    printf("%d", lunghezza);
}




int main(){
    string s1 = NULL;
    string s2 = NULL;
    int len1, len2;
    int scelta;

    printf("Inserisci lunghezza1: ");
    scanf("%d", &len1);
    printf("Inserisci lunghezza2: ");
    scanf("%d", &len2);

    if(len1<0){
        printf("Errore");
        return 1;
    }

    if(len2<0){
        printf("Errore");
        return 1;
    }

    s1=(string)malloc(len1 * sizeof(char));
    s2=(string)malloc(len2 * sizeof(char));

    if(s1==NULL){
        return 1;
    }
    if(s2==NULL){
        return 1;
    }

    printf("Inserisci stringa1: ");
    getchar();
    fgets(s1, len1+1, stdin);
    printf("Inserisci stringa2: ");
    getchar();
    fgets(s2, len2+1, stdin);
    
    printf("1. CALCOLA LUNGHEZZA STRINGA\n");
    printf("2. CONTROLLO STRINGHE UGUALI\n");
    printf("3. COPIARE UNA STRINGA\n");
    printf("4. CERCARE UN CARATTERE E COMUNICARE FREQUENZA\n");
    printf("5. CONCATENARE DUE STRINGHE\n");
    printf("6. RICERCA DI UNA STRINGA NELL'ALTRA\n");

    printf("Scegli: ");
    scanf("%d", &scelta);

    switch (scelta)
    {
    case 1:
        calcolaLunghezza(s1);
        break;
    default:
        break;
    }
}

