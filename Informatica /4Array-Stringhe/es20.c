/*
 trasforma caratteri da minuscolo a maiuscolo
 o viceversa 
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char* string;
typedef enum {true, false} Bool;

void MaiMin_o_MinMax(string str, Bool maiusc_to_minusc){
    if(maiusc_to_minusc == true){
        for(int i=0; str[i] != '\0'; i++){
            if(str[i]>=65 && str[i] <= 90){
                str[i]+=32;
            }
        }
        printf("%s", str);

    }else {
        for(int j=0; str[j] != '\0'; j++){
            if(str[j]>=97 && str[j] <= 122){
                str[j]-=32;
            }
        }
        printf("%s", str);

    }
}
    
int main(){
    string str=NULL;
    int len;
    int scelta;

    printf("Inserisci la lunghezza: ");
    scanf("%d", &len);

    if(len<0){
        printf("errore");
        return 0;
    }

    str=(string)malloc((len+1) * sizeof (char));
    if(str==NULL){
        return 1;
    }


    printf("Inserisci stringa: ");
    getchar();
    fgets(str, len+1, stdin);

    printf("Vuoi da MaiMin 1 o MinMai 2: ");
    scanf("%d", &scelta);

    if (scelta == 1){
        MaiMin_o_MinMax(str, true);
    } else (scelta == 2){
        MaiMin_o_MinMax(str, false);
    }

    free(str);

}