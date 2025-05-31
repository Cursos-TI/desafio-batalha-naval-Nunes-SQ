#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    // ---------- Inicializa o tabuleiro 10x10 com água (0) ----------
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // ---------- Coordenadas e direções dos navios ----------
    // Navio 1 - Horizontal
    int linha_horizontal = 1;
    int coluna_horizontal = 2;

    // Navio 2 - Vertical
    int linha_vertical = 4;
    int coluna_vertical = 7;

    // Navio 3 - Diagonal Principal (↘)
    int linha_diag_principal = 0;
    int coluna_diag_principal = 0;

    // Navio 4 - Diagonal Secundária (↙)
    int linha_diag_secundaria = 0;
    int coluna_diag_secundaria = 9;

    // ---------- Função de verificação de sobreposição ----------
    int sobreposicao = 0;

    // Valida horizontal
    if (coluna_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        sobreposicao = 1;
    else {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_horizontal][coluna_horizontal + i] == VALOR_NAVIO)
                sobreposicao = 1;
        }
    }

    // Valida vertical
    if (linha_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        sobreposicao = 1;
    else {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_vertical + i][coluna_vertical] == VALOR_NAVIO)
                sobreposicao = 1;
        }
    }

    // Valida diagonal principal (↘)
    if (linha_diag_principal + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        coluna_diag_principal + TAMANHO_NAVIO > TAMANHO_TABULEIRO)
        sobreposicao = 1;
    else {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_diag_principal + i][coluna_diag_principal + i] == VALOR_NAVIO)
                sobreposicao = 1;
        }
    }

    // Valida diagonal secundária (↙)
    if (linha_diag_secundaria + TAMANHO_NAVIO > TAMANHO_TABULEIRO ||
        coluna_diag_secundaria - (TAMANHO_NAVIO - 1) < 0)
        sobreposicao = 1;
    else {
        for (int i = 0; i < TAMANHO_NAVIO; i++) {
            if (tabuleiro[linha_diag_secundaria + i][coluna_diag_secundaria - i] == VALOR_NAVIO)
                sobreposicao = 1;
        }
    }

    // Se houver sobreposição ou fora dos limites, encerrar
    if (sobreposicao) {
        printf("Erro: sobreposição ou posição inválida dos navios!\n");
        return 1;
    }

    // ---------- Posicionamento dos navios ----------
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_horizontal + i] = VALOR_NAVIO;
        tabuleiro[linha_vertical + i][coluna_vertical] = VALOR_NAVIO;
        tabuleiro[linha_diag_principal + i][coluna_diag_principal + i] = VALOR_NAVIO;
        tabuleiro[linha_diag_secundaria + i][coluna_diag_secundaria - i] = VALOR_NAVIO;
    }

    // ---------- Exibição do tabuleiro ----------
    printf("Tabuleiro Batalha Naval (0 = Água | 3 = Navio):\n\n");
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;