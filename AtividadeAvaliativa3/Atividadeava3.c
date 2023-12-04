#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct Produto {
    char descricao[50];
    int quantidade;
    float valor;
    int codigo;
    struct Produto *prox;
} Produto;

Produto* criandoEstoque() {
    return NULL;
}

Produto* criaProd() {
    Produto *novoProduto = (Produto*)malloc(sizeof(Produto));
    if (novoProduto == NULL) {
        printf("Erro de alocacao de memoria");
        exit(EXIT_FAILURE);
    }
    novoProduto->prox = NULL;
    return novoProduto;
}

Produto* cadastroProd(Produto *estoque) {
    srand(time(NULL));
    Produto *novoProduto = criaProd();
    novoProduto->codigo = rand() % 100;
    printf("Digite a descricao do produto: ");
    fflush(stdin);
    fgets(novoProduto->descricao, sizeof(novoProduto->descricao), stdin);
    printf("Digite a quantidade do produto: ");
    scanf("%d", &novoProduto->quantidade);
    printf("Digite o valor do produto: ");
    scanf("%f", &novoProduto->valor);

    if (estoque == NULL) {
        return novoProduto;
    } else {
        Produto *atual = estoque;
        while (atual->prox != NULL) {
            atual = atual->prox;
        }
        atual->prox = novoProduto;
        return estoque;
    }
}

void mostrarEstoque(Produto *estoque) {
    Produto *atual = estoque;
    if (estoque == NULL) {
        printf("\nEstoque vazio\n");
        return;
    } else {
        while (atual != NULL) {
            printf("\nDescricao: %s", atual->descricao);
            printf("Quantidade: %d", atual->quantidade);
            printf("\nValor: %.2f", atual->valor);
            printf("\nCodigo: %d", atual->codigo);
            printf("\n");
            atual = atual->prox;
        }
    }
}

Produto* buscarProduto(Produto *estoque, int codigoBusca) {
    Produto *atual = estoque;
    while (atual != NULL) {
        if (atual->codigo == codigoBusca) {
            printf("\nDescricao: %s", atual->descricao);
            printf("Quantidade: %d", atual->quantidade);
            printf("\nValor: $%.2f", atual->valor);
            printf("\nCodigo: %d", atual->codigo);
            return atual;
        }
        atual = atual->prox;
    }
    printf("Produto nao encontrado");
    return NULL;
}

void alterarProduto(Produto *produto) {
    printf("\nDigite a nova descricao: ");
    fflush(stdin);
    fgets(produto->descricao, sizeof(produto->descricao), stdin);
    printf("\nDigite a nova quantidade: ");
    scanf("%d", &produto->quantidade);
    printf("\nDigite o novo valor: ");
    scanf("%f", &produto->valor);
}

Produto* excluirProduto(Produto *estoque, int codigoBusca) {
    Produto *atual = estoque;
    Produto *anterior = NULL;

    while (atual != NULL && atual->codigo != codigoBusca) {
        anterior = atual;
        atual = atual->prox;
    }
    if (atual != NULL) {
        if (anterior != NULL) {
            anterior->prox = atual->prox;
        } else {
            estoque = atual->prox;
        }
        free(atual);
        printf("Produto removido com sucesso");
    } else {
        printf("\nProduto nao encontrado\n");
    }
    return estoque;
}

void liberarEstoque(Produto *estoque) {
    Produto *atual = estoque;
    Produto *prox;
    while (atual != NULL) {
        prox = atual->prox;
        free(atual);
        atual = prox;
    }
}

int main() {
    int opcao;
    int codigoBusca;
    Produto *encontrado;
    Produto *estoque = criandoEstoque();

    do {
        printf("\nDigite 1 para cadastrar produto");
        printf("\nDigite 2 para mostrar estoque");
        printf("\nDigite 3 para buscar produto");
        printf("\nDigite 4 para alterar produto");
        printf("\nDigite 5 para excluir produto");
        printf("\nDigite 0 para sair");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                estoque = cadastroProd(estoque);
                break;
            case 2:
                printf("Carregando estoque...");
                mostrarEstoque(estoque);
                break;
            case 3:
                printf("Digite o codigo para busca: ");
                scanf("%d", &codigoBusca);
                encontrado = buscarProduto(estoque, codigoBusca);
                break;
            case 4:
                printf("\nDigite o codigo para alteracao: ");
                scanf("%d", &codigoBusca);
                encontrado = buscarProduto(estoque, codigoBusca);
                if (encontrado != NULL) {
                    alterarProduto(encontrado);
                }
                break;
            case 5:
                printf("\nDigite o codigo para exclusao: ");
                scanf("%d", &codigoBusca);
                estoque = excluirProduto(estoque, codigoBusca);
                break;
        }
    } while (opcao != 0);

    liberarEstoque(estoque);

    return 0;
}
