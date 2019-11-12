#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "Func.h"

int n=0;

void push(Fila *f, int posicao){
    Lista *novo = (Lista*) malloc(sizeof(Lista));
    novo->linha = posicao;
    novo->prox = NULL;

    if(f->ini == NULL){
        f->ini = novo;
        f->fim = novo;
    }else{
        f->fim->prox = novo;
        f->fim = novo;
    }
}

//Esvasia totalmente a fila
void limpa(Fila *f){
    if(f->ini != NULL){
        Lista *old = f->ini;
        f->ini = f->ini->prox;
        if(f->ini == NULL){
            f->fim == NULL;
        }
            free(old);
        limpa(f);
    }
}

void impFila(Lista *l){
    if(l != NULL){
        printf("\n%i", l->linha);
        impFila(l->prox);
    }
}

int aleatorio(Fila *f){
    Lista *aux = f->ini;

    int tam = 0;
    while(aux != NULL){
		tam++;
        aux = aux->prox; 
	}
    
    aux = f->ini;

    srand ((unsigned)time(NULL)); 
    int sorteado = rand() % tam;
    
    for(int i = 0; i < sorteado; i++){
        aux = aux->prox;
    }
    return aux->linha;
}

void geraAleatorio(int *tabuleiro){
    srand((unsigned)time(NULL));
    for(int i = 0; i < n; i++){
        tabuleiro[i] = rand() % n;
    }
}

void impTabuleiro(int *tabuleiro){
    printf("\n\n");
    //linhas
    for(int i = 0; i < n; i++){
        //colunas
        for(int j = 0; j < n; j++){
            if(tabuleiro[j] == i){
                printf("| R ");
            }else{
                printf("| - ");
            }
        }
        printf("|\n");
    }
}

int contAtk(int *tabuleiro){
    //Conta quantos ataques estão ocorrendo
    int qtdAtk = 0;
    for (int i = 0; i < n - 1; i++){
        for (int j = i + 1; j < n; j++){
        	//verifica se está na mesma linha
            if (tabuleiro[i] == tabuleiro[j]){
                qtdAtk++;
                continue;
            }
            //verifica se está na mesma diagonal
            if (tabuleiro[i] - tabuleiro[j] == i - j){
                qtdAtk++;
                continue;
            }
            //verifica se esta na mesma diagonal
            if (tabuleiro[i] - tabuleiro[j] ==  j - i){
                qtdAtk++;
                continue;
            }
        }
    }
    return qtdAtk;
}

//Deixa tudo na posição em que acontece a menor quantidade de ataques
int *melhoraTabuleiro(int *tabuleiro){
    Fila *decisao = (Fila*) malloc(sizeof(Fila));
    decisao->ini = NULL;
    decisao->fim = NULL;

    int qtdAtk, k;

    //Quantidade de ataques no tabuleiro original
    int atkOri = contAtk(tabuleiro);

    int *tab2 = malloc(n * sizeof(int));

    //Criando cópia do tabuleiro
    for(int i = 0; i < n; i++){
        tab2[i] = tabuleiro[i];
    }

    for(int i = 0; i < n; i++){
        limpa(decisao);
        push(decisao, tab2[i]);

        for(int j = 0; j < n; j++){
            //Testa a quantidade de ataques para todas as posições da coluna, escolhendo como posição final o local com menos ataques
            tab2[i] = j;

            //k é o número de ataques para a nova posição
            k = contAtk(tab2);

            //Se a quantidade de ataques para a nova posição for igual, não faz diferença
            if(k == atkOri){
                push(decisao, j);
            }

            //Neste caso temos uma posição melhor que a original
            if(k < atkOri){
                limpa(decisao);
                push(decisao, j);
                atkOri = k;
            }
        }

        //Caso tenha mais de uma casa com a mesma quantidade de ataques, escolhe uma aleatória
        tab2[i] = aleatorio(decisao);
    }

    return(tab2);
}

bool tentaMelhora(int *tabuleiro){
    //Quantidade de ataques no tabuleiro original
    int atkOri = contAtk(tabuleiro);

    int *tentativa = melhoraTabuleiro(tabuleiro);
    int novoAtk = contAtk(tentativa);

    //Verifica se o novo tabuleiro tem menos ataques que o original
    if(novoAtk < atkOri){
        for(int i = 0; i < n; i++){
            tabuleiro[i] = tentativa[i];
        }

        //Tabuleiro melhor encontrado
        return true;
    }

    //Não foi possível encontrar um tabuleiro melhor
    return false;
}

int *resolveRainhas(int *tabuleiro){
    while(contAtk(tabuleiro) != 0){
        if(tentaMelhora(tabuleiro) == false){
            return(tabuleiro);
        }
    }

    return(tabuleiro);
}