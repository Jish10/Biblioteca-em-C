#include <stdio.h>
#include <string.h>
#include "biblioteca.h"

int main() {
    Livro biblioteca[MAX_LIVROS];
    int total = 0;
    int opcao;

    printf("= Sistema de Biblioteca - UniMindelo =\n\n");

    do {
        printf("\n- Menu Principal -\n");
        printf("1. Adicionar livro\n");
        printf("2. Listar todos os livros\n");
        printf("3. Procurar livro por codigo\n");
        printf("4. Mostrar livros disponiveis\n");
        printf("5. Atualizar quantidade de exemplares\n");
        printf("6. Remover livro\n");
        printf("7. Total de livros registados\n");
        printf("8. Sair\n");
        printf("Opcao: ");

        // valida se o utilizador digitou um numero
        if (scanf("%d", &opcao) != 1) {
            printf("Entrada invalida. Digite um numero.\n");
            limparBuffer();
            opcao = 0; // forca o loop a continuar
            continue;
        }
        limparBuffer();

        switch (opcao) {
            case 1: adicionarLivro(biblioteca, &total);    break;
            case 2: listarLivros(biblioteca, total);       break;
            case 3: procurarPorCodigo(biblioteca, total);  break;
            case 4: mostrarDisponiveis(biblioteca, total); break;
            case 5: atualizarQuantidade(biblioteca, total);break;
            case 6: removerLivro(biblioteca, &total);      break;
            case 7: mostrarTotal(total);                   break;
            case 8: printf("Am sei. Txau!\n"); break;
            default: printf("Bo digita meriod. Tenta ot vex.\n");
        }

    } while (opcao != 8);

    return 0;
}
