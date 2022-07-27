/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
#include <stdio.h>
#include <stdlib.h>
#include "listaMusica.h"
#include <string.h>

struct  desc_queue * criaDescQueue(void){
    struct desc_queue * base=(struct desc_queue *)malloc(sizeof(struct desc_queue));
    base->tamanho = 0;
    base->head = NULL;
    base->tail = NULL;
    printf("\n\nLista criada com sucesso.\n");
    return base;
}
struct nodo * inNodo(struct musica *muss){
    struct nodo * listaMuisca = (struct nodo*)malloc(sizeof(struct nodo));
    listaMuisca->info = muss;
    listaMuisca->prox = NULL;
    listaMuisca->ant = NULL;
    return listaMuisca;
}
struct musica * inMuss(char *tituloInf, char *artistaInf, char *letraInf, char *generoInf, int anoInf, int execucoesInf){
    struct musica * iMuss = (struct musica*)malloc(sizeof(struct musica));
    strcpy(iMuss->titulo, tituloInf);
    strcpy(iMuss->artista, artistaInf);
    strcpy(iMuss->letra, letraInf);
    strcpy(iMuss->genero, generoInf);
    iMuss->ano = (int)anoInf;
    iMuss->execucoes = (int)execucoesInf;
    return iMuss;
}
struct desc_queue * enqueue(struct nodo * nNodo, struct desc_queue * base){
    struct nodo * aux = NULL;
    if((base->tamanho==0) && (base->head)==NULL){
        base->head = nNodo;
        base->tail = nNodo;
        base->tamanho++;
        return base;
    }else{
        aux = base->tail;
        aux->prox = nNodo;
        aux->prox->ant = aux;
        base->tail = nNodo;
        base->tamanho++;
        return base;
    }
}
struct desc_queue * delete(struct desc_queue * base){
    base->tamanho = 0;
    base->head = NULL;
    base->tail = NULL;
    printf("\n\nLista limpa com sucesso.\n");
    return base;
}
struct desc_queue * dequeue(struct desc_queue * base){
    imprimeMusica(base->head);
    base->head = base->head->prox;
    base->head->ant = NULL;
    base->tamanho--;
    return base;
}
void * imprimeLista(struct desc_queue *base){
    printf("\ntitulo - artista - letra - codigo\n");
    struct nodo *aux = base->head;
    while (aux != NULL){
        imprimeMusica(aux);
        aux = aux->prox;
    }
    return 0;
}
int empty(struct desc_queue *base){
    if((base->tamanho==0) && (base->head==NULL) && (base->tail==NULL)){
        return 1;
    }else{
        return 0;
    }
}
void lenght(struct desc_queue *base){
    printf("\nTamanho: %d\n", base->tamanho);
}
void * imprimeMusica(struct nodo *aux){
    printf("%s - ", aux->info->titulo);
    printf("%s - ", aux->info->artista);
    printf("%s - ", aux->info->letra);
    printf("%s - ", aux->info->genero);
    printf("%d - ", aux->info->ano);
    printf("%d\n", aux->info->execucoes);
    return 0;
}