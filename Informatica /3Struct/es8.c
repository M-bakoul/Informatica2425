/* Classe di studenti
    Cognome, Nome, classe, matricola
    Per ogni studente dotato di matricola abbiamo
    le informazioni riguardante gli esami e il livello raggiunto
    1) ricercare lo studente con piu certificazioni
*/

typedef struct Studente{
    char nome[20];
    char cognome[20];
    char classe[3];
    int matricola; // 1000 - 9999
}Studente;

typedef struct Certificazioni{
    int matricola;
    struct esame{
        char corso[20];
        int livello; // (1-3)
    }
}Certificazioni;

void creaStudente(Studente* studenti, int* dim){
    Studente* nuovoStudente = (Studente*)malloc(sizeof(Studente));
    printf("Inserisci nome: ");
    fgets(nuovoStudente->nome, 20, stdin);
    printf("Inserisci cognome: ");
    fgets(nuovoStudente->cognome, 20, stdin);
    printf("Inserisci classe: ");
    fgets(nuovoStudente->classe, 3, stdin);
    
    if(dim == 0){
        nuovoStudente->matricola = 1000;
    }else{
        int i=0;
        while(i!=dim){
            i++;
        }
        int num1 = studenti[i]->matricola;
        nuovoStudente->matricola = num1++;
    }

    studenti[*dim] = nuovoStudente;
    (*dim)++;
}

void stampaMatricola(S* studenti, int dim) {
    for (int i = 0; i < dim; i++) {
            printf("Studente %s: matricola:%d \n", studenti[i].nome , studenti[i].matricola);
    }
}

int main(){
    Studente* Studenti = (Studente*)malloc(30 * sizeof(Studente));
    int dimStudenti = 0;
    int scelta;

    do {
        printf("\n--- Menu ---\n");
        printf("1. Inserisci nuovo studente: \n");
        printf("2. Stampa studente: \n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar();

        switch (scelta) {
            case 1:
                if (dimSquadre < 30) {
                    aggiungiStudente(Studenti, &dimStudenti);
                } else {
                    printf("Hai superato 30 studenti \n");
                }
                break;
            case 2:
                stampaMatricola(Studenti);
                break;
            case 0:
                printf("Uscita...\n");
                break;

            default:
                break;
        }
    } while (scelta != 0);

    return 0;
}