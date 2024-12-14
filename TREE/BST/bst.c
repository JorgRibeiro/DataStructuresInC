#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

Raiz bst_inserir(Raiz raiz, int novo_valor)
{
    if (raiz == NULL)
    {
        Raiz novo = (Raiz)malloc(sizeof(no));
        novo->valor = novo_valor;
        novo->raiz_dir = NULL;
        novo->raiz_esq = NULL;
        return novo;
    }
    else if (novo_valor > raiz->valor)
    {
        raiz->raiz_dir = bst_inserir(raiz->raiz_dir, novo_valor);
    }
    else
    {
        raiz->raiz_esq = bst_inserir(raiz->raiz_esq, novo_valor);
    }
    return raiz;
}

void bst_preorder(Raiz raiz)
{
    if (raiz != NULL)
    {
        printf("[%d]", raiz->valor);
        bst_preorder(raiz->raiz_esq);
        bst_preorder(raiz->raiz_dir);
    }
}

void bst_inorder(Raiz raiz)
{
    if (raiz != NULL)
    {
        bst_inorder(raiz->raiz_esq);
        printf("[%d]", raiz->valor);
        bst_inorder(raiz->raiz_dir);
    }
}

void bst_posorder(Raiz raiz)
{
    if (raiz != NULL)
    {
        bst_posorder(raiz->raiz_esq);
        bst_posorder(raiz->raiz_dir);
        printf("[%d]", raiz->valor);
    }
}

void bst_reverso(Raiz raiz)
{
    if (raiz != NULL)
    {
        bst_reverso(raiz->raiz_dir);
        printf("[%d]", raiz->valor);
        bst_reverso(raiz->raiz_esq);
    }
}

int bst_altura(Raiz raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        int altura_esq = bst_altura(raiz->raiz_esq);
        int altura_dir = bst_altura(raiz->raiz_dir);
        if (altura_esq > altura_dir)
        {
            {
                return altura_esq + 1;
            }
        }
        else
        {
            return altura_dir + 1;
        }
    }
}

int bst_quant_folhas(Raiz raiz)
{
    if (raiz != NULL)
    {
        int folhas = bst_quant_folhas(raiz->raiz_dir);
        folhas = folhas + bst_quant_folhas(raiz->raiz_esq);
        if (raiz->raiz_dir == NULL && raiz->raiz_esq == NULL)
        {
            return folhas + 1;
        }
        else
            return folhas;
    }

    return 0;
}

void bst_caminho(Raiz raiz, int chave)
{
    if (raiz->valor < chave)
    {
        printf("[%d]", raiz->valor);
        bst_caminho(raiz->raiz_dir, chave);
    }
    else if (raiz->valor > chave)
    {
        printf("[%d]", raiz->valor);
        bst_caminho(raiz->raiz_esq, chave);
    }
    else
        (printf("[%d]", raiz->valor));
}

int bst_valida_caminho(Raiz raiz, int chave)
{
     if (raiz == NULL)
    {
        return 0;
    }

    if (raiz->valor < chave)
    {
        return bst_valida_caminho(raiz->raiz_dir, chave);
    }
    else if (raiz->valor > chave)
    {
        return bst_valida_caminho(raiz->raiz_esq, chave);
    }
    else if (raiz->valor == chave)
    {
        return 1;
    }

    return 0;
}

Raiz bst_maior_valor(Raiz raiz)
{
    Raiz temp = raiz;
    if (raiz == NULL)
    {
        return NULL;
    }

    while (temp->raiz_dir != NULL)
    {
        temp = temp->raiz_dir;
    }

    return temp;
}

Raiz bst_remover(Raiz raiz, int valor_removido)
{
     if (raiz == NULL)
    {
        return raiz;
    }
    else if (raiz->valor == valor_removido)
    {

        if (raiz->raiz_dir == NULL && raiz->raiz_esq == NULL)
        {
            free(raiz);
            return NULL;
        }

        if (raiz->raiz_dir != NULL && raiz->raiz_esq == NULL)
        {
            Raiz aux = raiz->raiz_dir;
            free(raiz);
            return aux;
        }

        if (raiz->raiz_dir == NULL && raiz->raiz_esq != NULL)
        {
            Raiz aux = raiz->raiz_esq;
            free(raiz);
            return aux;
        }

        if (raiz->raiz_dir != NULL && raiz->raiz_esq != NULL)
        {
            raiz->valor = bst_maior_valor(raiz->raiz_esq)->valor;
            raiz->raiz_esq = bst_remover(raiz->raiz_esq, raiz->valor);
            return raiz;
        }
    }
    else if (valor_removido > raiz->valor)
    {
        raiz->raiz_dir = bst_remover(raiz->raiz_dir, valor_removido);
    }
    else
    {
        raiz->raiz_esq = bst_remover(raiz->raiz_esq, valor_removido);
    }
    return raiz;
}
