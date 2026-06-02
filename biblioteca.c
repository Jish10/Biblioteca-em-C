#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

void limparBuffer() {
    while (getchar() != '\n');
}

// retorna o indice do livro, ou -1 se nao existir
int encontrarIndice(Livro biblioteca[], int total, int codigo) {
    for (int i = 0; i < total; i++) {
        if (biblioteca[i].codigo == codigo)
            return i;
    }
    return -1;
}

void adicionarLivro(Livro biblioteca[], int *total) {
    if (*total >= MAX_LIVROS) {
        printf("Sistema cheio.\n");
        return;
    }

    Livro novo;

    printf("Codigo: ");
    scanf("%d", &novo.codigo);
    limparBuffer();

    if (novo.codigo <= 0 || encontrarIndice(biblioteca, *total, novo.codigo) != -1) {
        printf("Codigo invalido ou ja existe.\n");
        return;
    }

    printf("Titulo: ");
    fgets(novo.titulo, TAM_TITULO, stdin);
    novo.titulo[strcspn(novo.titulo, "\n")] = '\0';

    printf("Autor: ");
    fgets(novo.autor, TAM_AUTOR, stdin);
    novo.autor[strcspn(novo.autor, "\n")] = '\0';

    printf("Ano: ");
    scanf("%d", &novo.ano);
    limparBuffer();

    printf("Quantidade: ");
    scanf("%d", &novo.quantidade);
    limparBuffer();

    biblioteca[(*total)++] = novo;
    printf("Livro adicionado!\n");
}

void imprimirCabecalho() {
    printf("\n%-6s %-30s %-20s %-6s %-5s\n", "Cod", "Titulo", "Autor", "Ano", "Qtd");
    printf("---------------------------------------------------------------\n");
}

void listarLivros(Livro biblioteca[], int total) {
    if (total == 0) { printf("Nenhum livro registado.\n"); return; }

    imprimirCabecalho();
    for (int i = 0; i < total; i++)
        printf("%-6d %-30s %-20s %-6d %-5d\n",
               biblioteca[i].codigo, biblioteca[i].titulo,
               biblioteca[i].autor, biblioteca[i].ano, biblioteca[i].quantidade);
}

void procurarPorCodigo(Livro biblioteca[], int total) {
    int codigo;
    printf("Codigo: ");
    scanf("%d", &codigo);
    limparBuffer();

    int idx = encontrarIndice(biblioteca, total, codigo);
    if (idx == -1) { printf("Livro nao encontrado.\n"); return; }

    printf("\nCodigo : %d\n", biblioteca[idx].codigo);
    printf("Titulo : %s\n", biblioteca[idx].titulo);
    printf("Autor  : %s\n", biblioteca[idx].autor);
    printf("Ano    : %d\n", biblioteca[idx].ano);
    printf("Qtd    : %d\n", biblioteca[idx].quantidade);
}

void mostrarDisponiveis(Livro biblioteca[], int total) {
    int encontrou = 0;
    imprimirCabecalho();
    for (int i = 0; i < total; i++) {
        if (biblioteca[i].quantidade > 0) {
            printf("%-6d %-30s %-20s %-6d %-5d\n",
                   biblioteca[i].codigo, biblioteca[i].titulo,
                   biblioteca[i].autor, biblioteca[i].ano, biblioteca[i].quantidade);
            encontrou = 1;
        }
    }
    if (!encontrou) printf("Nenhum livro disponivel.\n");
}

void atualizarQuantidade(Livro biblioteca[], int total) {
    int codigo;
    printf("Codigo: ");
    scanf("%d", &codigo);
    limparBuffer();

    int idx = encontrarIndice(biblioteca, total, codigo);
    if (idx == -1) { printf("Livro nao encontrado.\n"); return; }

    printf("Quantidade atual: %d\nNova quantidade: ", biblioteca[idx].quantidade);
    scanf("%d", &biblioteca[idx].quantidade);
    limparBuffer();
    printf("Quantidade atualizada!\n");
}

void removerLivro(Livro biblioteca[], int *total) {
    int codigo;
    printf("Codigo: ");
    scanf("%d", &codigo);
    limparBuffer();

    int idx = encontrarIndice(biblioteca, *total, codigo);
    if (idx == -1) { printf("Livro nao encontrado.\n"); return; }

    printf("Remover \"%s\"? (s/n): ", biblioteca[idx].titulo);
    char conf;
    scanf("%c", &conf);
    limparBuffer();

    if (conf != 's' && conf != 'S') { printf("Cancelado.\n"); return; }

    // desloca os elementos para cobrir o espaco
    for (int i = idx; i < (*total) - 1; i++)
        biblioteca[i] = biblioteca[i + 1];
    (*total)--;

    printf("Livro removido!\n");
}

void mostrarTotal(int total) {
    printf("Total de livros: %d\n", total);
}
