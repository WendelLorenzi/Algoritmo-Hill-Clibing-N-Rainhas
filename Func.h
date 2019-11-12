#ifndef _FUNC_H
#define _FUNC_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

typedef struct lista{
    int linha;
    struct lista *prox;
}Lista;

typedef struct fila{
    Lista *ini;
    Lista *fim;
}Fila;

void push(Fila *f, int posicao);

//Esvasia totalmente a fila
void limpa(Fila *f);

void impFila(Lista *l);

int aleatorio(Fila *f);

void geraAleatorio(int *tabuleiro);

void impTabuleiro(int *tabuleiro);

int contAtk(int *tabuleiro);

//Deixa tudo na posição em que acontece a menor quantidade de ataques
int *melhoraTabuleiro(int *tabuleiro);

bool tentaMelhora(int *tabuleiro);

int *resolveRainhas(int *tabuleiro);

#endif