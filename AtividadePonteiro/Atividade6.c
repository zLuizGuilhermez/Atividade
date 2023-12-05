#include <stdio.h>

void calcularDobro(int *a, int *b) {
    *a = 2 * (*a);
    *b = 2 * (*b);
}

int main() {
    int num1, num2;

    printf("Digite dois numeros inteiros:\n");
    scanf("%d %d", &num1, &num2);

    calcularDobro(&num1, &num2);

    printf("Dobro de num1: %d\n", num1);
    printf("Dobro de num2: %d\n", num2);

    return 0;
}
