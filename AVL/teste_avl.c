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
            //Inserir
            case 1:
                scanf("%d", &valor);
                arvore = avl_inserir(arvore, valor);
                break;
            case 2:
            //Pre-order
                avl_preorder(arvore); 
                printf("\n");
                break;
           case 3:
           //Remover
                scanf("%d", &valor);
                arvore = avl_remover(arvore, valor);
                printf("\n");
                break;
            case 99:
            //Sair
                exit(0);
        }    
    }
 }