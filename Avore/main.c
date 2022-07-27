/*
Aluno: Andre Francisco Silva de farias
Matricula: 2110102624
*/
#include <stdio.h>
#include <stdlib.h>
#include "avoreAvl.h"
#include <string.h>

int main(){
    struct desc_avl * minhaAvore;
    struct nodo * folha;

    int chave, menu;
    menu = 0;
    while(menu!=5) {
        printf("\n###### Menu ##########\n1 - CreateAVL \n2 – REMOVE\n3 – INSERT \n4 – IMPRIME\n5 - Sair\n : ");
        setbuf(stdin, NULL);
        scanf("%d", &menu);
        switch (menu) {
            case 1:
                minhaAvore = CreateAVL();
                break;
            case 3:
                folha = inNodo();
                minhaAvore = noNovo(minhaAvore, folha);
                break;
            case 5:
                menu = 5;
                break;
        }
    }
    return 0;
}