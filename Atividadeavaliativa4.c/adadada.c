/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _livro{
    char nome_livro[30];
    int quan_pag = 0;
    double preco_livro = 0.0;
    
} Livro

typedef struct _aluno{
    char nome_aluno[30];
    int idade_aluno = 0;
    
    Livro * livro;
    
} Aluno
   
Livro *create_livro (char *nome_livro, int quanPag, double preco){
  
    Livro *l = calloc (1, sizeof (Livro));
    strcpy (u->nome, nome);
 
    l->quanPag = quanPag;
    l->preco_livro = preco;
 
 

 return l;

}

Aluno * createAluno (char *nome, idade, Livro * livr){
  
Aluno * a = calloc (1, sizeof (Aluno));
  
strcpy (a->nome, nome);
  
 a->idade = idade;
  
 a->universidade = copy_livro (livr);
  
return a;

}

void display_livro()

int main(){
    
    Livro *l = create_livro("Harry Potter e o Prisioneiro de Azkaban", 325, 180.00)

    Aluno *luiz = createAluno ("Luiz", 20, l);

}
