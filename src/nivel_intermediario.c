#include "nivel_intermediario.h"
#include "fila.h"
#include "pilha.h"
#include "peca.h"
#include <stdio.h>

static void exibirMenu() {
    printf("\n--- Opcoes de Acao ---\n");
    printf("1 - Jogar peca\n");
    printf("2 - Reservar peca\n");
    printf("3 - Usar peca reservada\n");
    printf("0 - Sair\n");
    printf("Opcao: ");
}

static void exibirEstado(FilaPecas *fila, PilhaPecas *pilha) {
    printf("\n=== Estado Atual ===\n");
    printf("Fila de pecas: ");
    exibirFila(fila);
    printf("\n");
    printf("Pilha de reserva (Topo -> Base): ");
    exibirPilha(pilha);
    printf("\n");
}

void executarNivelIntermediario() {
    FilaPecas fila;
    PilhaPecas pilha;
    int proximoId = 0;
    int opcao;
    
    printf("\n========================================\n");
    printf("   TETRIS STACK - NIVEL INTERMEDIARIO\n");
    printf("========================================\n");
    
    // Inicializa as estruturas
    inicializarFila(&fila, &proximoId);
    inicializarPilha(&pilha);
    
    do {
        exibirEstado(&fila, &pilha);
        exibirMenu();
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1: { // Jogar peça
                Peca p;
                if (desenfileirar(&fila, &p)) {
                    printf("\nAcao: Peca jogada -> ");
                    exibirPeca(p);
                    printf("\n");
                    
                    // Adiciona nova peça ao final da fila
                    Peca nova = gerarPeca(proximoId++);
                    enfileirar(&fila, nova);
                } else {
                    printf("\nErro: Fila vazia!\n");
                }
                break;
            }
            
            case 2: { // Reservar peça
                if (pilhaCheia(&pilha)) {
                    printf("\nErro: Pilha de reserva cheia!\n");
                } else {
                    Peca p;
                    if (desenfileirar(&fila, &p)) {
                        empilhar(&pilha, p);
                        printf("\nAcao: Peca reservada -> ");
                        exibirPeca(p);
                        printf("\n");
                        
                        // Adiciona nova peça ao final da fila
                        Peca nova = gerarPeca(proximoId++);
                        enfileirar(&fila, nova);
                    } else {
                        printf("\nErro: Fila vazia!\n");
                    }
                }
                break;
            }
            
            case 3: { // Usar peça reservada
                Peca p;
                if (desempilhar(&pilha, &p)) {
                    printf("\nAcao: Peca reservada usada -> ");
                    exibirPeca(p);
                    printf("\n");
                } else {
                    printf("\nErro: Pilha de reserva vazia!\n");
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