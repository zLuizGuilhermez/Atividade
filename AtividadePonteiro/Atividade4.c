#include <stdio.h>

void trocarValores(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int num1, num2;

    printf("Digite dois numeros inteiros:\n");
    scanf("%d %d", &num1, &num2);

    printf("Valores antes da troca: %d %d\n", num1, num2);

    trocarValores(&num1, &num2);

    printf("Valores apos a troca: %d %d\n", num1, num2);

    return 0;
}
