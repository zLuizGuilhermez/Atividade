/*Escreva uma função que receba por parâmetro a altura e o raio de um cilindro circular e
retorne o volume desse cilindro. O volume de um cilindro circular é calculado por meio da
seguinte fórmula:
em que π = 3.1414592*/
#include<stdio.h>

int main(){
    int altura = 0, raio = 0,resultadoFinal = 0;
    printf("Digite a altura");
    scanf("%d", &altura );
    printf("Digite o raio");
    scanf("%d", &raio);
    resultadoFinal = calculo(altura, raio);
    printf("%d", resultadoFinal);
}
  

int calculo(int altura, int raio){
    int calculo = (float)3.1414592 * (raio * raio) * altura;
    return calculo;
}
