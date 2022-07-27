/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/

struct nodo{
    struct nodo *pai;
    int chave;
    struct nodo *esq;
    struct nodo *dir;
    int fator;
};
struct desc_avl{
    struct nodo *raiz;
    int tamanho;
};

struct desc_avl * CreateAVL(void);
struct nodo * inNodo(void);
struct nodo * noNovo(struct desc_avl * inAVL, struct nodo * inNodo);