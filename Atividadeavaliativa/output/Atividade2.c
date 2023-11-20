#include<stdio.h>
#define MAX 3
#include<string.h>

typedef struct{
    char nome[20], sexo,qualifisa[6];
    float salario;
}pessoa;
int classificaSalario(pessoa a[],int indice,float salario);

void cadastrar(pessoa a[], int indice){
    int escolha = 0;
    do
    {
        fflush(stdin);
        printf("\nDigite o nome do pessoa");
        getchar();
        fflush(stdin);
        fgets(a[indice].nome,sizeof(a[indice].nome), stdin);
        a[indice].nome[strcspn(a[indice].nome, "\n")] = '\0';
        fflush(stdin);

        printf("Digite o seu salario");
        scanf("%f", &a[indice].salario);
        if (a[indice].salario <= 1)
    {
        printf("Deseja inserir novamente 1 s/0 n");
        scanf("%d", &escolha);
        if (escolha = 0)
        {
            return 0;
        }
    }
    
        printf("\nDigite o seu sexo (m ou f)");
        getchar();
        fflush(stdin);
    scanf(" %c", &a[indice].sexo);
    if (a[indice].sexo != 'm' || a[indice].sexo != 'f')
    {
        printf("Deseja inserir novamente 1 s/0 n");
        scanf("%d", &escolha);
        if (escolha = 0)
        {
            return 0;
        }
        
    }
    
} while (escolha != 0);
}
int classificaSalario(pessoa a[],int indice,float salario){

    if (a[indice].salario < 1400){
    strcpy(a[indice].qualifisa, "Abaixo");
    }else if (a[indice].salario == 1400){
    strcpy(a[indice].qualifisa, "Igual");
    
    }else{
    strcpy(a[indice].qualifisa, "Acima");
    }

}
    
void mostraClassifica(pessoa a[], int indice){
    if(indice == 0){
        printf("\nnenhum dado cadastrado");
        
    }else{
        for(int i = 0; i < indice; i++){
            printf("\nNome %s", a[i].nome); 
            printf("\nSexo %c", a[i].sexo);
            printf("\n Salario %0.2f", a[i].salario);
            printf("Situação salario %s", a[i].qualifisa);
        }
    }
}
int main(){
        pessoa a[MAX];
        int indice = 0,opcao = 0,busca = 0;
        char decisao;
        
        do{
            printf("\nDigite 1 para registrar\nDigite 2 para listar\nDigite 0 para sair");
            scanf("%d", &opcao);
            switch(opcao){
                case 1:
                if(indice < MAX){
                    cadastrar(a, indice);
                    indice++;
                    printf("\nCadastro realizado com sucesso");
                    
                }else{
                    printf("\nCapacidade maxima atingida");
                }
                break;
                case 2:
                    mostraClassifica(a, indice);
                break;
               
            }
            
        }while(opcao != 0);
        return 0;
}