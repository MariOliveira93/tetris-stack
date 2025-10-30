#ifndef FILA_H
#define FILA_H

#include "peca.h"

#define TAMANHO_FILA 5

/**
 * Estrutura de fila circular para gerenciar peças futuras
 */
typedef struct {
    Peca pecas[TAMANHO_FILA];
    int frente;     // Índice da frente da fila
    int tras;       // Índice do final da fila
    int tamanho;    // Número atual de elementos
} FilaPecas;

/**
 * Inicializa a fila de peças
 * @param fila Ponteiro para a fila
 * @param idInicial ID inicial para geração de peças
 */
void inicializarFila(FilaPecas *fila, int *idInicial);

/**
 * Verifica se a fila está vazia
 * @param fila Ponteiro para a fila
 * @return 1 se vazia, 0 caso contrário
 */
int filaVazia(FilaPecas *fila);

/**
 * Verifica se a fila está cheia
 * @param fila Ponteiro para a fila
 * @return 1 se cheia, 0 caso contrário
 */
int filaCheia(FilaPecas *fila);

/**
 * Adiciona uma peça ao final da fila
 * @param fila Ponteiro para a fila
 * @param p Peça a ser adicionada
 * @return 1 se sucesso, 0 se falha
 */
int enfileirar(FilaPecas *fila, Peca p);

/**
 * Remove e retorna a peça da frente da fila
 * @param fila Ponteiro para a fila
 * @param p Ponteiro para armazenar a peça removida
 * @return 1 se sucesso, 0 se falha
 */
int desenfileirar(FilaPecas *fila, Peca *p);

/**
 * Retorna a peça da frente sem remover
 * @param fila Ponteiro para a fila
 * @param p Ponteiro para armazenar a peça
 * @return 1 se sucesso, 0 se falha
 */
int frenteFila(FilaPecas *fila, Peca *p);

/**
 * Exibe o estado atual da fila
 * @param fila Ponteiro para a fila
 */
void exibirFila(FilaPecas *fila);

#endif // FILA_H