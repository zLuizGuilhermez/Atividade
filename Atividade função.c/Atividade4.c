#include<stdio.h>
void somarColunas(int matriz[60][10]){
    for(int j = 0; j < 10; j++){
      matriz[60][j] = 0;
}
for(int j = 0; j < 60; j++){
    for(int i = 0; i < 60; i++){
    matriz[60][j] += matriz[i][j];
    }
}
}
int main(){
   int matriz[61][10];
  
  for (int i = 0; i < 60; i++){
      for (int j = 0; j < 10; j++){
	  matriz[i][j] = i * 10 + j;
	  
	}
    printf("\n");
}
somarColunas(matriz);

for (int i = 0; i < 61; i++){
      for (int j = 0; j < 10; j++){
	  printf("%d\t", matriz[i][j]);
	  
	}
    printf("\n");
}
}

