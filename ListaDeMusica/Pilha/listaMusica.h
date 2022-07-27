/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
struct musica{
    char titulo[256];
    char artista[256];
    char letra[256];
    char genero[10];
    int ano;
    int execucoes;
};
struct nodo{
    struct nodo *prox;
    struct musica *info;
};
struct desc_Pilha {
    struct nodo *Pilha;
    int tamanho;
};
struct desc_Pilha * startPilha(void);
struct nodo * inNodo(struct musica *muss);
struct musica * inMuss(char *tituloInf, char *artistaInf, char *letraInf, char *generoInf, int anoInf, int execucoesInf);
struct desc_Pilha * push(struct desc_Pilha *base, struct nodo *noMusica);
int empty(struct desc_Pilha *base);
void * TOP(struct desc_Pilha *base);
void * imprimeLista(struct desc_Pilha *base);
void * imprimeMusica(struct nodo *aux);
struct desc_Pilha * pop(struct desc_Pilha *base);
struct desc_Pilha * limpalista(struct desc_Pilha *base);