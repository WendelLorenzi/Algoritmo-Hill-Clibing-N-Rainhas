#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Func.h"

//Número de rainhas
int n;

int main(int argc, char const *argv[])
{
    //Pegando a quantidade de rainhas pelo teclado
    printf("\nQuantidade de Rainhas: \t");
    scanf("%i%*c", &n);

    while(n < 4){
        printf("\nNao existe solucao pra menos de 4 rainhas");
        printf("\nQuantidade de Rainhas: \t");
        scanf("%i%*c", &n);
    }

    int *tabuleiro = malloc(n * sizeof(int));

    geraAleatorio(tabuleiro);

    impTabuleiro(tabuleiro);
    printf("Quantidade de ataques no tabuleiro inicial: %i", contAtk(tabuleiro));

    Fila *teste = (Fila*) malloc(sizeof(Fila));
    teste->ini = NULL;
    teste->fim = NULL;
    
    int *resultado = resolveRainhas(tabuleiro);
    impTabuleiro(resultado);
    printf("Quantidade de ataques no tabuleiro final: %i", contAtk(resultado));
    printf("\n");

    return 0;
}
