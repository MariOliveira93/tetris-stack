#include "nivel_basico.h"
#include "fila.h"
#include "peca.h"
#include <stdio.h>

static void exibirMenu() {
    printf("\n--- Opcoes de Acao ---\n");
    printf("1 - Jogar peca (dequeue)\n");
    printf("2 - Inserir nova peca (enqueue)\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}

static void exibirEstado(FilaPecas *fila) {
    printf("\n=== Estado Atual ===\n");
    printf("Fila de pecas: ");
    exibirFila(fila);
    printf("\n");
}

void executarNivelBasico() {
    FilaPecas fila;
    int proximoId = 0;
    int opcao;
    
    printf("\n========================================\n");
    printf("   TETRIS STACK - NIVEL BASICO\n");
    printf("========================================\n");
    
    // Inicializa a fila com 5 peças
    inicializarFila(&fila, &proximoId);
    
    do {
        exibirEstado(&fila);
        exibirMenu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: { // Jogar peça
                Peca p;
                if (desenfileirar(&fila, &p)) {
                    printf("\nAcao: Peca jogada -> ");
                    exibirPeca(p);
                    printf("\n");
                    
                    // Adiciona nova peça ao final
                    Peca nova = gerarPeca(proximoId++);
                    enfileirar(&fila, nova);
                } else {
                    printf("\nErro: Fila vazia!\n");
                }
                break;
            }
            
            case 2: { // Inserir nova peça
                if (!filaCheia(&fila)) {
                    Peca nova = gerarPeca(proximoId++);
                    enfileirar(&fila, nova);
                    printf("\nAcao: Nova peca inserida -> ");
                    exibirPeca(nova);
                    printf("\n");
                } else {
                    printf("\nErro: Fila cheia! Jogue uma peca primeiro.\n");
                }
                break;
            }
            
            case 0:
                printf("\nEncerrando o jogo...\n");
                break;
                
            default:
                printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);
}