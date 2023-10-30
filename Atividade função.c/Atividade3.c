#include<stdio.h>
#include<stdlib.h>
void
imprimir (int matriz[10][10]){
  for (int coluna = 0; coluna < 10; coluna++){
      for (int linha = 0; linha < 10; linha++){
	  printf ("\n%d", matriz[linha][coluna]);
	}
      printf ("\n");
    }
}

//trocar linha 2 pela linha 8
void
trocarLinha2Linha8 (int matriz[10][10]){
  int aux;
  for (int coluna = 0; coluna < 10; coluna++){
      aux = matriz[1][coluna];
      matriz[1][coluna] = matriz[7][coluna];
      matriz[7][coluna] = aux;
    }
}
void trocarColuna4Coluna10(int matriz[10][10]){
 int aux;
  for (int i = 0; i < 10; i++){
      aux = matriz[i][3];
      matriz[i][3] = matriz[i][9];
      matriz[i][9] = aux;
    
 }
}
void trocarDiagonais(int matriz[10][10]){
    int aux;
  for (int i = 0; i < 10; i++){
    aux = matriz[i][i];
    matriz[i][i] = matriz[i][9 - i];
    matriz[i][9 - i] = aux;
    
}
}
void trocarLinha5Coluna10(int matriz[10][10]){
   int aux;
  for (int i = 0; i < 10; i++){
    aux = matriz[4][i];
    matriz[4][i] = matriz[i][9];
    matriz[i][9] = aux;
    
}
}

int main (){
  int matriz[10][10];

  for (int coluna = 0; coluna < 10; coluna++){
      for (int linha = 0; linha < 10; linha++){
	  matriz[linha][coluna] = coluna * 10 + linha;
	}
    }

  imprimir (matriz);

  //trocarLinha2Linha8 (matriz);
  //trocarColuna4Coluna10(matriz);
  //trocarDiagonais(matriz);
  //trocarLinha5Coluna10(matriz);
  imprimir (matriz);
}
