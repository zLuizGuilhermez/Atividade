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
void buscarCliente(cliente a[], int contador, char emailBusca[]) {
    int encontrado = 0; 

    for (int i = 0; i < contador; i++) {
        if (strcmp(emailBusca, a[i].email) == 0) {
            printf("\nNome: %s", a[i].nome);
            printf("\nAltura: %0.2f", a[i].altura);
            printf("\nEmail: %s", a[i].email);
            printf("\nEndereco: %s", a[i].endereco);
            printf("\nVacina: %d", a[i].vacina);
            printf("\nID: %d", a[i].id);
            printf("\nSexo: %c", a[i].sexo);
            printf("\n");
            encontrado = 1; 
            break; 
        }
    }

    if (!encontrado) {
        printf("Email não encontrado\n");
    }
}
void editarUsuario(cliente a[], int contador) {
    int idEditar;

    printf("Digite o ID do usuário a ser editado: ");
    scanf("%d", &idEditar);

    for (int i = 0; i < contador; i++) {
        if (idEditar == a[i].id) {
            printf("Digite o novo nome completo: ");
            getchar(); 
            fgets(a[i].nome, sizeof(a[i].nome), stdin);
            a[i].nome[strcspn(a[i].nome, "\n")] = '\0';

                printf("Digite o novo email: ");
                fgets(a[i].email, sizeof(a[i].email), stdin);
                a[i].email[strcspn(a[i].email, "\n")] = '\0';

            printf("Digite o novo sexo (Feminino, Masculino ou Indiferente): ");
            scanf(" %c", &a[i].sexo);


            printf("Digite o novo endereço: ");
            fgets(a[i].endereco, sizeof(a[i].endereco), stdin);
            a[i].endereco[strcspn(a[i].endereco, "\n")] = '\0';

                printf("Digite a nova altura (entre 1 e 2 metros): ");
                scanf("%f", &a[i].altura);

            printf("Situação da nova vacina (1 - sim, 0 - não): ");
            scanf("%d", &a[i].vacina);

            printf("\nUsuário editado com sucesso.\n");
            break;
        }
    }
 }
 void excluirUsuario(cliente a[], int *contador) {
    int idExcluir;
    int encontrado = 0;

    printf("Digite o ID do usuário a ser excluído: ");
    scanf("%d", &idExcluir);

    for (int i = 0; i < *contador; i++) {
        if (idExcluir == a[i].id) {
            for (int j = i; j < *contador - 1; j++) {
                a[j] = a[j + 1];
            }

            (*contador)--;
            printf("\nUsuário excluído com sucesso.\n");
            encontrado = 1;
            break;
        }
    }

    if (!encontrado) {
        printf("\nUsuário não encontrado.\n");
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
                printf("Digite o email que quer buscar: ");
                fgets(emailBusca, sizeof(emailBusca), stdin);
                emailBusca[strcspn(emailBusca, "\n")] = '\0';
                limparBuffer();

                buscarCliente(a, contador, emailBusca);
            break;
            case 4:
            excluirUsuario(a, &contador);
            break;
            case 5:
                editarUsuario(a, contador);
                break;
            default:
                break;
        }
    } while (opcao != 0);

    return 0;
}
