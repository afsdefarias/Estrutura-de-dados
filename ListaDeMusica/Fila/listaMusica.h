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
    struct nodo *ant;
};
struct desc_queue{
    struct nodo *head;
    struct nodo *tail;
    int tamanho;

};
struct desc_queue * criaDescQueue(void);
struct nodo * inNodo(struct musica *muss);
struct musica * inMuss(char *tituloInf, char *artistaInf, char *letraInf, char *generoInf, int anoInf, int execucoesInf);
struct desc_queue * enqueue(struct nodo * nNodo, struct desc_queue * base);
struct desc_queue * dequeue(struct desc_queue * base);
void * imprimeLista(struct desc_queue *base);
void * imprimeMusica(struct nodo *aux);
int empty(struct desc_queue *base);
struct desc_queue * delete(struct desc_queue * base);
void lenght(struct desc_queue *base);