#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(int argc, char * argv[]) {
    Raiz arvore;
    arvore = NULL;
    
    while(1) {
        int opcao;
        int valor;
        scanf("%d", &opcao);
        switch(opcao) {
            //inserir
            case 1:
                scanf("%d", &valor);
                arvore = avl_inserir(arvore, valor);
                break;
            case 2:
                avl_preorder(arvore); 
                printf("\n");
                break;
           case 3:
                scanf("%d", &valor);
                arvore = avl_remover(arvore, valor);
                break;
            case 99:
                exit(0);
        }    
    }
 }