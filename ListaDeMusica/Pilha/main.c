/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
#include <stdio.h>
#include "listaMusica.h"

int main(){
    struct desc_Pilha *minhalista;
    struct musica *inMusica;
    struct nodo *noMusica;

    char titulo[256];
    char artista[256];
    char letra[256];
    char genero[10];
    int menu, posicao, ano;
    menu = posicao = 0;

    while(menu!=7){
        printf("\n###### Menu ##########\n1 - Cria Lista \n2 – PUSH\n3 – POP \n4 – TOP\n5 - EMPTY\n6 - Imprimir\n7 - Sair\n : ");
        setbuf(stdin, NULL);
        scanf("%d", &menu);
        switch (menu){
            case 1:
                    minhalista = startPilha();
                break;
            case 2:
                printf("Nome da musica: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", titulo);
                printf("Nome do artista: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", artista);
                printf("Trecho da musica: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", letra);
                setbuf(stdin, NULL);
                printf("Genero da musica: ");
                scanf("%[^\n]s", genero);
                printf("Ano da musica: ");
                scanf("%i", &ano);

                inMusica = inMuss(titulo,artista,letra,genero, ano,0);
                noMusica = inNodo(inMusica);
                minhalista = push( minhalista, noMusica);
                break;
            case 3:
                minhalista = pop(minhalista);
                printf("\n");
                imprimeLista(minhalista);
                break;
            case 4:
                printf("TOP: ");
                TOP(minhalista);
                break;
            case 5:
                printf("EMPTY: ");
                if(empty(minhalista)){
                    printf("Verdadeiro\n");
                }else{
                    printf("Falso\n");
                }
                break;
            case 6:
                imprimeLista(minhalista);
                break;
            case 7:
                menu = 7;
                minhalista = limpalista(minhalista);
                break;
        }
    }
    return 0;
}
