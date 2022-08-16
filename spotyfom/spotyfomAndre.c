/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
#include <stdio.h>
#include <stdlib.h>
#include "spotyfomAndre.h"
#include <string.h>
#include <time.h>
// ################################# PILHA ###########################################
struct desc_Pilha * startPilha(void){
    struct desc_Pilha * base=(struct desc_Pilha *)malloc(sizeof(struct desc_Pilha));
    base->tamanho = 0;
    base->Pilha = NULL;
    strcpy(base->playlist, "Pilha");
    return base;
}
struct desc_Pilha * push(struct desc_Pilha *base, struct nodo *noMusica){
    struct nodo * aux = NULL;
    if((base->tamanho==0) && (base->Pilha==NULL)){
        base->Pilha = noMusica;
        base->tamanho++;
        return base;
    }else{
        aux = base->Pilha;
        base->Pilha = noMusica;
        noMusica->prox = aux;
        base->tamanho++;
        return base;
    }
}
struct desc_Pilha * playPop(struct desc_LSE **base, struct desc_Pilha *basePilha) {
//struct desc_Pilha * playPop(struct desc_Pilha *basePilha){
    if((basePilha->tamanho==0) && (basePilha->Pilha==NULL)){
        printf("A lista esta vazia.\n");
        return basePilha;
    }else{
        struct nodo *aux = NULL;
        struct nodo *atua = NULL;
        while (basePilha->tamanho != 0) {
            atualizaExecucao(*base,basePilha->Pilha->info->codigo);
            imprimeMusica(basePilha->Pilha);
            basePilha->Pilha = basePilha->Pilha->prox;
            basePilha->tamanho--;
        }
        return basePilha;
    }
}
// ###################################################################################
// ################################## FILA ###########################################
struct  desc_queue * criaDescQueue(void){
    struct desc_queue * baseFila=(struct desc_queue *)malloc(sizeof(struct desc_queue));
    baseFila->tamanho = 0;
    baseFila->head = NULL;
    baseFila->tail = NULL;
    strcpy(baseFila->playlist, "FILA");
    return baseFila;
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
struct desc_queue * playDequeue(struct desc_LSE **base, struct desc_queue * baseFila){
    if((baseFila->tamanho==0) && (baseFila->head==NULL)){
        printf("A lista esta vazia.\n");
        return baseFila;
    }else {
        while (baseFila->tamanho != 0) {
            atualizaExecucao(*base, baseFila->head->info->codigo);
            imprimeMusica(baseFila->head);
            baseFila->head = baseFila->head->prox;
            if (baseFila->tamanho > 1) baseFila->head->ant = NULL;
            baseFila->tamanho--;
        }
        return baseFila;
    }
}
// ###################################################################################
struct desc_LSE * startLista(void){
    struct desc_LSE * base=(struct desc_LSE *)malloc(sizeof(struct desc_LSE));
    base->tamanho = 0;
    base->LSE=NULL;
    return base;
}

struct nodo * inNodo(struct musica *muss){
    struct nodo * listaMuisca = (struct nodo*)malloc(sizeof(struct nodo));
    listaMuisca->info = muss;
    listaMuisca->ant = NULL;
    listaMuisca->prox = NULL;
    return listaMuisca;
}

struct musica * inMuss(char *tituloInf, char *artistaInf, char *letraInf, int codigoInf, int execucoesInf){
    struct musica * iMuss = (struct musica*)malloc(sizeof(struct musica));
    strcpy(iMuss->titulo, tituloInf);
    strcpy(iMuss->artista, artistaInf);
    strcpy(iMuss->letra, letraInf);
    iMuss->codigo = (int)codigoInf;
    iMuss->execucoes = (int)execucoesInf;
    return iMuss;
}

struct desc_LSE * novaMusica(struct desc_LSE *base, struct nodo *noMusica, int posicao){
    struct nodo * aux = NULL;
    struct nodo * atua = NULL;

    if((base->tamanho==0) && (base->LSE==NULL)){
        base->LSE = noMusica;
        base->tamanho++;
        return base;
    }else{
        if(posicao==1){
            aux = base->LSE;
            base->LSE = noMusica;
            noMusica->prox = aux;
            base->tamanho++;
            return base;
        }
        if(base->tamanho >= posicao){
            int anda = 2;
            aux = base->LSE;
            while (anda != posicao){
                aux = aux->prox;
                anda++;
            }
            atua = aux->prox;
            aux->prox = noMusica;
            noMusica->prox = atua;
            base->tamanho++;
            return base;
        }
        else{
            aux = base->LSE;
            while (aux->prox != NULL){
                aux = aux->prox;
            }
            atua = aux->prox;
            aux->prox = noMusica;
            noMusica->prox = atua;
            base->tamanho++;
            return base;
        }
    }
}

void * buscaPtitulo(struct desc_LSE *base, char *titu){
    int pagina = 0;
    int posi = 0;
    printf("|| CODIGO | TITULO | ARTISTA | TRECHO ||\n");
    if((base->tamanho==0) && (base->LSE==NULL)){
        printf("A lista esta vazia.\n");
        return base;
    }
    struct nodo *aux = base->LSE;
    do{
        if (strcmp(aux->info->titulo, titu)==0) {
            imprimeMusica(aux);
            if (pagina == 250) {
                setbuf(stdin, NULL);
                printf("--------------------------------------------------------------------------------------------------\n");
                printf("\n\n\t (%i) Pressione qualquer tecla para continuar \n\n", posi = posi + 250);
                getchar();
                pagina = 0;
            }
            pagina++;
        }
        aux = aux->prox;
    }while (aux != NULL);
    return 0;
}
void * buscaPArtista(struct desc_LSE *base, char *art){
    int pagina = 0;
    int posi = 0;
    printf("|| CODIGO | TITULO | ARTISTA | TRECHO ||\n");
    if((base->tamanho==0) && (base->LSE==NULL)){
        printf("A lista esta vazia.\n");
        return base;
    }
    struct nodo *aux = base->LSE;
    do{
        if (strcmp(aux->info->artista, art)==0) {
            imprimeMusica(aux);
            if (pagina == 250) {
                setbuf(stdin, NULL);
                printf("--------------------------------------------------------------------------------------------------\n");
                printf("\n\n\t (%i) Pressione qualquer tecla para continuar \n\n", posi = posi + 250);
                getchar();
                pagina = 0;
            }
            pagina++;
        }
        aux = aux->prox;
    }while (aux != NULL);
    return 0;
}
void * buscaPCodigo(struct desc_LSE *base, int codigo){
    int pagina = 0;
    int posi = 0;
    printf("|| CODIGO | TITULO | ARTISTA | TRECHO ||\n");
    if((base->tamanho==0) && (base->LSE==NULL)){
        printf("A lista esta vazia.\n");
        return base;
    }
    struct nodo *aux = base->LSE;
    do{
        if (aux->info->codigo == codigo) {
            imprimeMusica(aux);
            if (pagina == 250) {
                setbuf(stdin, NULL);
                printf("--------------------------------------------------------------------------------------------------\n");
                printf("\n\n\t (%i) Pressione qualquer tecla para continuar \n\n", posi = posi + 250);
                getchar();
                pagina = 0;
            }
            pagina++;
        }
        aux = aux->prox;
    }while (aux != NULL);
    return 0;
}
void * imprimeLista(struct desc_LSE *base){
    int pagina = 0;
    int posi = 0;
    printf("|| CODIGO | TITULO | ARTISTA | TRECHO ||\n");
    if((base->tamanho==0) && (base->LSE==NULL)){
        printf("A lista esta vazia.\n");
        return base;
    }
    struct nodo *aux = base->LSE;
    do{
        imprimeMusica(aux);
        if(pagina==250) {
            setbuf(stdin, NULL);
            printf("--------------------------------------------------------------------------------------------------\n");
            printf("\n\n\t (%i) Pressione qualquer tecla para continuar \n\n", posi=posi+250);
            getchar();
            pagina = 0;
        }pagina++;
        aux = aux->prox;
    }while (aux != NULL);
    return 0;
}
void * imprimeFila(struct desc_queue *base){
    printf("--------------------------    Playlist %s       -------------------------------\n", base->playlist);
    printf("|| CODIGO | TITULO | ARTISTA | TRECHO ||\n");
    if((base->tamanho==0) && (base->head==NULL)){
        printf("A lista esta vazia.\n");
        return base;
    }
    struct nodo *aux = base->head;
    do{
        imprimeMusica(aux);
        aux = aux->prox;
    }while (aux != NULL);
    return 0;
}
void * imprimeMusica(struct nodo *aux){
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("|| %i | %s | %s | %s | %d ||\n", aux->info->codigo, aux->info->titulo, aux->info->artista, aux->info->letra, aux->info->execucoes);
    return 0;
}
struct desc_LSE * limpalista(struct desc_LSE *base){
    free(base);
    return base;
}
struct desc_queue * filaAleatoria(struct  desc_LSE *base, struct desc_queue *baseFila, int qta){

    struct musica *inMusica;
    struct nodo *noMusica;
    struct nodo * aux = NULL;
    int i, posicao;
    i = posicao = 0;

    srand(time(NULL));
    while( i != qta ){
        posicao = rand() % base->tamanho;
        struct nodo *aux = base->LSE;
        int anda = 1;
        while (anda != posicao) {
            aux = aux->prox;
            anda++;
        }
        inMusica = inMuss(aux->info->titulo,aux->info->artista,aux->info->letra,aux->info->codigo, aux->info->execucoes);
        noMusica = inNodo(inMusica);
        baseFila = enqueue( noMusica, baseFila);
        imprimeMusica(noMusica);
        i++;
    }
    return baseFila;
}
struct desc_Pilha * pilhaPersonalizado(struct  desc_LSE *base, struct desc_Pilha *basePilha, int codigo){

    struct musica *inMusica;
    struct nodo *noMusica;
    struct nodo *aux = base->LSE;
    int i, posicao;
    i = posicao = 0;
    do{
        if (aux->info->codigo == codigo) {
            imprimeMusica(aux);
            inMusica = inMuss(aux->info->titulo,aux->info->artista,aux->info->letra,aux->info->codigo, aux->info->execucoes);
            noMusica = inNodo(inMusica);
            basePilha = push( basePilha, noMusica);
        }
        aux = aux->prox;
    }while (aux != NULL);
    return basePilha;
}
void * imprimePilha(struct desc_Pilha *base){
    struct nodo *aux = base->Pilha;
    printf("--------------------------    Playlist %s       -------------------------------\n", base->playlist);
    printf("|| CODIGO | TITULO | ARTISTA | TRECHO ||\n");
    if((base->tamanho==0) && (base->Pilha==NULL)){
        printf("A lista esta vazia.\n");
        return base;
    }
    while (aux != NULL){
        imprimeMusica(aux);
        aux = aux->prox;
    }
    return 0;
}

void ** atualizaExecucao(struct desc_LSE *base, int codigo){
    struct nodo *aux = base->LSE;
    int anda = base->tamanho;
    while (anda != 0){
        if (aux->info->codigo == codigo) {
            aux->info->execucoes = aux->info->execucoes + 1;
        }
        aux = aux->prox;
        anda--;
    }
    return 0;
}