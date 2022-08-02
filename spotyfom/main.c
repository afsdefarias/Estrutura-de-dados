/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "spotyfomAndre.h"

void carregaArquivoMusica(void);
void addMusicaPorLinha(char *frase, int n);

int main(){
    int menu;

    while(menu!=6){
        printf("\n###### Menu ##########\n1 - Carrega Lista \n2 – Insere\n3 – Remove \n4 – Consulta\n5 - Imprime\n6 - Sair\n : ");
        setbuf(stdin, NULL);
        scanf("%d", &menu);
        switch (menu){
            case 1:
                carregaArquivoMusica();
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                menu = 6;
                break;
        }
    }
    return 0;
}
void addMusicaPorLinha(char *frase, int n) {
    struct desc_LSE *minhalista;
    struct musica *inMusica;
    struct nodo *noMusica;

    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;

    strcpy(artista, strtok(frase,";"));
    codigo = atoi(strtok(NULL,";"));
    strcpy(titulo, strtok(NULL,";"));
    strcpy(letra, strtok(NULL,";"));
    printf("%s - %s - %s - %i\n", titulo, artista, letra, codigo, 0);
//    inMusica = inMuss(titulo, artista, letra, codigo, 0);
//    noMusica = inNodo(inMusica);
//    minhalista = novaMusica(minhalista, noMusica, n);
}

void carregaArquivoMusica(void) {
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
    char caractere;
    char frase[256];
    int n=0;

    while((caractere = fgetc(arquivoEntrada))!= EOF){
        if(caractere != '\n'){ //caractere diferente de \n guarda em frase
            frase[n]=caractere;
            n++;
        }
        else{//encontrou \n
            if(n > 0){
                frase[n]='\0';
                addMusicaPorLinha(frase,n);
            }
            n=0;
            frase[n]='\0';
        }
    }
}