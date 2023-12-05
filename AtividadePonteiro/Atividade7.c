#include <stdio.h>

void calcularSoma(int *a, int b) {
    *a = *a + b;
}

int main() {
    int num1, num2;

    printf("Digite dois numeros inteiros:\n");
    scanf("%d %d", &num1, &num2);

    calcularSoma(&num1, num2);

    printf("Valor de num1 apos a soma: %d\n", num1);
    printf("Valor de num2: %d\n", num2);

    return 0;
}
