#include<stdio.h>
float opcaoum(int opcao, float valorGasto);

float opcaodois( float valorGasto);

int main(){
    
    float valorGasto = 0.0;
    int opcao = 0;
    
    printf("Quanto você gastou ?");
    scanf("%f", &valorGasto);
    
    
    printf("Existem 3 opções de pagamento:\n 1 - a vista com 10 porcento de desconto \n 2 - em duas vezes (preço da etiqueta) \n 3 - de 3 até 10 vezes com 3 porcento de juros ao mês sobre o valor de cada prestação (somente para compras acima de R$ 100,00). ");
    scanf("\n %d", &opcao);
    
    if (opcao == 1) {
        float opcaoRetorno = opcaoum(valorGasto);
    }else if(opcao == 2){
        float opcaoRetornoo = opcaodois(valorGasto);
    }else if(opcao == 3){
        
    }
    return 0;
}

float opcaoum(float valorGasto){
    if(opcao == 1){
        float formula = valorGasto * (float)0.1;
        float formulaDois = valorGasto - formula;
        printf("O valor ficara %0.2f", formulaDois);
        return formulaDois;
    }
    
float opcaodois(int opcao, float valorGasto){
    float parcela = valorGasto / 2;
    printf("Ira ser em 2 parcelas de %0.2f", parcela);
}
}
