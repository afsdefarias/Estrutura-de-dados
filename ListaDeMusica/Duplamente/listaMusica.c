/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
#include <stdio.h>
#include <stdlib.h>
#include "listaMusica.h"
#include <string.h>

struct desc_LSE * startLista(void){
	struct desc_LSE * base=(struct desc_LSE *)malloc(sizeof(struct desc_LSE));
	base->tamanho = 0;
	base->LSE=NULL;
    printf("\n\nLista criada com sucesso.\n");
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
            aux->ant = noMusica;
			noMusica->prox = atua;
            noMusica->ant = atua;
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
            aux->ant = noMusica;
			noMusica->prox = atua;
            noMusica->ant = atua;
			base->tamanho++;
			return base;
		}
	}
}
struct desc_LSE * removeMusica(struct desc_LSE *base, int posicao){
    struct nodo * aux = NULL;
    struct nodo * atua = NULL;

    if((base->tamanho==0) && (base->LSE==NULL)){
        printf("A lista esta vazia.\n");
        return base;
    }else{
        if(posicao==1){
            base->LSE = base->LSE->prox;
            base->LSE->prox->ant = NULL;
            base->tamanho--;
            return base;
        }else{
            if(posicao==base->tamanho){
                aux = base->LSE;
                while (aux->prox != NULL){
                    atua = aux;
                    aux = aux->prox;
                }
                atua->prox->ant = NULL;
                atua->prox = NULL;
                base->tamanho--;
                return base;
            }else{
                if(posicao < base->tamanho){
                    int anda = 2; // dois por 1 já é a primeiro if. 2 siria o ultimo de 0 a 2 então a logica e depois do 2
                    aux = base->LSE;
                    while (anda != posicao){
                        aux = aux->prox;
                        anda++;
                    }
                    aux->ant = aux->prox->ant;
                    aux->prox = aux->prox->prox;
                    base->tamanho--;
                    return base;
                }else {
                    printf("Nao existe essa posicao.\n");
                }
            }
        }
    }
    return base;
}
void * busca(struct desc_LSE *base, int codigo){
    printf("titulo - artista - letra - codigo\n");
    if((base->tamanho==0) && (base->LSE==NULL)){
        printf("A lista esta vazia.\n");
        return base;
    }
    struct nodo *aux = base->LSE;
    while (aux != NULL){
        if (aux->info->codigo == codigo){
            imprimeMusica(aux);
        }
        aux = aux->prox;
    }
    return 0;
}

void * imprimeLista(struct desc_LSE *base){
    printf("titulo - artista - letra - codigo\n");
    if((base->tamanho==0) && (base->LSE==NULL)){
        printf("A lista esta vazia.\n");
        return base;
    }
    struct nodo *aux = base->LSE;
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
        printf("%d - ", aux->info->codigo);
        printf("%d\n", aux->info->execucoes);
    return 0;
}
struct desc_LSE * limpalista(struct desc_LSE *base){
    free(base);
    return base;
}
