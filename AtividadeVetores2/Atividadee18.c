#include <stdio.h>

int main() {
    int vetor[10], n, i, cont = 0;

    printf("Digite 10 números:\n");

    for(i = 0; i < 10; i++) {
        scanf("%d", &vetor[i]);
    }

    printf("Digite um número n:\n");
    scanf("%d", &n);

    for(i = 0; i < 10; i++) {
        if(vetor[i] % n == 0) {
            cont++;
        }
    }

    printf("Existem %d múltiplos de %d no vetor.\n", cont, n);

    return 0;
}
