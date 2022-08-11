enum mercadoEnum {
  Acougue = 1,
  Frios_e_laticinios,
  Adega_e_bebidas,
  Higiene_e_limpeza,
  Hortifruti_e_mercearia,
  Padaria,
  Enlatados,
  Cereais,
  Rotisseria
};

struct mercadoStruct  {
  char nome[30];
  enum mercadoEnum setores;
  float qta;
  float precoUni;
};

void alocaMercado(struct mercadoStruct ** mercado, int tamanho);
int inserirProdutos(struct mercadoStruct * mercado, int quant, int monitor, int maxProd);
void imprimeSetores(struct mercadoStruct * mercado, int sessao);
void pesquisaProduto(struct mercadoStruct * mercado, int monitor, char *nproduto);
void pesquisaSetores(struct mercadoStruct * mercado, int monitor, int setore);
void todosProdutos(struct mercadoStruct * mercado, int monitor);
struct mercadoStruct ** vendeProdutos (struct mercadoStruct * mercado, int monitor, char *nproduto);
float balancoProdutos (struct mercadoStruct * mercado, int monitor);

