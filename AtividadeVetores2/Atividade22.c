#include <stdio.h>

int main() {
    int vetor1[10], vetor2[10], vetorResultante[20];
    int i;

    printf("Digite 10 números para o primeiro vetor:\n");

    for(i = 0; i < 10; i++) {
        scanf("%d", &vetor1[i]);
    }

    printf("Digite 10 números para o segundo vetor:\n");

    for(i = 0; i < 10; i++) {
        scanf("%d", &vetor2[i]);
    }

    for(i = 0; i < 10; i++) {
        vetorResultante[2*i] = vetor1[i];
        vetorResultante[2*i+1] = vetor2[i];
    }

    printf("Elementos do vetor resultante:\n");

    for(i = 0; i < 20; i++) {
        printf("%d\n", vetorResultante[i]);
    }

    return 0;
}
