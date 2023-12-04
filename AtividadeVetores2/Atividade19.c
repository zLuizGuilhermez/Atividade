#include <stdio.h>

int main() {
    int vetor[50];
    int i;

    for(i = 0; i < 50; i++) {
        vetor[i] = i + 5 * (i + 1);
    }

    printf("Elementos do vetor:\n");

    for(i = 0; i < 50; i++) {
        printf("%d\n", vetor[i]);
    }

    return 0;
}
