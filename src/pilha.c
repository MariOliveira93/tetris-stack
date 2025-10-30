#include "pilha.h"
#include <stdio.h>

void inicializarPilha(PilhaPecas *pilha) {
    pilha->topo = -1;
}

int pilhaVazia(PilhaPecas *pilha) {
    return pilha->topo == -1;
}

int pilhaCheia(PilhaPecas *pilha) {
    return pilha->topo == TAMANHO_PILHA - 1;
}

int empilhar(PilhaPecas *pilha, Peca p) {
    if (pilhaCheia(pilha)) {
        return 0;
    }
    
    pilha->pecas[++pilha->topo] = p;
    return 1;
}

int desempilhar(PilhaPecas *pilha, Peca *p) {
    if (pilhaVazia(pilha)) {
        return 0;
    }
    
    *p = pilha->pecas[pilha->topo--];
    return 1;
}

int topoPilha(PilhaPecas *pilha, Peca *p) {
    if (pilhaVazia(pilha)) {
        return 0;
    }
    
    *p = pilha->pecas[pilha->topo];
    return 1;
}

void exibirPilha(PilhaPecas *pilha) {
    if (pilhaVazia(pilha)) {
        printf("[Vazia]");
        return;
    }
    
    // Exibe do topo para a base
    for (int i = pilha->topo; i >= 0; i--) {
        exibirPeca(pilha->pecas[i]);
    }
}