#include "fila.h"
#include <stdio.h>

void inicializarFila(FilaPecas *fila, int *idInicial) {
    fila->frente = 0;
    fila->tras = -1;
    fila->tamanho = 0;
    
    // Preenche a fila com peças iniciais
    for (int i = 0; i < TAMANHO_FILA; i++) {
        Peca p = gerarPeca((*idInicial)++);
        enfileirar(fila, p);
    }
}

int filaVazia(FilaPecas *fila) {
    return fila->tamanho == 0;
}

int filaCheia(FilaPecas *fila) {
    return fila->tamanho == TAMANHO_FILA;
}

int enfileirar(FilaPecas *fila, Peca p) {
    if (filaCheia(fila)) {
        return 0;
    }
    
    fila->tras = (fila->tras + 1) % TAMANHO_FILA;
    fila->pecas[fila->tras] = p;
    fila->tamanho++;
    return 1;
}

int desenfileirar(FilaPecas *fila, Peca *p) {
    if (filaVazia(fila)) {
        return 0;
    }
    
    *p = fila->pecas[fila->frente];
    fila->frente = (fila->frente + 1) % TAMANHO_FILA;
    fila->tamanho--;
    return 1;
}

int frenteFila(FilaPecas *fila, Peca *p) {
    if (filaVazia(fila)) {
        return 0;
    }
    
    *p = fila->pecas[fila->frente];
    return 1;
}

void exibirFila(FilaPecas *fila) {
    if (filaVazia(fila)) {
        printf("[Vazia]");
        return;
    }
    
    int i = fila->frente;
    for (int count = 0; count < fila->tamanho; count++) {
        exibirPeca(fila->pecas[i]);
        i = (i + 1) % TAMANHO_FILA;
    }
}