#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define NAVIO 3
#define AGUA 0

int main() {
    // Matriz que representa o tabuleiro 10x10
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Inicializa todas as posições do tabuleiro com água (0)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posição inicial do navio horizontal
    int linhaH = 2, colunaH = 4;

    // Validação: o navio horizontal precisa caber na linha
    if (colunaH + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            tabuleiro[linhaH][colunaH + i] = NAVIO;
        }
    } else {
        printf("Erro: navio horizontal fora dos limites!\n");
    }

    // Posição inicial do navio vertical
    int linhaV = 5, colunaV = 1;

    // Validação: o navio vertical precisa caber na coluna
    if (linhaV + TAMANHO_NAVIO <= TAMANHO_TABULEIRO) {
        int sobreposicao = 0;
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linhaV + i][colunaV] == NAVIO) {
                sobreposicao = 1;
                break;
            }
        }

        if (!sobreposicao) {
            for (int i = 0; i < TAMANHO_NAVIO; i++) {
                tabuleiro[linhaV + i][colunaV] = NAVIO;
            }
        } else {
            printf("Erro: sobreposição com outro navio!\n");
        }
    } else {
        printf("Erro: navio vertical fora dos limites!\n");
    }

    // Exibe o tabuleiro
    printf("\nTabuleiro de Batalha Naval (0 = água, 3 = navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}
