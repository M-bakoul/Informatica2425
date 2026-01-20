/*Scrivere un programma in C che gestisca un insieme di numeri interi
usando un array dinamico.

Il programma deve permettere, tramite menù:
    1. Aggiungere un numero (espandendo l’array con realloc)
    2. Visualizzare tutti i numeri
    3. Cercare un numero specifico
    4. Ordinare i numeri in ordine crescente
    5. Eliminare un numero scelto
    6. Uscire
*/

int main(){
    int *numeri = NULL;
    int dimensione=0;
    int scelta, i;

    do{
        printf("\n -MENU- \n");  
        printf("1. Aggiungere un numero (espandendo l’array con realloc)\n");
        printf("2. Visualizzare tutti i numeri \n");
        printf("3. Cercare un numero specifico \n");
        printf("4. Ordinare i numeri in ordine crescente\n");
        printf("5. Eliminare un numero scelto \n");
        printf("6. Uscire \n");
        scanf("%d", &scelta);

        switch(scelta){
            case 1:
                printf("numero da inserire: ");
                scanf("%d", &n);
                numeri=(int *)realloc(numeri, (dimensione+1)*sizeof(int));
                if(numeri=NULL){
                    printf("errore di allocazione\n");
                    return 1;
                }
                numeri[dimensione]= n;
                dimensione++;
                printf("numero aggiunto\n");

            break;

        }

    }while(scelta !=6);
}