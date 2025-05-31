#include <stdio.h>

#define TAM_TAB 10
#define TAM_NAVIO 3
#define TAM_HABIL 5

#define AGUA 0
#define NAVIO 3
#define HABILIDADE 5

// Função para aplicar uma matriz de habilidade no tabuleiro
void aplicar_habilidade(int tabuleiro[TAM_TAB][TAM_TAB], int matriz[TAM_HABIL][TAM_HABIL], int origem_linha, int origem_coluna) {
    int offset = TAM_HABIL / 2;
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            int linha = origem_linha + i - offset;
            int coluna = origem_coluna + j - offset;
            if (linha >= 0 && linha < TAM_TAB && coluna >= 0 && coluna < TAM_TAB) {
                if (matriz[i][j] == 1 && tabuleiro[linha][coluna] != NAVIO) {
                    tabuleiro[linha][coluna] = HABILIDADE;
                }
            }
        }
    }
}

// Função para criar a matriz em forma de cone 
void criar_matriz_cone(int matriz[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            matriz[i][j] = 0;
        }
    }
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            if (j >= TAM_HABIL / 2 - i && j <= TAM_HABIL / 2 + i && i <= TAM_HABIL / 2)
                matriz[i][j] = 1;
        }
    }
}

// Função para criar a matriz em forma de cruz
void criar_matriz_cruz(int matriz[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            if (i == TAM_HABIL / 2 || j == TAM_HABIL / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para criar a matriz em forma de octaedro 
void criar_matriz_octaedro(int matriz[TAM_HABIL][TAM_HABIL]) {
    for (int i = 0; i < TAM_HABIL; i++) {
        for (int j = 0; j < TAM_HABIL; j++) {
            if (abs(i - TAM_HABIL / 2) + abs(j - TAM_HABIL / 2) <= TAM_HABIL / 2)
                matriz[i][j] = 1;
            else
                matriz[i][j] = 0;
        }
    }
}

// Função para exibir o tabuleiro
void exibir_tabuleiro(int tabuleiro[TAM_TAB][TAM_TAB]) {
    printf("Legenda: 0=Água | 3=Navio | 5=Habilidade\n\n");
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM_TAB][TAM_TAB];

    // Inicializa o tabuleiro com água
    for (int i = 0; i < TAM_TAB; i++) {
        for (int j = 0; j < TAM_TAB; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }

    // Posiciona os navios 
    for (int i = 0; i < TAM_NAVIO; i++) {
        tabuleiro[1][2 + i] = NAVIO; // horizontal
        tabuleiro[4 + i][7] = NAVIO; // vertical
        tabuleiro[0 + i][0 + i] = NAVIO; // diagonal principal
        tabuleiro[0 + i][9 - i] = NAVIO; // diagonal secundária
    }

    // Matrizes de habilidade
    int cone[TAM_HABIL][TAM_HABIL];
    int cruz[TAM_HABIL][TAM_HABIL];
    int octaedro[TAM_HABIL][TAM_HABIL];

    criar_matriz_cone(cone);
    criar_matriz_cruz(cruz);
    criar_matriz_octaedro(octaedro);

    // Aplicar as habilidades em pontos fixos
    aplicar_habilidade(tabuleiro, cone, 6, 2);      // Cone na posição (6,2)
    aplicar_habilidade(tabuleiro, cruz, 2, 5);      // Cruz na posição (2,5)
    aplicar_habilidade(tabuleiro, octaedro, 7, 7);  // Octaedro na posição (7,7)

    // Exibir o resultado final
    exibir_tabuleiro(tabuleiro);

    return 0;
}