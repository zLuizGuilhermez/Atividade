#include <stdio.h>

int main() {
    int var1, var2;

    printf("Digite dois numeros inteiros:\n");
    scanf("%d %d", &var1, &var2);

    int *ptr1 = &var1;
    int *ptr2 = &var2;

    printf("Conteudo do endereco de maior valor: %d\n", (*ptr1 > *ptr2) ? *ptr1 : *ptr2);

    return 0;
}
