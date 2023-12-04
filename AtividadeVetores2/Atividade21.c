#include <stdio.h>

int main() {
    int vetorA[10], vetorB[10], vetorC[10];
    int i;

    printf("Digite 10 números para o vetor A:\n");

    for(i = 0; i < 10; i++) {
        scanf("%d", &vetorA[i]);
    }

    printf("Digite 10 números para o vetor B:\n");

    for(i = 0; i < 10; i++) {
        scanf("%d", &vetorB[i]);
    }

    printf("Calculando o vetor C como A - B:\n");

    for(i = 0; i < 10; i++) {
        vetorC[i] = vetorA[i] - vetorB[i];
    }

    printf("Elementos do vetor C:\n");

    for(i = 0; i < 10; i++) {
        printf("%d\n", vetorC[i]);
    }

    return 0;
}
