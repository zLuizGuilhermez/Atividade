/*Escreva uma função que receba por parâmetro uma temperatura em graus Fahrenheit e a
retorne convertida em graus Celsius. A fórmula de conversão é: C = (F – 32.0) * (5.0/9.0),
sendo F a temperatura em Fahrenheit e C a temperatura em Celsius*/
#include<stdio.h>

int main(){
  int fahrenheit = 0, resultadoFinal = 0;
  
  printf("Digite a temperatura");
  scanf("%d", &fahrenheit);
  resultadoFinal = calculo(fahrenheit);
  printf("Resultado %d", resultadoFinal);

}
int calculo(int fahrenheit){
    int conversao = (fahrenheit - 32.0) * (5.0 / 9.0);
    return conversao;

}