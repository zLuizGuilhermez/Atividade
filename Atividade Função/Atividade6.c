#include<stdio.h>

int main(void){
   int raio = 0, resultadoFinal = 0;
    printf("Digite o raio");
    scanf("%d", &raio);
    resultadoFinal = calculo(raio);
    printf("%d", resultadoFinal);
    return 0;
}

int calculo(int raio){
    int calculo = 4 / 3 * (float)3.1414592 * (raio * raio * raio);
    return calculo;
}