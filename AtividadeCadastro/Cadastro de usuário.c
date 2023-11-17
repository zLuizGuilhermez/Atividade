#include <stdio.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char nome[20];
    char email[50]; 
    char sexo;
    char endereco[20];
    int id, vacina;
    float altura;
} cliente;

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastro(cliente a[], int contador) {
    printf("\nDigite o seu id para registro\n");
    scanf("%d", &a[contador].id);
    limparBuffer();

    printf("\nDigite o sexo\n");
    scanf(" %c", &a[contador].sexo);
    limparBuffer();

    printf("\nDigite o nome do cliente\n");
    fgets(a[contador].nome, sizeof(a[contador].nome), stdin);
    a[contador].nome[strcspn(a[contador].nome, "\n")] = '\0';

    printf("\nDigite a sua altura\n");
    scanf("%f", &a[contador].altura);
    limparBuffer();

    printf("\nDigite o endereço?\n");
    fgets(a[contador].endereco, sizeof(a[contador].endereco), stdin);
    a[contador].endereco[strcspn(a[contador].endereco, "\n")] = '\0';

    printf("\nDigite o email?\n");
    fgets(a[contador].email, sizeof(a[contador].email), stdin);
    a[contador].email[strcspn(a[contador].email, "\n")] = '\0';

    printf("Situação de vacina 1 - sim 0 - nao: ");
    scanf("%d", &a[contador].vacina);
}

void listarTodos(cliente a[], int contador) {
    if (contador == 0) {
        printf("\nNenhum dado cadastrado.\n");
    } else {
        for (int i = 0; i < contador; i++) {
            printf("\nNome: %s", a[i].nome);
            printf("\nAltura: %0.2f", a[i].altura);
            printf("\nEmail: %s", a[i].email);
            printf("\nEndereco: %s", a[i].endereco);
            printf("\nVacina: %d", a[i].vacina);
            printf("\nID: %d", a[i].id);
            printf("\nSexo: %c", a[i].sexo);
            printf("\n");
        }
    }
}
void buscarCliente(cliente a[], int contador, int emailBusca){
    for (int i = 0; i < contador; i++)
    {
        if (emailBusca == a[i].email)
        {
            printf("\nNome: %s", a[i].nome);
            printf("\nAltura: %0.2f", a[i].altura);
            printf("\nEmail: %s", a[i].email);
            printf("\nEndereco: %s", a[i].endereco);
            printf("\nVacina: %d", a[i].vacina);
            printf("\nID: %d", a[i].id);
            printf("\nSexo: %c", a[i].sexo);
            printf("\n");
        }else{
            printf("Email não encontrado");
        }
        
    }
    
}

int main(){
    cliente a[MAX];
    char emailBusca[50];
    int contador = 0, opcao = 0;

    do {
        printf("\nOpção 1: Cadastro\nOpção 2: Listar todos os clientes\nOpção 3: Buscar usuário\nOpção 4: Excluir um usuário\nOpção 5: Alterar um cadastro\nDigite 0 para sair do programa\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (contador < MAX) {
                    contador++;
                    cadastro(a, contador - 1); 
                } else {
                    printf("Limite máximo alcançado.\n");
                }
                break;
            case 2:
                listarTodos(a, contador);
                break;
            case 3:
                printf("Deseja o email que quer buscar");
                fgets(emailBusca, sizeof(emailBusca), stdin);
emailBusca[strcspn(emailBusca, "\n")] = '\0';
                limparBuffer();
                buscarCliente(a, contador, emailBusca);
            break;
            default:
                break;
        }
    } while (opcao != 0);

    return 0;
}
