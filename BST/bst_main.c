#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main(int argc, char * argv[]) {
    //Declarar uma variável do tipo árvore e inicializar como uma árvore vazia
    Raiz arvore = NULL;
    
    //Usando um While true para fazer um menu com switch
    while(1) {
        int opcao;
        int valor;
        scanf("%d", &opcao);
        switch(opcao) {
            //Inserir
            case 1:
                scanf("%d", &valor);
                arvore = bst_inserir(arvore, valor);
                break;
            case 2:
            //Pre-order
                bst_preorder(arvore); 
                printf("\n");
                break;
           case 3:
           //In-order
                bst_inorder(arvore); 
                printf("\n");
                break;
            case 4:
            //Pos-order
                bst_posorder(arvore); 
                printf("\n");
                break;
            case 5:
            //Reverso
                bst_reverso(arvore); 
                printf("\n");
                break;
            case 6:
            //Altura
                printf("%d\n",bst_altura(arvore));
                printf("\n");
                break;
            case 7:
            //Quantidade de folhas de uma arvore
                printf("%d\n",bst_quant_folhas(arvore));
                printf("\n");
                break;
            case 8:
            //Caminho até uma raiz
                scanf("%d", &valor);
                if(bst_valida_caminho(arvore,valor) == 1){
                    bst_caminho(arvore, valor);    
                }
                printf("\n");
                break;
            case 9:
            //Remover
                scanf("%d", &valor);
                arvore = bst_remover(arvore, valor);
                printf("\n");
                break;
            case 99:
            //sair
                exit(0);
        }    
    }
 }