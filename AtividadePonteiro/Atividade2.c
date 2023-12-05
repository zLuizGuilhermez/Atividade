#include <stdio.h>

int main() {
    int var1, var2;

    int *ptr1 = &var1;
    int *ptr2 = &var2;

    printf("Endereco da primeira variavel: %p\n", (void*)ptr1);
    printf("Endereco da segunda variavel: %p\n", (void*)ptr2);

    if (ptr1 > ptr2) {
        printf("O endereco da primeira variavel e maior.\n");
    } else if (ptr2 > ptr1) {
        printf("O endereco da segunda variavel e maior.\n");
    } else {
        printf("Os enderecos sao iguais.\n");
    }

    return 0;
}
