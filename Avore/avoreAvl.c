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
struct nodo * nodoADD(struct nodo * raiz, struct nodo * folha, struct nodo *pai){
    if(raiz==NULL){ // Não tem raiz
        bn();
        folha->pai = pai;
        return folha;
    }else if(folha->chave > raiz->chave){
        bn();
        printf("Chave direita\n");
        raiz->dir = nodoADD(raiz->dir, folha, raiz);
        return raiz;
    }else if(folha->chave < raiz->chave) {
        bn();
        printf("Chave Esquerda\n");
        raiz->esq = nodoADD(raiz->esq, folha, raiz);
        return raiz;
    }else{
        bn();
        printf("Chave Igual\n");
    }
}
void preOrdem(struct nodo * raiz){
    if(raiz == NULL) return;
    else{
        printf("%d ", raiz->chave);
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
        return;
    }
}
void posOrdem(struct nodo * raiz){
    if(raiz == NULL) return;
    else{
        preOrdem(raiz->esq);
        preOrdem(raiz->dir);
        printf("%d ", raiz->chave);
        return;
    }
}