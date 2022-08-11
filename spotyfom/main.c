/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spotyfomAndre.h"

struct desc_LSE * carregaArquivoMusica(struct desc_LSE * minhalista);

int main(){
    struct desc_LSE *minhalista;
    struct musica *inMusica;
    struct nodo *noMusica;

    int menu, codigo, posicao;

    char titulo[256];
    char artista[256];
    char letra[256];

    menu = posicao = 0;

    while(menu!=6){
        printf("\n###### Menu ##########\n1 - Carrega Lista \n2 – Insere\n3 – Remove \n4 – Consulta\n5 - Imprime\n6 - Sair\n : ");
        setbuf(stdin, NULL);
        scanf("%d", &menu);
        switch (menu){
            case 1:
                minhalista = carregaArquivoMusica(minhalista);
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
struct desc_LSE * carregaArquivoMusica(struct desc_LSE * minhalista) {

    struct musica *inMusica;
    struct nodo *noMusica;

    minhalista = startLista();
    FILE * arquivoEntrada;
    arquivoEntrada = fopen("musicas.txt", "r");
    if (arquivoEntrada ==NULL){
        printf("não foi possivel abrir o arquivo\n");
        exit(-1);
    }
    int tamanhoAcervo;
    fscanf(arquivoEntrada, "%d", &tamanhoAcervo);
    printf("tamanho do acervo sera %d\n", tamanhoAcervo);
    //aloca a struct musica com o tamanho do acervo

    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo, p;
    char caractere;
    char frase[256];
    int n=p=0;

    while((caractere = fgetc(arquivoEntrada))!= EOF){
        if(caractere != '\n'){ //caractere diferente de \n guarda em frase
            frase[n]=caractere;
            n++;
        }
        else{//encontrou \n
            if(n > 0){
                strcpy(artista, strtok(frase,";"));
                codigo = atoi(strtok(NULL,";"));
                strcpy(titulo, strtok(NULL,";"));
                strcpy(letra, strtok(NULL,";"));
                inMusica = inMuss(titulo, artista, letra, codigo, 0);
                noMusica = inNodo(inMusica);
                minhalista = novaMusica(minhalista, noMusica, p);
            }p++;
            n=0;
            frase[n]='\0';
        }
    }
    return minhalista;
}