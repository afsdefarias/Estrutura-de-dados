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
    char titulo[256];
    char artista[256];

    struct desc_LSE *minhalista;
    struct desc_queue *minhaPlayFila;
    struct desc_Pilha *minhaPlayPilha;

    int menu, sbmenu, codigo, posicao, menulist, menulistE, qta;
    menu = posicao = sbmenu = menulist = menulistE = qta = 0;
    minhalista = carregaArquivoMusica(minhalista); // Carrega Musica
    minhaPlayFila = criaDescQueue();
    minhaPlayPilha = startPilha();
    while(menu!=6){
        printf("\n###### Menu ##########\n1 - Execução \n2 – Playlist\n3 – Busca \n4 – Relatório\n5 - Impressão\n6 - Sair\n : ");
        setbuf(stdin, NULL);
        scanf("%d", &menu);
        switch (menu){
            case 1:
                printf("\n###### Execução ##########\n1 - Execução Playlist Aleatoria \n2 – Execução Playlist personalizada\n3 – Ver playlist\n4 – voltar\n : ");
                setbuf(stdin, NULL);
                scanf("%d", &menulistE);
                switch (menulistE) {
                    case 1:
                        minhaPlayFila = playDequeue(&minhalista,minhaPlayFila);
                        break;
                    case 2:
                        minhaPlayPilha = playPop(&minhalista, minhaPlayPilha);
                        break;
                    case 3:
                        imprimeFila(minhaPlayFila);
                        printf("\n\n");
                        imprimePilha(minhaPlayPilha);
                        break;
                }
                break;
            case 2:
                printf("\n###### Playlist ##########\n1 - Criar Playlist Aleatoria \n2 – Criar Playlist personalizada\n3 – Ver playlist\n4 – voltar\n : ");
                setbuf(stdin, NULL);
                scanf("%d", &menulist);
                switch (menulist) {
                    case 1:
                        printf("Quantidade de musica que deseja \n : ");
                        setbuf(stdin, NULL);
                        scanf("%d", &qta);
                        minhaPlayFila = filaAleatoria(minhalista, minhaPlayFila, qta);
                        break;
                    case 2:
                        codigo = 1;
                        while(codigo!=0) {
                            printf("Codigo da Musica : DIGITE 0 PARA SAIR \n : ");
                            setbuf(stdin, NULL);
                            scanf("%d", &codigo);
                            if (codigo == 0) break;
                            minhaPlayPilha = pilhaPersonalizado(minhalista, minhaPlayPilha, codigo);
                        }
                        break;
                    case 3:
                        imprimeFila(minhaPlayFila);
                        printf("\n\n");
                        imprimePilha(minhaPlayPilha);
                        break;
                }
                break;
            case 3:
                printf("Pesquisar\n 1 - Codigo | 2 - Titulo | 3 - Artosta \n:");
                setbuf(stdin, NULL);
                scanf("%d", &sbmenu);

                switch (sbmenu) {
                    case 1:
                        printf("Codigo da Musica: ");
                        setbuf(stdin, NULL);
                        scanf("%d", &codigo);
                        buscaPCodigo(minhalista, codigo);
                        break;
                    case 2:
                        printf("Titulo da Musica: \n");
                        setbuf(stdin, NULL);
                        scanf("%[^\n]s", titulo);
                        buscaPtitulo(minhalista, titulo);
                        break;
                    case 3:
                        printf("Artista da Musica: \n");
                        setbuf(stdin, NULL);
                        scanf("%[^\n]s", artista);
                        buscaPArtista(minhalista, artista);
                        break;
                }
                break;
            case 4:
                printf("Deleta a posicao: ");
                scanf("%d", &posicao);
                printf("\n");
                imprimeLista(minhalista);
                break;
            case 5:
                imprimeLista(minhalista);
                break;
            case 6:
                menu = 6;
                minhalista = limpalista(minhalista);
                break;
            case 7:
                imprimeFila(minhaPlayFila);
                break;
        }
    }
    return 0;
}
struct desc_LSE * carregaArquivoMusica(struct desc_LSE * minhalista) {

    struct musica *inMusica;
    struct nodo *noMusica;

    minhalista = startLista(); // Cria lista
    FILE * arquivoEntrada;
    arquivoEntrada = fopen("musicas.txt", "r");
    if (arquivoEntrada ==NULL){
        printf("não foi possivel abrir o arquivo\n");
        exit(-1);
    }
    int tamanhoAcervo;
    fscanf(arquivoEntrada, "%d", &tamanhoAcervo);
    printf("\nO acervo consta com %d musicas\n", tamanhoAcervo);
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