#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

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

                if(arvore == NULL)
                arvore = rbt_inicializar(arvore, valor);
                else
                arvore = rbt_inserir(arvore, valor);

                break;
            case 2:
            //Pre-order
                rbt_preorder(arvore); 
                printf("\n");
                break;
           case 3:
           //In-order
                rbt_inorder(arvore); 
                printf("\n");
                break;
            case 4:
           //Pos-order
                rbt_posorder(arvore);
                printf("\n"); 
                break;
            case 5:
           //Reverso
                rbt_reverso(arvore);
                printf("\n"); 
                break;
            case 6:
           //Info
                scanf("%d", &valor);
                rbt_info(arvore, valor); 
                break;
            case 7:
           //Remover
                
                break;
            case 8:
           //Remover
                break;
            case 9:
           //Remover
                scanf("%d", &valor);
                arvore = rbt_remover(arvore, valor);
                break;
            case 99:
            //Sair
                exit(0);
        }    
    }
 }