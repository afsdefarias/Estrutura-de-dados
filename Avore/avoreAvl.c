/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/

#include <stdio.h>
#include <stdlib.h>
#include "avoreAvl.h"

struct desc_avl * CreateAVL(void){
    struct desc_avl * base = (struct desc_avl *) malloc(sizeof(struct desc_avl));
    base->tamanho = 0;
    base->raiz = NULL;
    printf("\n\nLista criada com sucesso.\n");
    return base;
}
struct nodo * inNodo(void){
    struct nodo * nodinho = (struct nodo*)malloc(sizeof(struct nodo));
    nodinho->pai = NULL;
    nodinho->esq = NULL;
    nodinho->dir = NULL;
    nodinho->chave = 0;
    nodinho->fator = 0;
    return nodinho;
}
struct nodo * nodoADD(struct desc_avl * inAVL, struct nodo * inNodo){

}