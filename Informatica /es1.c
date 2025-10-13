/*Data una matrice di valori scambiare gli 
elementi della diagonale principale con la diagonale secondaria.*/


#include <stdio.h>
#define N 3  


void scambia(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        int temp = M[i][i];
        M[i][i] = M[i][N - 1 - i];
        M[i][N - 1 - i] = temp;
    }
}


void stampaMatrice(int M[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main() {
    
    int M[N][N] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    printf("Matrice originale:\n");
    stampaMatrice(M);

    scambia(M);

    printf("Matrice dopo lo scambio delle diagonali:\n");
    stampaMatrice(M);

    return 0;
}