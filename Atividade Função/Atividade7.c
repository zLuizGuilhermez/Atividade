#include<stdio.h>
float calculo(float peso, float altura);
int main(){
    float peso = 0.0, altura = 0.0, resultadoFinal = 0.0;
    printf("Digite o seu peso");
    scanf("%f", &peso);
    printf("Digite a sua altura");
    scanf("%f", &altura);

    resultadoFinal = calculo(peso, altura);

    printf("O imc e: %0.2f", resultadoFinal);
    
    return 0;
}
float calculo(float peso, float altura){
    int operacao = peso / (altura * altura);
    return operacao;

}