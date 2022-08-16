/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
struct musica{
    char titulo[256];
    char artista[256];
    char letra[256];
    int codigo;
    int execucoes;
};
struct nodo{
    struct nodo *prox;
    struct nodo *ant;
    struct musica *info;
};
struct desc_LSE {
    struct nodo *LSE;
    int tamanho;
};
struct desc_queue{
    struct nodo *head;
    struct nodo *tail;
    char playlist[255];
    int tamanho;
};
struct desc_Pilha {
    struct nodo *Pilha;
    char playlist[255];
    int tamanho;
};
struct desc_Pilha * startPilha(void);
struct desc_LSE * startLista(void);
struct desc_queue * criaDescQueue(void);
struct nodo * inNodo(struct musica *muss);
struct musica * inMuss(char *tituloInf, char *artistaInf, char *letraInf, int codigoInf, int execucoesInf);
struct desc_queue * enqueue(struct nodo * nNodo, struct desc_queue * base); //Fila
struct desc_queue * filaAleatoria(struct  desc_LSE *base, struct desc_queue *baseFila, int qta);
//struct desc_queue * playDequeue(struct desc_queue * baseFila);
struct desc_queue * playDequeue(struct desc_LSE **base, struct desc_queue * baseFila);

struct desc_Pilha * push(struct desc_Pilha *base, struct nodo *noMusica);
struct desc_Pilha * pilhaPersonalizado(struct  desc_LSE *base, struct desc_Pilha *basePilha, int codigo);
void * imprimePilha(struct desc_Pilha *base);
//struct desc_Pilha * playPop(struct desc_Pilha *basePilha);
struct desc_Pilha * playPop(struct desc_LSE **base, struct desc_Pilha *basePilha);

struct desc_LSE * novaMusica(struct desc_LSE *base, struct nodo *noMusica, int posicao);
void * imprimeLista(struct desc_LSE *base);
void * imprimeFila(struct desc_queue * base);
void * buscaPCodigo(struct desc_LSE *base, int codigo);
void * buscaPtitulo(struct desc_LSE *base, char *titu);
void * buscaPArtista(struct desc_LSE *base, char *art);
void * imprimeMusica(struct nodo *aux);
struct desc_LSE * limpalista(struct desc_LSE *base);
void ** atualizaExecucao(struct desc_LSE *base, int codigo);