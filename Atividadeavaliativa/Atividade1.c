#include<stdio.h>

int validaQuantidade(int pecas, int bonus);
int calculaSalario(int pecas, int bonus, int calculo);
int mostraFinal(int calculo);

int validaQuantidade(int pecas, int bonus) {
    if (pecas <= 50 && pecas >= 0) {
        bonus = 0;
        return bonus;
    } else if (pecas > 50 && pecas <= 80) {
        bonus = 0.50 * (pecas - 50);
        return bonus;
    } else if (pecas > 80) {
        pecas -= 50;
        bonus = 0.50 * 30;
        pecas -= 30;
        bonus += 0.75 * pecas;
        return bonus;
    } else {
        printf("O valor nao pode ser negativo\n");
        return -1;
    }
}

int calculaSalario(int pecas, int bonus, int calculo) {
    calculo = 600 + bonus;
    return calculo;
}

int mostraFinal(int calculo) {
    printf("O salario e %d\n", calculo);
    return 0;
}

int main() {
    int pecas = 0, bonus = 0, calculo = 0;
    printf("\nQual a quantidade de peças fabricadas: ");
    scanf("%d", &pecas);

    bonus = validaQuantidade(pecas, bonus);

    if (bonus == -1) {
        return 0;
    }

    calculo = calculaSalario(pecas, bonus, calculo);

    mostraFinal(calculo);

    return 0;
}
