#include<stdio.h>
#include<string.h>

#define MAX 1000

typedef struct {
    char nome[20], sexo, qualifisa[6];
    float salario;
} pessoa;

void classificaSalario(pessoa a[], int indice, int *salarioMaior, int *salarioMenor);

void cadastrar(pessoa a[], int indice, int *salarioMaior, int *salarioMenor){
    int escolha = 0;
        fflush(stdin);
        printf("\nDigite o nome do pessoa: ");
        fgets(a[indice].nome, sizeof(a[indice].nome), stdin);
        a[indice].nome[strcspn(a[indice].nome, "\n")] = '\0';
        fflush(stdin);
       do{
        escolha = 0;
        fflush(stdin);
        printf("Digite o seu salario: ");
        scanf("%f", &a[indice].salario);
        if (a[indice].salario <= 1) {
            printf("Deseja inserir novamente? 1 para sim, 0 para não: ");
            scanf("%d", &escolha);
            fflush(stdin);
        }
       }while(escolha != 0);
       
        classificaSalario(a, indice, salarioMaior, salarioMenor);
       do{
        escolha = 0;
        printf("\nDigite o seu sexo (M ou F): ");
        scanf(" %c", &a[indice].sexo);
        if (a[indice].sexo != 'M' && a[indice].sexo != 'F') {
            printf("Deseja inserir novamente? 1 para sim, 0 para não: ");
            scanf("%d", &escolha);
            fflush(stdin);
        }
    }while(escolha != 0);

   
}

void classificaSalario(pessoa a[], int indice, int *salarioMaior, int *salarioMenor) {
    if (a[indice].salario < 1400) {
        strcpy(a[indice].qualifisa, "Abaixo");
        (*salarioMenor)++;
    } else if (a[indice].salario == 1400) {
        strcpy(a[indice].qualifisa, "Igual");

    } else {
        strcpy(a[indice].qualifisa, "Acima");
        (*salarioMaior)++;
    }
}

void mostraClassifica(pessoa a[], int indice) {
    if (indice == 0) {
        printf("\nNenhum dado cadastrado");

    } else {
            
        for (int i = 0; i < indice; i++) {
            printf("\n\nNome: %s", a[i].nome);
            if (a[i].sexo == 'M'){
                printf("\nSexo: Masculino");
            }else{
                printf("\nSexo: Feminino");
            }
            printf("\nSalario: BRL %0.2f", a[i].salario);
            printf("\nSituacao salario: %s", a[i].qualifisa);
        }
    }
}

int main() {
    pessoa a[MAX];
    int indice = 0, opcao = 0, salarioMaior = 0, salarioMenor = 0;

    do {
        printf("\n\nDigite 1 para registrar\nDigite 2 para listar\n Digite 3 para mostrar as estatisticas dos salarios \nDigite 0 para sair: ");
        scanf("%d", &opcao);
        getchar();
        switch (opcao) {
            case 1:
                if (indice < MAX) {
                    cadastrar(a, indice, &salarioMaior, &salarioMenor);
                    indice++;
                    printf("\nCadastro realizado com sucesso");

                } else {
                    printf("\nCapacidade maxima atingida");
                }
                break;
            case 2:
                    mostraClassifica(a, indice);
                    break;
            case 3:
                    
                    printf("\nQuantidade de pessoas com salarios menores:%d", salarioMenor);
                    printf("\nQuantidade de pessoas com salarios maiores:%d", salarioMaior);

        }

    } while (opcao != 0);
    return 0;
}
