#include <stdio.h>

int main() {
    int vetor[10];
    int i;

    printf("Digite 10 números:\n");

    for(i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < 10; i++) {
        if(vetor[i] < 0) {
            vetor[i] = 0;
        }
    }

    printf("Elementos do vetor após a substituição:\n");

    for(i = 0; i < 10; i++) {
        printf("%d\n", vetor[i]);
    }

    return 0;
}
