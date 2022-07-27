/*
 * FFVazia/DELETE(Fila). Faz a fila ficar vazia.
 *
–Vazia/EMPTY (Fila). Retorna true se a Fila
        estiver vazia; caso contrário, retorna false.

–Enfileirar/ENQUEUE (x, Fila). Insere o item x
no fim da fila.

– Desenfileirar/DEQUEUE (Fila, x). Retorna o
item x no início da fila, retirando-o da fila.

–Tamanho/LENGHT (Fila). Esta função retorna o
número de itens da fila

Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
#include <stdio.h>
#include "listaMusica.h"

int main(){
    struct desc_queue *minhalista;
    struct musica *inMusica;
    struct nodo *noMusica;

    char titulo[256];
    char artista[256];
    char letra[256];
    char genero[10];
    int menu, posicao, ano;
    menu = posicao = 0;

    while(menu!=8){
        printf("\n###### Menu ##########\n1 - CreateQueue \n2 – DELETE\n3 – EMPTY \n4 – ENQUEUE\n5 - DEQUEUE\n6 - LENGHT\n7 - ShowQueue\n8 - Sair\n : ");
        setbuf(stdin, NULL);
        scanf("%d", &menu);
        switch (menu){
            case 1:
                minhalista = criaDescQueue();
                break;
            case 2:
                minhalista = delete(minhalista);
                break;
            case 3:
                if(empty(minhalista)){
                    printf("\nTrue\n");
                }else{
                    printf("\nFalse\n");
                }
                break;
            case 4:
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
                minhalista = enqueue( noMusica, minhalista);
                break;
            case 5:
                minhalista = dequeue(minhalista);
                break;
            case 6:
                lenght(minhalista);
                break;
            case 7:
                imprimeLista(minhalista);
                break;
            case 8:
                menu = 8;
                break;
        }
    }
    return 0;
}
