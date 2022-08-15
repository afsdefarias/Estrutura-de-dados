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
struct nodo * inNodo(int key);
//struct desc_avl * nodoADD(struct desc_avl * vaso, struct nodo * folha);
struct nodo * nodoADD(struct nodo * raiz, struct nodo * folha, struct nodo *pai);
void preOrdem(struct nodo * raiz);
void posOrdem(struct nodo * raiz);
void bn(void);