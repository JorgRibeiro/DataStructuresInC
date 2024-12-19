#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

Raiz rbt_inserir(Raiz raiz, int valor)
{
    if (raiz == NULL)
    {
        Raiz novo = (Raiz)malloc(sizeof(no));
        novo->chave = valor;
        novo->cor = 'r';
        novo->raiz_esq = NULL;
        novo->raiz_dir = NULL;
        return novo;
    }
    else if (valor > raiz->chave)
    {
        raiz->raiz_dir = rbt_inserir(raiz->raiz_dir, valor);
    }
    else
    {
        raiz->raiz_esq = rbt_inserir(raiz->raiz_esq, valor);
    }
    return raiz;
}

void rbt_preorder(Raiz raiz)
{
    if(raiz != NULL){
    printf("[%d]",raiz->chave);
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

Raiz rbt_remover(Raiz raiz, int valor_removido)
{
    return raiz;
}
