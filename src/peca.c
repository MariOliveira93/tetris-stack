#include "peca.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Tipos de peças disponíveis
static const char TIPOS_PECAS[] = {'I', 'O', 'T', 'L'};
static const int NUM_TIPOS = 4;

Peca gerarPeca(int id) {
    Peca p;
    p.id = id;
    p.nome = TIPOS_PECAS[rand() % NUM_TIPOS];
    return p;
}

void exibirPeca(Peca p) {
    printf("[%c %d] ", p.nome, p.id);
}