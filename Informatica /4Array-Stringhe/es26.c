#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum { false, true } Bool;
void clearBuffer(){
    int c;
    while( c = getchar() != '\n');
}

char* consonanti(char s1[]) {
    char vocali[] = "AEIOU";
    int lenConsonanti = strlen(s1);
    int lenVocali = strlen(vocali);
    char* consonante1 = (char*) malloc(4 * sizeof(char));
    int pos = 0;
    for (int i = 0; i < lenConsonanti && pos < 3; i++) {
        int eVocale = 0;
        for (int j = 0; j < lenVocali; j++) {
            if (s1[i] == vocali[j]) {
                eVocale = 1;
            }
        }
        if (eVocale == 0 && (s1[i] >= 'A' && s1[i] <= 'Z') ) {
            consonante1[pos++] = s1[i];
        }
    }
    consonante1[pos] = '\0';
    return consonante1;
}

char fMese(int mese) {
    char mesi[] = "ABCDEHLMPRST";
    if (mese >= 1 && mese <= 12)
        return mesi[mese - 1];
}

char* fGiorno(char* giorno, Bool maschio_o_femmina) {
    char* giornoOutput;
    if (maschio_o_femmina){
        giornoOutput = malloc(1*sizeof(char));
        for(int i=0; i<2; i++){
            giornoOutput[i]=giorno[i];   
        }
   
        return giornoOutput;
    }else{
        giorno += 40;
        giornoOutput = malloc(2*sizeof(char));
        giornoOutput[0] = giorno[0];
        giornoOutput[1] = giorno[1];
        return giornoOutput;
    }
}

char* fAnno(char* anno) {
    char annoOutput;

    for(int i=2; i<4; i++){
        annoOutput = anno[i];
    } //torna ultime 2 lettere
    return anno;
}


int calcola_lunghezza_stringa(char s[]) {
    int dim = 0;
    while (s[dim] != '\0') dim++;
    return dim;
}

char* concatena_stringhe(char cognomeO[], char nomeO[], char* annoNascitaO, char meseNascitaO, char* giornoNascitaO) {
    char codiceComune[] = "G633";
    char* codiceFinale = (char*) malloc(30 * sizeof(char));

    strcat(codiceFinale, cognomeO);
    strcat(codiceFinale, nomeO);
    strcat(codiceFinale, annoNascitaO);

    char meseStr[2];
    meseStr[0] = meseNascitaO;
    meseStr[1] = '\0';
    strcat(codiceFinale, meseStr);

    strcat(codiceFinale, giornoNascitaO);
    strcat(codiceFinale, codiceComune);
    return codiceFinale;
}

int main(){
    char cognome[30];
    char nome[30];
    char* annoNascita = malloc(4 * sizeof(char));
    int meseNascita;
    char* giornoNascita = malloc (2 * sizeof(char));
    int sesso;

    printf("Inserisci cognome: ");
    scanf("%s", cognome); //
    printf("Inserisci nome: ");
    scanf("%s", nome); //
    printf("Inserisci anno di nascita: ");
    fgets(annoNascita, 4, stdin);
    clearBuffer();
    printf("Inserisci mese di nascita (1-12): ");
    scanf("%d", &meseNascita);
    printf("Inserisci giorno di nascita: ");
    fgets(giornoNascita, 2, stdin);
    clearBuffer();
    printf("Inserisci sesso (0 = femmina / 1 = maschio): ");
    scanf("%d", &sesso);


    char* cognomeO = consonanti(cognome);
    char* nomeO = consonanti(nome);
    char* annoNascitaO = fAnno(annoNascita);
    char meseO = fMese(meseNascita);
    char* giornoO = fGiorno(giornoNascita, (Bool)sesso);

    char* codiceFiscale = concatena_stringhe(cognomeO, nomeO, annoNascitaO, meseO, giornoO);

    printf("\nCodice fiscale: %s\n", codiceFiscale);

    free(cognomeO);
    free(nomeO);
    free(codiceFiscale);


    return 0;
}