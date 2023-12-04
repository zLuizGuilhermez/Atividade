#include <stdio.h>

int main() {
    int vetor[20], vetorFinal[20];
    int i, j, k = 0, repetido;

    printf("Digite 20 números inteiros:\n");

    for(i = 0; i < 20; i++) {
        scanf("%d", &vetor[i]);
    }

    for(i = 0; i < 20; i++) {
        repetido = 0;
        for(j = 0; j < i; j++) {
            if(vetor[i] == vetor[j]) {
                repetido = 1;
                break;
            }
        }
        if(!repetido) {
            vetorFinal[k++] = vetor[i];
        }
    }

    printf("Elementos do vetor sem repetições:\n");

    for(i = 0; i < k; i++) {
        printf("%d\n", vetorFinal[i]);
    }

    return 0;
}
