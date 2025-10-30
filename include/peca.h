#ifndef PECA_H
#define PECA_H

/**
 * Estrutura que representa uma peça do Tetris
 */
typedef struct {
    char nome;  // Tipo da peça: 'I', 'O', 'T', 'L'
    int id;     // Identificador único da peça
} Peca;

/**
 * Gera uma nova peça com tipo aleatório
 * @param id Identificador único da peça
 * @return Nova peça gerada
 */
Peca gerarPeca(int id);

/**
 * Exibe informações de uma peça
 * @param p Peça a ser exibida
 */
void exibirPeca(Peca p);

#endif // PECA_H