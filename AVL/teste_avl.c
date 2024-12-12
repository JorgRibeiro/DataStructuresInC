#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

int main(int argc, char * argv[]) {
    //Declarar uma variável do tipo árvore
    Raiz arvore;
    //inicializar como uma árvore vazia
    arvore = NULL;
    
    while(1) {
        int opcao;
        int valor;
        scanf("%d", &opcao);
        switch(opcao) {
            //inserir
            case 1:
                scanf("%d", &valor);
                arvore = bst_inserir(arvore, valor);
                break;
            case 2:
                bst_preorder(arvore); 
                printf("\n");
                break;
           case 3:
                bst_inorder(arvore); 
                printf("\n");
                break;
            case 4:
                bst_posorder(arvore); 
                printf("\n");
                break;
            case 5:
                bst_reverso(arvore); 
                printf("\n");
                break;
            case 6:
                printf("%d\n",bst_altura(arvore));
                printf("\n");
                break;
            case 7:
                printf("%d\n",bst_quant_folhas(arvore));
                printf("\n");
                break;
            case 8:
                scanf("%d", &valor);
                if(bst_valida_caminho(arvore,valor) == 1){
                    bst_caminho(arvore, valor);    
                }
                printf("\n");
                break;
            case 9:
                scanf("%d", &valor);
                arvore = bst_remover(arvore, valor);
                printf("\n");
                break;
            case 99:
                exit(0);
        }    
    }
 }