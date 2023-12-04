#include <stdio.h>

int main() {
    float vetor[6];
    int codigo, i;

    printf("Digite 6 números reais:\n");

    for(i = 0; i < 6; i++) {
        scanf("%f", &vetor[i]);
    }

    printf("Digite um código (1 ou 2):\n");
    scanf("%d", &codigo);

    switch(codigo) {
        case 1:
            printf("Vetor na ordem direta:\n");
            for(i = 0; i < 6; i++) {
                printf("%.2f\n", vetor[i]);
            }
            break;
        case 2:
            printf("Vetor na ordem inversa:\n");
            for(i = 5; i >= 0; i--) {
                printf("%.2f\n", vetor[i]);
            }
            break;
        default:
            printf("Código inválido.\n");
    }

    return 0;
}
