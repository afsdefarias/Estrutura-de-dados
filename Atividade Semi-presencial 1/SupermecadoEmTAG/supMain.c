#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "supTag.h"

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
