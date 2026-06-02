#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H

// capacidade maxima de livros no sistema
#define MAX_LIVROS 100

// tamanhos dos campos de texto
#define TAM_TITULO 100
#define TAM_AUTOR  80

// estrutura que representa um livro
typedef struct {
    int codigo;
    char titulo[TAM_TITULO];
    char autor[TAM_AUTOR];
    int ano;
    int quantidade;
} Livro;

// prototipos das funcoes
void adicionarLivro(Livro biblioteca[], int *total);
void listarLivros(Livro biblioteca[], int total);
void procurarPorCodigo(Livro biblioteca[], int total);
void mostrarDisponiveis(Livro biblioteca[], int total);
void atualizarQuantidade(Livro biblioteca[], int total);
void removerLivro(Livro biblioteca[], int *total);
void mostrarTotal(int total);

// funcoes auxiliares
int codigoExiste(Livro biblioteca[], int total, int codigo);
int encontrarIndice(Livro biblioteca[], int total, int codigo);
void limparBuffer();

#endif
