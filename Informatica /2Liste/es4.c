/* Spotify, crea playlist con lista circolare */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Canzone{
    char titolo[30];
    char artista[30];
    int durataCanzone;
    int id;
    char like;
    struct Canzone* next;
    struct Canzone* prev;
}Canzone;

typedef struct Lista{
    Canzone* head;
    int lunghezza;
}Lista;


Lista* crea_lista(){
    Lista* lista = (Lista*)malloc(sizeof(Lista));
    lista->head = NULL;
    lista->lunghezza = 0;
    return lista;
}

void set_canzone(Canzone *c){
    printf("Inserisci titolo: ");
    fgets(c->titolo, 9, stdin);
    printf("Inserisci artista: ");
    fgets(c->artista, 9, stdin);
    printf("Inserisci durata della canzone: ");
    scanf("%d", &c->durataCanzone);
    getchar();
    printf("Voui mettere like?: ");
    scanf("%c", &c->like);
}

void stampa_lista(Lista* lista){
    Canzone* temp = lista->head;
    int i = 1;
    while(temp!=NULL){
        printf("\n=== CANZONE %i ===\n", i);
        printf("CANZONE: titolo: %s, artista: %s, durata della canzone: %ds , ID: %d\n", temp->titolo, temp->artista, temp->durataCanzone, temp->id);
        temp = temp->next;
        i++;
    }
}

void inserisci_canzone(Lista* lista){
    Canzone* canzone=(Canzone*)malloc(sizeof(Canzone));
    Canzone* temp1 = lista->head;
    int i=0;

    if(canzone == NULL) {
        printf("Errore di allocazione");
        exit(1);
    }

    canzone->next = NULL;

    set_canzone(canzone);

    if(lista->head==NULL){
        lista->head=canzone;
        lista->lunghezza++;
        canzone->id = 0;
    }else {
        Canzone* temp = lista->head;
        lista->head = canzone;
        canzone->next=temp;
        canzone->id= lista->lunghezza-1;
    }
    lista->lunghezza++;
    
}

void stampaCanzone(Canzone* c){
    printf("titolo: %s\n", c->titolo);
    printf("artista: %s\n", c->artista);
    printf("Durata della canzone: %ds\n", c->durataCanzone);
    printf("ID canzone: %d\n", c->id);
}

void ricerca_canzone_artista(Lista *lista, char* artista){
    Canzone* temp = lista->head;

    if(lista->head==NULL){
        printf("Lista vuota");
        return;
    }

    if(strcmp(temp->artista, artista) == 0){
        printf("\nartista: %s, titolo: %s, durata canzone: %d s, ID: %d", temp->artista, temp->titolo, temp->durataCanzone, temp->id);
        temp = temp->next;
    }

    // non funzionava cosi perche se la pima canzone viene trovata
    // canatata dall artista poi non cercava le altre
    /*else{
        while(temp->next != NULL){
            if(strcmp(temp->artista, artista) == 0){
                printf("artista: %s, titolo: %s, durata canzone: %d s, ID: %d", temp->artista, temp->titolo, temp->durataCanzone, temp->id);
            }
            temp = temp->next;
        }
    }
        */


    // cosi funziona anche per le canzoni dopo
    do{
        if(strcmp(temp->artista, artista) == 0){
            printf("artista: %s, titolo: %s, durata canzone: %d s, ID: %d", temp->artista, temp->titolo, temp->durataCanzone, temp->id);
        }
        temp = temp->next;
    }while(temp != NULL);

}

void libera_memoria(Lista* lista){
    Canzone* temp = lista->head;

    if(lista->head==NULL){
        printf("Lista vuota");
        return;
    }
    
    while(temp != NULL){
        Canzone* current = temp->next;
        free(temp);
        temp = current;
    }
    lista->head = NULL;
}

Lista* crea_playlist(){
    Lista* playlist = (Lista*)malloc(sizeof(Lista));
    playlist->head = NULL;
    playlist->lunghezza = 0;
    return playlist;
}

void inserisci_canzone_playlist(Lista *lista, Lista *playlist){
    int id1;
    printf("Inserisci ID della canzone che vuoi inserire: ");
    scanf("%d", &id1);
    getchar();


    if(lista->head==NULL){
        printf("Lista vuota");
        return;
    }

/* all inizio ho fatto questo algoritmo che cerca nella lista_canzoni
l id che cerchiamo basandosi su un if e else (che si basano il primo
se id e al primo nodo il secondo l else si basa sul secondo in poi),
l'if conteneva un altro if else e qua entra la playlist, il primo 
l 1if controllava se la playlist era vuota e lo aggiungeva, l else
lo aggiungeva in coda alla playlist. Poi l ultimo else conteneva
lo stesso procedimento, cambiava solo che l id che cerchiamo e dopo
il primo nodo(2+) quindi lo scorreva tutto.


    if(temp->id == id1){
        if(playlist->head == NULL){
            playlist->head = current;
            playlist->lunghezza++;
        }else{
            Canzone* temp1 = playlist->head;
            while(temp1->next != playlist->head){
                temp1 = temp1->next; 
            }
            temp1 = temp;
            playlist->lunghezza++;
        }
    }else{
        while(temp->next != NULL){
            if(temp->id == id1){
                if(playlist->head == NULL){
                    playlist->head = current;
                    playlist->lunghezza++;
                }else{
                    Canzone* temp1 = playlist->head;
                    while(temp1->next != playlist->head){
                        temp1 = temp1->next;
                    }
                    temp1 = temp;
                    playlist->lunghezza++;
                }
                temp = temp->next
            }
        }
    }
    */

    Canzone* temp = lista->head; 
    while(temp != NULL){
        if(temp->id == id1){
            Canzone* current = (Canzone*)malloc(sizeof(Canzone));
            *current = *temp;
            if(playlist->head == NULL){
                playlist->head = current;
                current->next = playlist->head;
                current->prev = playlist->head;
                playlist->lunghezza++;
            }else{
                Canzone* speed = playlist->head;
                while(speed->next != playlist->head){
                    speed=speed->next;
                }
                speed->next = current;
                current->next = playlist->head;
                current->prev = speed;
                playlist->head->prev = current;
                playlist->lunghezza++;
            }
        }
        temp = temp->next;
    }
    

}

void stampa_playlist(Lista* playlist){
    if(playlist->head==NULL){
        printf("Lista vuota");
        return;
    }
    
    // si puo stampare in 2 modi
    // codi classico

    /*
    Canzone* temp = playlist->head;

    printf("Playlist: \nID: %d, titolo: %s, artista %s, durata canzone %d", temp->id, temp->titolo, temp->artista, temp->durataCanzone);
    while(temp->next != playlist->head){
        printf("\nID: %d, titolo: %s, artista: %s, durata canzone %d", temp->next->id, temp->next->titolo, temp->next->artista, temp->next->durataCanzone);
        temp = temp->next;
    }
        
*/

    // o anche da destra verso sinistra

    
    Canzone* current = playlist->head->prev;

    printf("Playlist: \nID: %d, titolo: %s, artista %s, durata canzone %d", current->id, current->titolo, current->artista, current->durataCanzone);
    while(current->prev != playlist->head->prev){
        printf("\nID: %d, titolo: %s, artista: %s, durata canzone %d", current->prev->id, current->prev->titolo, current->prev->artista, current->prev->durataCanzone);
        current = current->prev;
    } 
        
   
}

void cancella_canzone_playlist(Lista *playlist){
    int id1;
    Canzone* temp = playlist->head;

    printf("Inserisci ID della canzone che vuoi eliminare: ");
    scanf("%d", &id1);

    if(temp==NULL){
        printf("Lista vuota");
        return;
    }

    if(temp->id == id1){ //caso primo nodo della lista || temp id == id che cerchiamo
        if(temp->next == playlist->head){ // caso 1 solo nodo; ci sono 2 casi visto che e circolare quindi l ultimo nodo deve puntare all head 
            free(temp);
            playlist->head = NULL;
            playlist->lunghezza--;
        }else{ // ci sono 2+ nodi
            // e circolare quindi l ultimo nodo deve puntare al pimo
            // ma se tolgo il pimo deve puntare al secondo quindi:

            Canzone* i = playlist->head;
            while(i->next != playlist->head){
                i = i->next; //trovo ultimo nodo
            }
            i->next = temp->next;//ultimo nodo punta al secondo
            playlist->head = temp->next;// aggiorno l head
            free(temp);
            playlist->lunghezza--;
        }
    }else{
        while(temp->next != playlist->head){
            if(temp->next->id == id1){
                Canzone* i = temp->next;
                temp->next = temp->next->next;
                free(i);
                playlist->lunghezza--;
                return;
            }
            temp = temp->next;
        }
    }
}


void ascolta_playlist(Lista* playlist){
    if(playlist->head==NULL){
        printf("Lista vuota");
        return;
    }
    
    Canzone* temp = playlist->head;

    printf("Playlist: \n\nID: %d, titolo: %s, artista %s, durata canzone %d", temp->id, temp->titolo, temp->artista, temp->durataCanzone);
    while(temp->next != playlist->head){
        printf("\nID: %d, titolo: %s, artista: %s, durata canzone %d", temp->next->id, temp->next->titolo, temp->next->artista, temp->next->durataCanzone);
        temp = temp->next;
    }

    char scelta;

    do{
        printf("Vuoi contunare ad ascoltare? (s/n)");
        scanf("%c", &scelta);
        getchar();

        if(scelta == 's'){
            printf("Playlist: \nID: %d, titolo: %s, artista %s, durata canzone %d", temp->next->id, temp->next->titolo, temp->next->artista, temp->next->durataCanzone);
        }else{
            return;
        }
        temp = temp->next;

    }while(scelta == 's');
}

void stampa_like(Lista* lista_canzoni){
    Canzone* current = lista_canzoni->head;

    printf("Canzoni a cui hai messo like: \n");
    while(current != NULL){
        if(current->like == 's'){
            printf("titolo: %s\n", current->titolo);
            printf("artista: %s\n", current->artista);
            printf("Durata della canzone: %ds\n", current->durataCanzone);
            printf("ID canzone: %d\n", current->id);
        }

        current = current->next;
    }
}



int main(){
    int scelta;
    Lista* lista_canzoni = crea_lista();
    Lista* playlist = crea_playlist();
    char artista[50];

    do {
        printf("\n--- SPOTIFY ---\n");
        printf("1. Inserisci nuova canzone nella lista\n");
        printf("2. Stampa lista canzoni\n");
        printf("3. Cerca canzoni per artista\n");
        printf("4. Canzoni con like\n");
        printf("5. Aggiungi canzone alla playlist\n");
        printf("6. Stampa playlist\n");
        printf("7. Cancella canzone dalla playlist\n");
        printf("8. Ascolta playlist\n");
        printf("0. Esci\n");
        printf("Scelta: ");
        scanf("%d", &scelta);
        getchar(); // pulisci buffer input

        switch (scelta) {
            case 1:
                inserisci_canzone(lista_canzoni);
                break;
            case 2:
                stampa_lista(lista_canzoni);
                break;
            case 3:
                printf("Inserisci artista da cercare: ");
                fgets(artista, 50, stdin);
                ricerca_canzone_artista(lista_canzoni, artista);
                break;
            case 4:
                stampa_like(lista_canzoni);
                break;
            case 5:
                inserisci_canzone_playlist(lista_canzoni, playlist);
                break;
            case 6:
                stampa_playlist(playlist);
                break;
            case 7:
                cancella_canzone_playlist(playlist);
                break;
            case 8:
                ascolta_playlist(playlist);
                break;
            case 0:
                printf("Uscita...\n");
                break;
            default:
                printf("Scelta non valida. Riprova.\n");
        }

    } while (scelta != 0);

    libera_memoria(lista_canzoni);
    libera_memoria(playlist);

    return 0;
}

