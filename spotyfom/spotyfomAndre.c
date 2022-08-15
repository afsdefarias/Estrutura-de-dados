/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
#include <stdio.h>
#include <stdlib.h>
#include "spotyfomAndre.h"
#include <string.h>

struct desc_LSE * startLista(void){
    struct desc_LSE * base=(struct desc_LSE *)malloc(sizeof(struct desc_LSE));
    base->tamanho = 0;
    base->LSE=NULL;
    return base;
}

struct nodo * inNodo(struct musica *muss){
    struct nodo * listaMuisca = (struct nodo*)malloc(sizeof(struct nodo));
    listaMuisca->info = muss;
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
// ################################# PILHA ###########################################
struct  desc_queue * criaDescQueue(void){
    struct desc_queue * basePilha=(struct desc_queue *)malloc(sizeof(struct desc_queue));
    basePilha->tamanho = 0;
    basePilha->head = NULL;
    basePilha->tail = NULL;
    return basePilha;
}
// ###################################################################################
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
        printf("%s %d %s %d\n", aux->info->titulo, strlen(aux->info->titulo), titu, strlen(titu));
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
void * imprimeMusica(struct nodo *aux){
    printf("--------------------------------------------------------------------------------------------------\n");
    printf("|| %i | %s | %s | %s ||\n", aux->info->codigo, aux->info->titulo, aux->info->artista, aux->info->letra);
    return 0;
}
struct desc_LSE * limpalista(struct desc_LSE *base){
    free(base);
    return base;
}
