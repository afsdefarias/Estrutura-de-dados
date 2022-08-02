/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/

#include <stdio.h>
#include <stdlib.h>
#include "avoreAvl.h"
void bn(void) {
    printf("\n");
}

struct desc_avl * CreateAVL(void){
    struct desc_avl * vaso = (struct desc_avl *) malloc(sizeof(struct desc_avl));
    vaso->tamanho = 0;
    vaso->raiz = NULL;
    printf("\n\n Alocado com sucesso.\n");
    return vaso;
}
struct nodo * inNodo(int key){
    struct nodo * galho = (struct nodo*)malloc(sizeof(struct nodo));
    galho->pai = NULL;
    galho->esq = NULL;
    galho->dir = NULL;
    galho->chave = key;
    galho->fator = 0;
    return galho;
}
struct desc_avl * nodoADD(struct desc_avl * vaso, struct nodo * folha){
    if(vaso->raiz==NULL && vaso->tamanho==0){ // Não tem raiz
        vaso->raiz = folha;
        bn();
        printf("Raiz criada. (%i)\n", vaso->raiz->chave);
        return vaso;
    }else if(folha->chave > 10){
        bn();
        printf("Chave direita\n");
        return vaso;
    }else if(folha->chave < 10) {
        bn();
        printf("Chave Esquerda\n");
        return vaso;
    }else{
        bn();
        printf("Chave Igual\n");
    }
}