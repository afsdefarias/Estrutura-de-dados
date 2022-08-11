// Lista 1
// Wednesday, 11 May 2022
// Nome Andr? Francisco Silva de Farias (andrefarias.aluno.unipampa.edu.br).

#include <stdio.h>
#include <stdlib.h>

int ** criaMatriz(int **pmtr, int linhas, int colunas);
void leiaMatriz(int **pmtr, int linhas, int colunas);
int somaMatriz(int **pmtr, int linhas, int colunas);
int * colunaMat(int **pmtr, int linhas, int colunas, int ncoluna);
void liberaMatriz(int **pmtr, int *vet);
void imprimeMatriz(int **pmtr, int linhas, int colunas);
void imprimeVet(int *vet, int colunas);

int main() {
  int **pmtr, *vet;
  int linhas, colunas, sair=1, menu, soma, ncoluna;

  while (sair!=0) {
    printf("\n################### Menu ###########################\n\n");
    printf("1) Criar Matrix\n");
    printf("2) Ler Matrix\n");
    printf("3) Soma dos elementos da matriz\n");
    printf("4) Retornar em um vetor de uma determinada coluna da matriz\n");
    printf("5) Sair do programa\n");
    printf(" : ");
    setbuf(stdin,NULL);
    scanf("%i", &menu);

    switch (menu) {
      case 1:
        printf("\n");
        printf("Digite quantidade de linhas da matrix: ");
        scanf("%i", &linhas);
        printf("Digite quantidade de colunas da matrix: ");
        scanf("%i", &colunas);
        pmtr = criaMatriz(pmtr, linhas, colunas);
        leiaMatriz(pmtr, linhas, colunas);
        break;
      case 2:
        printf("\n");
        imprimeMatriz(pmtr,linhas,colunas);
        break;
      case 3:
        printf("\n");
        soma = somaMatriz(pmtr, linhas, colunas);
        printf("%i\n", soma);
        break;
      case 4:
        printf("\n");
        printf("Escolha uma coluna da matriz para cria um vetor\n\t:");
        scanf("%i", &ncoluna);
        vet = colunaMat(pmtr, linhas, colunas, ncoluna);
        imprimeVet(vet, linhas);
        break;
      case 5:
        printf("\n");
        liberaMatriz(pmtr, vet);
        return sair==0;
      default:
        printf("\n");
        printf("Opcao invalida!\n");
    }
  }
  return 0;
}

int ** criaMatriz(int **pmtr, int linhas, int colunas) {
  int i;
  pmtr = malloc(colunas * sizeof(int*)); // Aloca um vetor de ponteiros
  for (i=0; i<colunas; i++){  // Aloca ponteiros dentro do vetor. formndo a matrix
    pmtr[i] = malloc(linhas * sizeof(int));
  }
  return pmtr;
}
void leiaMatriz(int **pmtr, int linhas, int colunas){
  int i;
  int j;
  for (i=0; i<linhas; i++){
    for (j = 0; j<colunas; j++){
      printf("Valor[%i][%i]: ", i,j);
      scanf("%i", &pmtr[i][j]);
    }
  }
}
void imprimeMatriz(int **pmtr, int linhas, int colunas){
  int i;
  int j;
  for (i = 0; i<linhas; i++){
    for (j = 0; j<colunas; j++){
      printf("%i ", pmtr[i][j]);
    }
    printf("\n");
  }
}
int somaMatriz(int **pmtr, int linhas, int colunas){
  int soma = 0;
  int i;
  int j;
  for (i = 0; i<linhas; i++){
    for (j = 0; j<colunas; j++){
      soma = soma + pmtr[i][j];
    }
  }
  return soma;
}
int * colunaMat(int **pmtr, int linhas, int colunas, int ncoluna) {
  int *vet;
  int i;
  int j;
  vet = malloc(linhas * sizeof(int));
  for (i = 0; i<linhas; i++){
    for (j = 0; j<colunas; j++){
      if (ncoluna==j) {
        vet[i] = pmtr[i][ncoluna];
      }
    }
  }
  return vet;
}
void imprimeVet(int *vet, int colunas) {
  int i;
  for (i=0; i<colunas; i++){
    printf("[%i] ", vet[i]);
  }
    printf("\n");
}
void liberaMatriz(int **pmtr, int *vet){
  free(vet);
  free(pmtr);
  free(*pmtr);
  printf("Saindo...\n");
}
