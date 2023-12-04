#include <stdio.h>

int main() {
    float vetor1[5], vetor2[5], produtoEscalar = 0;
    int i;

    printf("Digite 5 números reais para o primeiro conjunto:\n");

    for(i = 0; i < 5; i++) {
        scanf("%f", &vetor1[i]);
    }

    printf("Digite 5 números reais para o segundo conjunto:\n");

    for(i = 0; i < 5; i++) {
        scanf("%f", &vetor2[i]);
    }

    printf("Calculando o produto escalar:\n");

    for(i = 0; i < 5; i++) {
        produtoEscalar += vetor1[i] * vetor2[i];
    }

    printf("Elementos do primeiro conjunto:\n");

    for(i = 0; i < 5; i++) {
        printf("%.2f\n", vetor1[i]);
    }

    printf("Elementos do segundo conjunto:\n");

    for(i = 0; i < 5; i++) {
        printf("%.2f\n", vetor2[i]);
    }

    printf("Produto escalar: %.2f\n", produtoEscalar);

    return 0;
}
