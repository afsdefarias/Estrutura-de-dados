/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
#include <stdio.h>
#include <stdlib.h>
#include "listaMusica.h"
#include <string.h>

struct desc_Pilha * startPilha(void){
	struct desc_Pilha * base=(struct desc_Pilha *)malloc(sizeof(struct desc_Pilha));
	base->tamanho = 0;
	base->Pilha = NULL;
    printf("\n\nLista criada com sucesso.\n");
	return base;
}

struct nodo * inNodo(struct musica *muss){
	struct nodo * listaMuisca = (struct nodo*)malloc(sizeof(struct nodo));
	listaMuisca->info = muss;
	listaMuisca->prox = NULL;
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
struct desc_Pilha * pop(struct desc_Pilha *base) {
    if(empty(base)){
        printf("A lista esta vazia.\n");
        return base;
    }else{
        struct nodo *aux = NULL;
        struct nodo *atua = NULL;
        base->Pilha = base->Pilha->prox;
        base->tamanho--;
        return base;
    }
}
int empty(struct desc_Pilha *base){
    if((base->tamanho==0) && (base->Pilha==NULL)){
        return 1;
    }else{
        return 0;
    }
}
void * TOP(struct desc_Pilha *base){
    imprimeMusica(base->Pilha);
    return 0;
}
void * imprimeLista(struct desc_Pilha *base){
    printf("titulo - artista - letra - codigo\n");
    if(empty(base)){
        printf("A lista esta vazia.\n");
        return base;
    }
    struct nodo *aux = base->Pilha;
    	while (aux != NULL){
            imprimeMusica(aux);
            aux = aux->prox;
		}
	return 0;
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
struct desc_Pilha * limpalista(struct desc_Pilha *base){
    free(base);
    return base;
}