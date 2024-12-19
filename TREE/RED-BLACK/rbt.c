#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

Raiz rbt_inserir(Raiz raiz, int valor)
{
    if(valor > raiz->chave){
        if(raiz->raiz_dir == NULL){
        Raiz novo = (Raiz)malloc(sizeof(no));
        raiz->raiz_dir = novo;
        novo->chave = valor;
        novo->cor = 'r';
        novo->raiz_esq = NULL;
        novo->raiz_dir = NULL;
        novo->raiz_pai = raiz;
        } else {
            raiz->raiz_dir = rbt_inserir(raiz->raiz_dir, valor);
        }
    } else{
        if(raiz->raiz_esq == NULL){
        Raiz novo = (Raiz)malloc(sizeof(no));
        raiz->raiz_esq = novo;
        novo->chave = valor;
        novo->cor = 'r';
        novo->raiz_esq = NULL;
        novo->raiz_dir = NULL;
        novo->raiz_pai = raiz;
        } else {
            raiz->raiz_esq = rbt_inserir(raiz->raiz_esq, valor);
        }
    }

    return raiz;
}

Raiz rbt_inicializar(Raiz raiz, int valor)
{
    if(raiz == NULL){
        Raiz novo = (Raiz)malloc(sizeof(no));
        novo->chave = valor;
        novo->cor = 'b';
        novo->raiz_esq = NULL;
        novo->raiz_dir = NULL;
        novo->raiz_pai = NULL;
        return novo;
    }
    return raiz;
}

void rbt_preorder(Raiz raiz)
{
    if(raiz != NULL){
    printf("[%d %c]",raiz->chave,raiz->cor);
    rbt_preorder(raiz->raiz_esq);
    rbt_preorder(raiz->raiz_dir);
    }
    
}

void rbt_posorder(Raiz raiz)
{
    if(raiz != NULL){
    rbt_posorder(raiz->raiz_esq);
    rbt_posorder(raiz->raiz_dir);
    printf("[%d %c]",raiz->chave,raiz->cor);
    }
}

void rbt_inorder(Raiz raiz)
{
    if(raiz != NULL){
    rbt_inorder(raiz->raiz_esq);
    printf("[%d %c]",raiz->chave,raiz->cor);
    rbt_inorder(raiz->raiz_dir);
    }
}

void rbt_reverso(Raiz raiz)
{
    if(raiz != NULL){
    rbt_reverso(raiz->raiz_dir);
    printf("[%d %c]",raiz->chave,raiz->cor);
    rbt_reverso(raiz->raiz_esq);   
    }
}

void rbt_info(Raiz raiz, int valor)
{
    if(raiz != NULL){
        if(valor > raiz->chave){
            rbt_info(raiz->raiz_dir, valor);
        }else if(valor < raiz->chave){
            rbt_info(raiz->raiz_esq, valor);
        } else {
            printf("---- INFO ----\n");
            printf("Valor: %d\n", raiz->chave);
            printf("Cor: %c\n", raiz->cor);
            if(raiz->raiz_dir == NULL)
                printf("Direito: NULL\n");
            else 
            printf("Direito: %d\n", raiz->raiz_dir->chave);

            if(raiz->raiz_esq == NULL)
                printf("Esquerdo: NULL\n");
            else 
            printf("Esquerdo: %d\n", raiz->raiz_esq->chave);

            if(raiz->raiz_pai == NULL)
                printf("Pai: NULL\n");
            else 
            printf("Pai: %d\n", raiz->raiz_pai->chave);
        }
    }
    
}

Raiz rbt_remover(Raiz raiz, int valor_removido)
{
    return raiz;
}
