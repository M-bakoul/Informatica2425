/*  
    Registrare le informazioni di alcuni libri con
    titolo, autore, anno e prezzo.
    Determinare il libro piu costoso e piu vecchio
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Libro{
    char titolo[30];
    char autore[30];
    int anno;
    int prezzo;
}Libro;


void inserisciLibro(Libro** libri, int* dim){
    Libro libro;

    printf("Inserisci titolo: ");
    fgets(libro.titolo, 30, stdin);
    printf("Inserisci autore: ");
    fgets(libro.autore, 30, stdin);
    printf("Inserisci anno: ");
    scanf("%d", &libro.anno);
    getchar();
    printf("Inserisci prezzo: ");
    scanf("%d", &libro.prezzo);


    // libri = realloc(libri, (*dim) * sizeof(Libro));
    // libri[*dim - 1] = libro;
    (*dim)++;
    Libro* temp = realloc(*libri, (*dim) * sizeof(Libro));
    *libri = temp;
    (*libri)[*dim - 1] = libro;
}


void mostraCostoso(Libro* libri, int dim){
    int j=0, i=0;
    int max = libri[0].prezzo;

    while(i<dim){
        if(libri[i].prezzo>max){
            max = libri[i].prezzo;
        }
        i++;
    }

    Libro temp;
    while(j<dim){
        if(libri[j].prezzo == max){
            temp = libri[j];
        }
        j++;
    }

    printf("Libro piu costoso: %s, prezzo: %d", temp.titolo, max);
}

void mostraVecchio(Libro* libri, int dim){
    int j=0, i=0;
    int vecchio = libri[0].anno;

    while(i<dim){
        if(libri[i].anno<vecchio){
            vecchio = libri[i].anno;
        }
        i++;
    }

    Libro temp;
    while(j<dim){
        if(libri[j].anno == vecchio){
            temp = libri[j];
        }
        j++;
    }

    printf("Libro piu vecchio: %s, anno: %d", temp.titolo, vecchio);
}


void mostraLibri(Libro* libri, int dim){
    for(int i=0; i<dim; i++){
        printf("Libro: %s, Autore: %s, Prezzo; %d, Anno: %d", libri[i].titolo, libri[i].autore, libri[i].prezzo, libri[i].anno);
    }
}


int main(){
    int dimLibri = 0;
    Libro* libri = (Libro*)calloc(1 , sizeof(Libro));
    // Libro* prova = calloc(10, sizeof(Libro));
    int scelta;

    do {
        printf("\n--- LIBRERIA ---\n");
        printf("1. Inserisci libro\n");
        printf("2. Mostra libri\n");
        printf("3. Mostra piu costoso\n");
        printf("4. Mostra piu vecchio\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar(); // pulisci buffer input

        switch (scelta) {
            case 1:
                inserisciLibro(&libri, &dimLibri);
                break;
            case 2:
                mostraLibri(libri, dimLibri);
                break;
            case 3:
                mostraCostoso(libri, dimLibri);
                break;
            case 4:
                mostraVecchio(libri, dimLibri);
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }
    } while (scelta != 0);


    return 0;
}