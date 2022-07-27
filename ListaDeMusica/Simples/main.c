/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
#include <stdio.h>
#include "listaMusica.h"

int main(){
    struct desc_LSE *minhalista;
    struct musica *inMusica;
    struct nodo *noMusica;

    char titulo[256];
    char artista[256];
    char letra[256];

    int menu, codigo, posicao;
    menu = posicao = 0;

    while(menu!=6){
        printf("\n###### Menu ##########\n1 - Cria Lista \n2 – Insere\n3 – Remove \n4 – Consulta\n5 - Imprime\n6 - Sair\n : ");
        setbuf(stdin, NULL);
        scanf("%d", &menu);
        switch (menu){
            case 1:
                if(minhalista->LSE !=NULL ){
                    minhalista = startLista();
                }else{
                    printf("\nLista ja existe.\n");
                }
                break;
            case 2:
                printf("Codigo da musica: ");
                scanf("%i", &codigo);
                printf("Nome da musica: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", titulo);
                printf("Nome do artista: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", artista);
                printf("Trecho da musica: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]s", letra);

                inMusica = inMuss(titulo,artista,letra,codigo,0);
                noMusica = inNodo(inMusica);
                printf("\n");
                printf("Posicao: ");
                scanf("%d", &posicao);
                minhalista = novaMusica( minhalista, noMusica, posicao);
                break;
            case 3:
                printf("Deleta a posicao: ");
                scanf("%d", &posicao);
                minhalista = removeMusica(minhalista, posicao);
                printf("\n");
                imprimeLista(minhalista);
                break;
            case 4:
                printf("Codigo da Musica: ");
                scanf("%d", &codigo);
                busca(minhalista, codigo);
                break;
            case 5:
                imprimeLista(minhalista);
                break;
            case 6:
                menu = 6;
                minhalista = limpalista(minhalista);
                break;
        }
    }
    return 0;
}
