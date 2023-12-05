#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Veiculo {
    char proprietario[50];
    char combustivel[20];
    char modelo[50];
    char cor[20];
    char chassi[20];
    int ano;
    char placa[8];
    struct Veiculo *prox;
} Veiculo;

Veiculo* criarListaVeiculos() {
    return NULL;
}

Veiculo* criarVeiculo() {
    Veiculo *novoVeiculo = (Veiculo*)malloc(sizeof(Veiculo));
    if (novoVeiculo == NULL) {
        printf("Erro de alocacao de memoria");
        exit(EXIT_FAILURE);
    }
    novoVeiculo->prox = NULL;
    return novoVeiculo;
}

Veiculo* cadastrarVeiculo(Veiculo *listaVeiculos) {
    Veiculo *novoVeiculo = criarVeiculo();

    printf("Digite o nome do proprietario: ");
    fflush(stdin);
    fgets(novoVeiculo->proprietario, sizeof(novoVeiculo->proprietario), stdin);
    int retorno;

    do {
        retorno = 0;
        printf("Digite o tipo de combustivel ('alcool', 'diesel', 'gasolina'): ");
        scanf("%s", novoVeiculo->combustivel);
        if (strcmp(novoVeiculo->combustivel, "alcool") != 0 && strcmp(novoVeiculo->combustivel, "diesel") != 0 && strcmp(novoVeiculo->combustivel, "gasolina") != 0) {
            retorno = 1;
            printf("Tipo de combustivel invalido. Tente novamente.\n");
        }
    } while (retorno != 0);

    printf("Digite o modelo do veiculo: ");
    scanf("%s", novoVeiculo->modelo);

    printf("Digite a cor do veiculo: ");
    scanf("%s", novoVeiculo->cor);

    printf("Digite o numero do chassi: ");
    scanf("%s", novoVeiculo->chassi);

    printf("Digite o ano do veiculo: ");
    scanf("%d", &novoVeiculo->ano);

    do {
        printf("Digite a placa do veiculo (Placa possui os três primeiros valores alfabéticos e os quatro restantes valores numéricos.): ");
        scanf("%s", novoVeiculo->placa);

        if (strlen(novoVeiculo->placa) != 7) {
            printf("Placa invalida. Deve conter 7 caracteres. Tente novamente.\n");
        }
    } while (strlen(novoVeiculo->placa) != 7);

    if (listaVeiculos == NULL) {
        return novoVeiculo;
    } else {
        Veiculo *atual = listaVeiculos;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoVeiculo;
        return listaVeiculos;
    }
}

void listarVeiculosAnoDiesel(Veiculo *listaVeiculos) {
    Veiculo *atual = listaVeiculos;
    while (atual != NULL) {
        if (atual->ano >= 2010 && strcmp(atual->combustivel, "diesel") == 0) {
            printf("\nProprietario: %s", atual->proprietario);
            printf("\nCombustivel: %s", atual->combustivel);
            printf("\nModelo: %s", atual->modelo);
            printf("\nCor: %s", atual->cor);
            printf("\nChassi: %s", atual->chassi);
            printf("\nAno: %d", atual->ano);
            printf("\nPlaca: %s", atual->placa);
            printf("\n");
        }
        atual = atual->prox;
    }
}

void listarPlacasEspecificas(Veiculo *listaVeiculos) {
    Veiculo *atual = listaVeiculos;
    while (atual != NULL) {
        if (atual->placa[0] == 'J' && (atual->placa[6] == '0' || atual->placa[6] == '2' || atual->placa[6] == '4' || atual->placa[6] == '7')) {
            printf("\nProprietario: %s", atual->proprietario);
            printf("\nCombustivel: %s", atual->combustivel);
            printf("\nModelo: %s", atual->modelo);
            printf("\nCor: %s", atual->cor);
            printf("\nChassi: %s", atual->chassi);
            printf("\nAno: %d", atual->ano);
            printf("\nPlaca: %s", atual->placa);
            printf("\n");

        }
        atual = atual->prox;
    }
}

void listarModeloCorVogalSomaPar(Veiculo *listaVeiculos) {
    Veiculo *atual = listaVeiculos;
    while (atual != NULL) {
        if (strchr("aeiouAEIOU", atual->placa[1]) != NULL) {
            int resultadoSoma = 0;
            for (int i = 0; i < 7; i++) {
                if (isdigit(atual->placa[i])) {
                    resultadoSoma += atual->placa[i] - '0';
                }
            }
            if (resultadoSoma % 2 == 0) {
                printf("\nProprietario: %s", atual->proprietario);
                printf("\nCombustivel: %s", atual->combustivel);
                printf("\nModelo: %s", atual->modelo);
                printf("\nCor: %s", atual->cor);
                printf("\nChassi: %s", atual->chassi);
                printf("\nAno: %d", atual->ano);
                printf("\nPlaca: %s", atual->placa);
                printf("\n");
            }
        }
        atual = atual->prox;
    }
}

void trocarProprietario(Veiculo *listaVeiculos, const char *chassi) {
    Veiculo *atual = listaVeiculos;
    while (atual != NULL) {
        if (strcmp(atual->chassi, chassi) == 0 && strchr(atual->placa, '0') == NULL) {
            printf("\nDigite o novo nome do proprietario: ");

            // Consumir caracteres indesejados do buffer
            int c;
            while ((c = getchar()) != '\n' && c != EOF);

            // Obter o novo nome do proprietário
            fgets(atual->proprietario, sizeof(atual->proprietario), stdin);

            // Remover a quebra de linha do final do nome, se houver
            size_t len = strlen(atual->proprietario);
            if (len > 0 && atual->proprietario[len - 1] == '\n') {
                atual->proprietario[len - 1] = '\0';
            }

            printf("Proprietario alterado com sucesso");
            return;
        }
        atual = atual->prox;
    }
    printf("\nVeiculo nao encontrado ou placa possui digito zero");
}

void liberarListaVeiculos(Veiculo *listaVeiculos) {
    Veiculo *atual = listaVeiculos;
    Veiculo *prox;
    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

int main() {
    int opcao;
    char chassiTroca[20];
    Veiculo *listaVeiculos = criarListaVeiculos();

    do {
        printf("\nDigite 1 para cadastrar veiculo");
        printf("\nDigite 2 para listar veiculos ano 2010 ou posterior movidos a diesel");
        printf("\nDigite 3 para listar placas que comecem com J e terminem com 0, 2, 4 ou 7");
        printf("\nDigite 4 para listar modelo e cor de veiculos com placas segunda letra vogal e soma de digitos par");
        printf("\nDigite 5 para trocar proprietario de veiculo (com chassi)");
        printf("\nDigite 0 para sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                listaVeiculos = cadastrarVeiculo(listaVeiculos);
                break;
            case 2:
                printf("\nVeiculos ano 2010 ou posterior movidos a diesel:\n");
                listarVeiculosAnoDiesel(listaVeiculos);
                break;
            case 3:
                printf("\nPlacas que comecam com J e terminam com 0, 2, 4 ou 7:\n");
                listarPlacasEspecificas(listaVeiculos);
                break;
            case 4:
                printf("\nModelo e cor de veiculos com placas segunda letra vogal e soma de digitos par:\n");
                listarModeloCorVogalSomaPar(listaVeiculos);
                break;
            case 5:
                printf("\nDigite o chassi do veiculo para troca de proprietario: \n");
                scanf("%s", chassiTroca);
                trocarProprietario(listaVeiculos, chassiTroca);
                break;
        }
    } while (opcao != 0);

    liberarListaVeiculos(listaVeiculos);

    return 0;
}
