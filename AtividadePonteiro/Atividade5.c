#include <stdio.h>

void encontrarExtremos(int *maior, int *menor) {
    int num1, num2;

    printf("Digite dois numeros inteiros:\n");
    scanf("%d %d", &num1, &num2);

    *maior = (num1 > num2) ? num1 : num2;
    *menor = (num1 < num2) ? num1 : num2;
}

int main() {
    int maior, menor;

    encontrarExtremos(&maior, &menor);

    printf("Maior valor: %d\n", maior);
    printf("Menor valor: %d\n", menor);

    return 0;
}
