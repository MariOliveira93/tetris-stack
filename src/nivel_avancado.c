#include "nivel_avancado.h"
#include "fila.h"
#include "pilha.h"
#include "peca.h"
#include <stdio.h>

static void exibirMenu() {
    printf("\n--- Opcoes Disponiveis ---\n");
    printf("1 - Jogar peca da frente da fila\n");
    printf("2 - Enviar peca da fila para a pilha de reserva\n");
    printf("3 - Usar peca da pilha de reserva\n");
    printf("4 - Trocar peca da frente da fila com o topo da pilha\n");
    printf("5 - Trocar os 3 primeiros da fila com as 3 pecas da pilha\n");
    printf("0 - Sair\n");
    printf("Opcao escolhida: ");
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

/**
 * Troca a peça da frente da fila com o topo da pilha
 */
static void trocarPecaAtual(FilaPecas *fila, PilhaPecas *pilha) {
    if (filaVazia(fila)) {
        printf("\nErro: Fila vazia!\n");
        return;
    }
    
    if (pilhaVazia(pilha)) {
        printf("\nErro: Pilha vazia!\n");
        return;
    }
    
    Peca pecaFila, pecaPilha;
    
    // Remove da fila e da pilha
    desenfileirar(fila, &pecaFila);
    desempilhar(pilha, &pecaPilha);
    
    // Coloca a peça da pilha na frente da fila
    // e a peça da fila no topo da pilha
    
    // Para colocar na frente da fila, precisamos ajustar o índice
    fila->frente = (fila->frente - 1 + TAMANHO_FILA) % TAMANHO_FILA;
    fila->pecas[fila->frente] = pecaPilha;
    fila->tamanho++;
    
    empilhar(pilha, pecaFila);
    
    printf("\nAcao: Troca realizada entre a frente da fila e o topo da pilha.\n");
}

/**
 * Troca as 3 primeiras peças da fila com as 3 peças da pilha
 */
static void trocaMultipla(FilaPecas *fila, PilhaPecas *pilha) {
    if (fila->tamanho < 3) {
        printf("\nErro: Fila precisa ter pelo menos 3 pecas!\n");
        return;
    }
    
    if (pilha->topo + 1 < 3) {
        printf("\nErro: Pilha precisa ter pelo menos 3 pecas!\n");
        return;
    }
    
    Peca pecasFila[3];
    Peca pecasPilha[3];
    
    // Remove 3 peças da fila
    for (int i = 0; i < 3; i++) {
        desenfileirar(fila, &pecasFila[i]);
    }
    
    // Remove 3 peças da pilha
    for (int i = 0; i < 3; i++) {
        desempilhar(pilha, &pecasPilha[i]);
    }
    
    // Coloca as peças da pilha na fila (na mesma ordem que foram retiradas da pilha)
    for (int i = 0; i < 3; i++) {
        fila->frente = (fila->frente - 1 + TAMANHO_FILA) % TAMANHO_FILA;
        fila->pecas[fila->frente] = pecasPilha[i];
        fila->tamanho++;
    }
    
    // Coloca as peças da fila na pilha (na ordem inversa para manter a lógica)
    for (int i = 2; i >= 0; i--) {
        empilhar(pilha, pecasFila[i]);
    }
    
    printf("\nAcao: Troca realizada entre os 3 primeiros da fila e os 3 da pilha.\n");
}

void executarNivelAvancado() {
    FilaPecas fila;
    PilhaPecas pilha;
    int proximoId = 0;
    int opcao;
    
    printf("\n========================================\n");
    printf("   TETRIS STACK - NIVEL AVANCADO\n");
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
            
            case 4: { // Trocar peça atual
                trocarPecaAtual(&fila, &pilha);
                break;
            }
            
            case 5: { // Troca múltipla
                trocaMultipla(&fila, &pilha);
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