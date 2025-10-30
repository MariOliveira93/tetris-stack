#ifndef PILHA_H
#define PILHA_H

#include "peca.h"

#define TAMANHO_PILHA 3

/**
 * Estrutura de pilha para gerenciar peças reservadas
 */
typedef struct {
    Peca pecas[TAMANHO_PILHA];
    int topo;  // Índice do topo da pilha (-1 se vazia)
} PilhaPecas;

/**
 * Inicializa a pilha de peças
 * @param pilha Ponteiro para a pilha
 */
void inicializarPilha(PilhaPecas *pilha);

/**
 * Verifica se a pilha está vazia
 * @param pilha Ponteiro para a pilha
 * @return 1 se vazia, 0 caso contrário
 */
int pilhaVazia(PilhaPecas *pilha);

/**
 * Verifica se a pilha está cheia
 * @param pilha Ponteiro para a pilha
 * @return 1 se cheia, 0 caso contrário
 */
int pilhaCheia(PilhaPecas *pilha);

/**
 * Adiciona uma peça ao topo da pilha
 * @param pilha Ponteiro para a pilha
 * @param p Peça a ser adicionada
 * @return 1 se sucesso, 0 se falha
 */
int empilhar(PilhaPecas *pilha, Peca p);

/**
 * Remove e retorna a peça do topo da pilha
 * @param pilha Ponteiro para a pilha
 * @param p Ponteiro para armazenar a peça removida
 * @return 1 se sucesso, 0 se falha
 */
int desempilhar(PilhaPecas *pilha, Peca *p);

/**
 * Retorna a peça do topo sem remover
 * @param pilha Ponteiro para a pilha
 * @param p Ponteiro para armazenar a peça
 * @return 1 se sucesso, 0 se falha
 */
int topoPilha(PilhaPecas *pilha, Peca *p);

/**
 * Exibe o estado atual da pilha (do topo para a base)
 * @param pilha Ponteiro para a pilha
 */
void exibirPilha(PilhaPecas *pilha);

#endif // PILHA_H