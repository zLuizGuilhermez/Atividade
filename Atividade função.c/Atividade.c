#include <stdio.h>
float opcaoum(int opcao, float valorGasto);
float opcaodois(float valorGasto);
float opcaotres(int opcao, float valorGasto, int parcelas);

int main(){

    float valorGasto = 0.0;
    int opcao = 0, parcelas = 0;

    printf("Quanto você gastou ?");
    scanf("%f", &valorGasto);

    printf("Existem 3 opções de pagamento:\n 1 - a vista com 10 porcento de desconto \n 2 - em duas vezes (preço da etiqueta) \n 3 - de 3 até 10 vezes com 3 porcento de juros ao mês sobre o valor de cada prestação (somente para compras acima de R$ 100,00). ");
    scanf("\n %d", &opcao);

    if (opcao == 1){
        opcaoum(opcao, valorGasto);
    }
    else if (opcao == 2){
        opcaodois(valorGasto);
    }
    else if (valorGasto > 100 && opcao == 3){
        printf("escolha o numero de parcelas");
        scanf("%d", &parcelas);
        if (parcelas >= 3 && parcelas <= 10){
            opcaotres(opcao, valorGasto, parcelas);
        }
    }
    return 0;
}


    float opcaoum(int opcao, float valorGasto){
        float formula = valorGasto * (float)0.1;
        float formulaDois = valorGasto - formula;
        printf("O valor ficara %0.2f", formulaDois);
        return formulaDois;
        
    }

    float opcaodois(float valorGasto){
        float parcela = valorGasto / 2;
        printf("Ira ser em 2 parcelas de %0.2f", parcela);
        return parcela;
    }
    float opcaotres(int opcao, float valorGasto, int parcelas){
        float calculo = valorGasto / parcelas;
        float porcentagem = calculo * (float)0.03;
        float valorFinal = calculo + porcentagem;
        printf("A quantidade de parcelas e %d , o valor de cada parcela e de %0.2f", parcelas, valorFinal);
        return valorFinal; 
    }
