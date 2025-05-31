#include <stdio.h>

#define TAMANHO_TABULEIRO 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

int main() {
    // ---------- Declaração e inicialização do tabuleiro ----------
    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO];

    // Preenche o tabuleiro com 0 (água)
    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            tabuleiro[i][j] = VALOR_AGUA;
        }
    }

    // ---------- Navios (vetores apenas para referência) ----------
    int navio_horizontal[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};
    int navio_vertical[TAMANHO_NAVIO] = {VALOR_NAVIO, VALOR_NAVIO, VALOR_NAVIO};

    // ---------- Coordenadas dos navios ----------
    // Navio horizontal: linha fixa, colunas consecutivas
    int linha_horizontal = 2;
    int coluna_inicial_horizontal = 4;

    // Navio vertical: coluna fixa, linhas consecutivas
    int coluna_vertical = 6;
    int linha_inicial_vertical = 6;

    // ---------- Validação de limites ----------
    if (coluna_inicial_horizontal + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio horizontal ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    if (linha_inicial_vertical + TAMANHO_NAVIO > TAMANHO_TABULEIRO) {
        printf("Erro: navio vertical ultrapassa os limites do tabuleiro.\n");
        return 1;
    }

    // ---------- Verificação de sobreposição ----------
    int sobreposicao = 0;
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        if (tabuleiro[linha_horizontal][coluna_inicial_horizontal + i] == VALOR_NAVIO ||
            tabuleiro[linha_inicial_vertical + i][coluna_vertical] == VALOR_NAVIO) {
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao) {
        printf("Erro: os navios se sobrepõem!\n");
        return 1;
    }

    // ---------- Posicionamento dos navios ----------
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        tabuleiro[linha_horizontal][coluna_inicial_horizontal + i] = navio_horizontal[i]; // Horizontal
        tabuleiro[linha_inicial_vertical + i][coluna_vertical] = navio_vertical[i];       // Vertical
    }

    // ---------- Exibição do tabuleiro ----------
    printf("Tabuleiro de Batalha Naval (0 = Água | 3 = Navio):\n\n");

    for (int i = 0; i < TAMANHO_TABULEIRO; i++) {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }

    return 0;
}