/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

int main(){
  int menu, quant, setore, sair = 1, sairVenda = 1, monitor = 0;
  char nomeProduto[30];
  struct mercadoStruct * mercado = NULL;

  int quantProdutos = 10;
  alocaMercado(&mercado, quantProdutos);

  while (sair!=0) {
    printf("#################### MENU ##########################\n\n");
    printf("1 - Para inserir Produtos\n");
    printf("2 - Para pesquisar um Produto\n");
    printf("3 - Para pesquisar por Seotres\n");
    printf("4 - Para mostrar todos os Produtos\n");
    printf("5 - Para Vender os Produtos\n");
    printf("6 - Para obter o balanco dos Produtos\n");
    printf("7 - Para sair\n");

    printf("\n :");
    setbuf(stdin, NULL);
    scanf("%i", &menu);
    switch (menu) {
      case 1:
        printf("\n");
        printf("Digite a quantidade de produtos que deseja tabalhar\n\t:");
        scanf("%i", &quant);
        monitor = inserirProdutos(mercado, quant, monitor, quantProdutos);
        break;
      case 2:
        printf("\n");
        printf("Digite o nome do produto que procura\n\t:");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", nomeProduto);
    	pesquisaProduto(mercado, monitor, nomeProduto);
        break;
      case 3:
        printf("\n");
        printf("\nDigite o numero do sertor quer deseja filtra;\n");
        printf("1-Acougue, 2-Frios e laticinios, 3-Adega e bebidas, 4-Higiene e limpeza\n");
        printf("5-Hortifruti e mercearia, 6-Padaria, 7-Enlatados, 8-Cereais, 9-Rotisseria)\n :");
        scanf("%d", &setore);
        pesquisaSetores(mercado, monitor, setore);
        break;
      case 4:
        printf("\n");
        todosProdutos(mercado, monitor);
        break;
      case 5:
        printf("\n");
        printf("Digite o nome do produto deseja vender\n\t:");
        setbuf(stdin, NULL);
        scanf("%[^\n]s", nomeProduto);
        vendeProdutos (mercado, monitor, nomeProduto);
        break;
      case 6:
        printf("\n");
        printf("Total do balaco R$ %.2f\n\n", balancoProdutos(mercado, monitor-1));
        break;
      case 7:
        printf("\n");
        printf("Saindo.....\n");
        free(mercado);
        sair = 0;
        return sair;
      default:
        printf("Opcao invalida.\n\n");
        break;
    }
  }
  return 0;
}

void alocaMercado(struct mercadoStruct ** mercado, int tamanho){
	*mercado = (struct mercadoStruct *)malloc(tamanho * sizeof(struct mercadoStruct));
}

int inserirProdutos (struct mercadoStruct * mercado, int quant, int monitor, int maxProd){
	int i;
	monitor = monitor + quant;

	if (maxProd>=monitor){
	  	for (i=monitor-quant; i<monitor; i++){
		    printf("[%i] - Produto: ", i);
		    setbuf(stdin, NULL);
		    scanf("%[^\n]s", mercado[i].nome);

		    printf("[%i] - Setores (1-Acougue, 2-Frios e laticinios, 3-Adega e bebidas, 4-Higiene e limpeza\n", i);
		    printf("\t\t5-Hortifruti e mercearia, 6-Padaria, 7-Enlatados, 8-Cereais, 9-Rotisseria)\n\t:");
		    setbuf(stdin, NULL);
		    scanf("%d", &mercado[i].setores);

		    printf("[%i] - Quantidade: ", i);
		    setbuf(stdin, NULL);
		    scanf("%f", &mercado[i].qta);

		    printf("[%i] - Preco Unitario: ", i);
		    setbuf(stdin, NULL);
		    scanf("%f", &mercado[i].precoUni);
		    printf("\n");
		}
	}else{
		printf("\nQuantidade produto inserido e maio que permitido.\n\n");
		monitor = monitor - quant;
	}
	return monitor;
}

void pesquisaProduto(struct mercadoStruct * mercado, int monitor, char *nproduto){
  int achei = 0;
  int i;
  for (i=0; i<monitor; i++){
      if(strcmp( mercado[i].nome, nproduto)==0){
        printf("\n");
        printf("[%i] - Produto: %s\n", i, mercado[i].nome);
        printf("[%i] - Setores: ", i);
        imprimeSetores(mercado, i);
        printf("[%i] - Quantidade: %.2f\n", i, mercado[i].qta);
        printf("[%i] - Preco Unitario: R$ %.2f\n", i, mercado[i].precoUni);
        printf("\n");
        achei = 1;
      }
    }if(achei==0){
      printf("\nProduto nao encontrado.\n\n");
    }
}

void pesquisaSetores(struct mercadoStruct * mercado, int monitor, int setore){
  int achei = 0;
  int i;
  for (i=0; i<monitor; i++){
      if(mercado[i].setores == setore){
        printf("\n");
        printf("[%i] - Produto: %s\n", i, mercado[i].nome);
        printf("[%i] - Setores: ", i);
        imprimeSetores(mercado, i);
        printf("[%i] - Quantidade: %.2f\n", i, mercado[i].qta);
        printf("[%i] - Preco Unitario: R$ %.2f\n", i, mercado[i].precoUni);
        printf("\n");
        achei = 1;
      }
    }if(achei==0){
      printf("\nProduto nao encontrado.\n\n");
    }
}

void todosProdutos(struct mercadoStruct * mercado, int monitor){
  int i;
  for (i=0; i<monitor; i++){
        printf("\n");
        printf("[%i] - Produto: %s\n", i, mercado[i].nome);
        printf("[%i] - Setores: ", i);
        imprimeSetores(mercado, i);
        printf("[%i] - Quantidade: %.2f\n", i, mercado[i].qta);
        printf("[%i] - Preco Unitario: R$ %.2f\n", i, mercado[i].precoUni);
        printf("\n");
      }
}

void imprimeSetores(struct mercadoStruct * mercado, int sessao){
  switch (mercado[sessao].setores) {
    case Acougue:
    printf("1 - Acougue\n");
    break;
    case Frios_e_laticinios:
    printf("2 - Frios e laticinios\n");
    break;
    case Adega_e_bebidas:
    printf("3 - Adega e bebidas\n");
    break;
    case Higiene_e_limpeza:
    printf("4 - Higiene e limpeza\n");
    break;
    case Hortifruti_e_mercearia:
    printf("5 - Hortifruti e mercearia\n");
    break;
    case Padaria:
    printf("6 - Padaria\n");
    break;
    case Enlatados:
    printf("7 - Enlatados\n");
    break;
    case Cereais:
    printf("8 - Cereais\n");
    break;
    case Rotisseria:
    printf("9 - Rotisseria\n");
    break;
  }
}

struct mercadoStruct ** vendeProdutos (struct mercadoStruct * mercado, int monitor, char *nproduto){
  int achei = 0;
  float venda;
  int i;
  for (i=0; i<monitor; i++){
      if(strcmp(mercado[i].nome, nproduto)==0){
        printf("\n");
        printf("Produtos encontrado.\n([%i] - %s) Quat.: %.2f R$ %.2f\n", i, mercado[i].nome, mercado[i].qta, mercado[i].precoUni);
        printf("Quantos voce quer vender\n\t : ");
        scanf("%f", &venda);
        printf("%.2fx([%i] - %s) = R$ %.2f\n", venda, i, mercado[i].nome, mercado[i].precoUni*venda);
        printf("[%i] - Quantidade Atualizada: %.2f\n", i, mercado[i].qta-venda);
        mercado[i].qta = mercado[i].qta-venda;
        printf("\n");
        achei = 1;
      }
    }if(achei==0){
      printf("\nProduto nao encontrado.\n\n");
    }
  //return (struct mercadoStruct *)mercado;
}

float balancoProdutos (struct mercadoStruct * mercado, int monitor){
  if(monitor==-1){
    return 0;
  }else{
    return (mercado[monitor].qta * mercado[monitor].precoUni) + balancoProdutos(mercado, monitor-1);
  }
}
