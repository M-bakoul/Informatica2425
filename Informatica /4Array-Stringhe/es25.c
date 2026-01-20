#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// typedef char* string;

typedef enum {false, true} Bool;

char* consonanti(char s1[]){
    char vocali[] = "AEIOU";
    int lenConsonanti= strlen(s1);
    int lenVocali= strlen(vocali);
    char consonante1[3];


    for(int i=0; i<lenConsonanti; i++){
        for(int j=0; j<lenVocali){
            if(s1[i] =! vocali[j])
            for(int k=0; k<3; k++){
                consonante1[k] = s1[i];
            }
        }
    }
    
    // printf("%s", consonante1);
    return consonante1;
}


/*
void fCognome(char cognome){
    consonanti(cognome);
}

void fNome(char nome){
    consonanti(nome);
}

*/


char* fMese(int mese[]){
    char mesi[] = "ABCDEHLMPRST";
    if(mese>= 1 && mese<= 12){
        return mesi[mese - 1];
    }
}

int* fGiorno(int giorno, Bool maschio_o_femmina){
    
    // printf("M o F ? \n");
    // scanf("%d", &c);
    int dim = 0;
    if(maschio_o_femmina){ //maschio
        return giorno;
    }else(maschio_o_femmina == false){; //femmina
        return giorno +=40;
    }
}


int* fAnno(int anno[]){
    for(int i = 2; i<4; i++){
        return anno[i];
    }
}

int calcola_lunghezza_stringa(char s){
    int dim=0;
    while(s[dim]!='\0') dim++;
    
    return dim;
}

char* concatena_stringhe(char cognomeO[], char nomeO[], int annoNascitaO[], int meseNascitaO, int giornoNascitaO[]){
    int dimCognome = calcola_lunghezza_stringa(cognomeO);
    int dimNome = calcola_lunghezza_stringa(nomeO);
    int dimAnnoNascita = 2;
    int dimMeseNascita = 1;
    int dimGiornoNascita = 0;
    char codiceComune[] = "G186";
    char codiceFinale[30];

    for(int i=0; giornoNascitaO[i] != NULL; i++){
        dimGiornoNascita++;
    }

    for(int i=0; i<dimCognome; i++){
        codiceFinale=cognomeO[i];
    }
    for(int i=0; i<dimNome; i++){
        codiceFinale+=nomeO[i];
    }
    for(int i=0; i<dimAnnoNascita; i++){
        codiceFinale+=annoNascitaO[i];
    }
    for(int i=0; i<dimMeseNascita; i++){
        codiceFinale+=meseNascitaO[i];
    }
    for(int i=0; i<dimGiornoNascita; i++){
        codiceFinale=giornoNascitaO[i];
    }
    codiceFinale+=codiceComune;

    return codiceFinale;
}

int main(){

    // input
    char cognome[30];
    char nome[30];
    int annoNascita[4];
    int meseNascita[2];
    int giornoNascita[2];
    char sesso;

    char codiceFiscale[17];



    printf("inserisci cognome: ");
    scanf("%s", &cognome);
    printf("inserisci nome: ");
    scanf("%s", &nome);
    printf("inserisci anno di nascita: ");
    scanf("%d", &annoNascita);
    printf("inserisci mese di nascita: ");
    scanf("%d", &meseNascita);
    printf("Insereisci sesso (0 = femmina / 1 = Maschio): ");
    scanf("%c", &sesso);


    char cognomeO = consonanti(cognome);
    char nomeO = consonanti(nome);
    int annoNascitaO = fAnno(annoNascita);
    int meseO = fMese(meseNascita);
    int giornoO = fGiorno(giornoNascita, sesso);

    codiceFiscale = concatena_stringhe(cognomeO, nomeO, annoNascitaO, meseO, giornoO);
}