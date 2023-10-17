#include<stdio.h>

int main(){
   int n1 = 0,n2 = 0,resultado = 0;
   printf("Digite o primeiro numero");
   scanf("%d", &n1);
   printf("Digite o segundo numero");
   scanf("%d", &n2);
   
   resultado = maior(n1,n2);
   printf("%d", resultado);
}

int maior(int num1, int num2){
     if (num1 > num2)
     {
        return num1;
     }else{
        return num2;
     }
     
}