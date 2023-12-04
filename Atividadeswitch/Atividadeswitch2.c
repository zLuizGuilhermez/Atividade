#include <stdio.h>

int main() {
    int codigo;
    float preco;
    int quantidade;

    printf("Digite o codigo do item (1 - Cachorro Quente, 2 - Bauru Simples, 3 - Bauru com Ovo, 4 - Hamburger, 5 - Cheeseburger): ");
    scanf("%d", &codigo);

    switch (codigo) {
        case 1:
            preco = 10.10;
            printf("Cachorro Quente\n");
            break;
        case 2:
            preco = 8.30;
            printf("Bauru Simples\n");
            break;
        case 3:
            preco = 8.50;
            printf("Bauru com Ovo\n");
            break;
        case 4:
            preco = 12.50;
            printf("Hamburger\n");
            break;
        case 5:
            preco = 13.50;
            printf("Cheeseburger\n");
            break;
        default:
            printf("Codigo de item invalido\n");
            return 1;  
    }

    printf("Digite a quantidade: ");
    scanf("%d", &quantidade);

    float valorTotal = preco * quantidade;

    printf("Valor a ser pago: R$ %.2f\n", valorTotal);

    return 0;
}
