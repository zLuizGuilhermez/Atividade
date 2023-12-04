#include <stdio.h>

int main() {
    int vetor[10], vetorImpar[10];
    int i, j = 0, num;

    printf("Digite 10 números inteiros no intervalo [0,50]:\n");

    for(i = 0; i < 10; i++) {
        scanf("%d", &num);
        if(num >= 0 && num <= 50) {
            vetor[i] = num;
            if(num % 2 != 0) {
                vetorImpar[j++] = num;
            }
        } else {
            printf("Número fora do intervalo [0,50]. Tente novamente.\n");
            i--;
        }
    }

    printf("Elementos dos vetores:\n");

    for(i = 0; i < 10; i += 2) {
        printf("%d %d\n", vetor[i], vetor[i+1]);
    }

    for(i = 0; i < j; i += 2) {
        printf("%d %d\n", vetorImpar[i], vetorImpar[i+1]);
    }

    return 0;
}