#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "nivel_basico.h"
#include "nivel_intermediario.h"
#include "nivel_avancado.h"

/**
 * Exibe o menu principal de seleção de nível
 */
void exibirMenuPrincipal() {
    printf("\n========================================\n");
    printf("        TETRIS STACK SIMULATOR\n");
    printf("========================================\n");
    printf("Selecione o nivel do desafio:\n");
    printf("1 - Nivel Basico (Apenas Fila)\n");
    printf("2 - Nivel Intermediario (Fila + Pilha)\n");
    printf("3 - Nivel Avancado (Fila + Pilha + Trocas)\n");
    printf("0 - Sair\n");
    printf("========================================\n");
    printf("Opcao: ");
}

int main() {
    int opcao;

    // Inicializa o gerador de números aleatórios
    srand(time(NULL));

    do {
        exibirMenuPrincipal();
        scanf("%d", &opcao);

        switch (opcao) {
        case 1:
            executarNivelBasico();
            break;

        case 2:
            executarNivelIntermediario();
            break;

        case 3:
            executarNivelAvancado();
            break;

        case 0:
            printf("\nObrigado por jogar Tetris Stack!\n");
            break;

        default:
            printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}