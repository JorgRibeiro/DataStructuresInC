#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

Raiz avl_inserir(Raiz raiz, int novo_valor)
{
    if (raiz == NULL)
    {
        Raiz novo = (Raiz)malloc(sizeof(no));
        novo->valor = novo_valor;
        novo->folha_dir = NULL;
        novo->folha_esq = NULL;
        novo->fb = 0;
        return novo;
    }
    else if (novo_valor > raiz->valor)
    {
        raiz->folha_dir = avl_inserir(raiz->folha_dir, novo_valor);
    }
    else
    {
        raiz->folha_esq = avl_inserir(raiz->folha_esq, novo_valor);
    }
    return raiz;
}

int avl_fator_balanceamento(Raiz raiz){
    int esquerda = avl_altura(raiz->folha_esq);
    int direita = avl_altura(raiz->folha_dir);
    return direita - esquerda;
}

void avl_preorder(Raiz raiz)
{
    if (raiz != NULL)
    {
        printf("[%d %d] {%d}", raiz->valor, avl_fator_balanceamento(raiz),raiz->fb);
        avl_preorder(raiz->folha_esq);
        avl_preorder(raiz->folha_dir);
    }
}

void bst_inorder(Raiz raiz)
{
    if (raiz != NULL)
    {
        bst_inorder(raiz->folha_esq);
        printf("[%d]", raiz->valor);
        bst_inorder(raiz->folha_dir);
    }
}

void bst_posorder(Raiz raiz)
{
    if (raiz != NULL)
    {
        bst_posorder(raiz->folha_esq);
        bst_posorder(raiz->folha_dir);
        printf("[%d]", raiz->valor);
    }
}

void bst_reverso(Raiz raiz)
{
    if (raiz != NULL)
    {
        bst_reverso(raiz->folha_dir);
        printf("[%d]", raiz->valor);
        bst_reverso(raiz->folha_esq);
    }
}

int avl_altura(Raiz raiz)
{
    if (raiz == NULL)
    {
        return -1;
    }
    else
    {
        int altura_esq = avl_altura(raiz->folha_esq);
        int altura_dir = avl_altura(raiz->folha_dir);
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
        int folhas = bst_quant_folhas(raiz->folha_dir);
        folhas = folhas + bst_quant_folhas(raiz->folha_esq);
        if (raiz->folha_dir == NULL && raiz->folha_esq == NULL)
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
        bst_caminho(raiz->folha_dir, chave);
    }
    else if (raiz->valor > chave)
    {
        printf("[%d]", raiz->valor);
        bst_caminho(raiz->folha_esq, chave);
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
        return bst_valida_caminho(raiz->folha_dir, chave);
    }
    else if (raiz->valor > chave)
    {
        return bst_valida_caminho(raiz->folha_esq, chave);
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

    while (temp->folha_dir != NULL)
    {
        temp = temp->folha_dir;
    }

    return temp;
}

Raiz avl_remover(Raiz raiz, int valor_removido)
{
     if (raiz == NULL)
    {
        return raiz;
    }
    else if (raiz->valor == valor_removido)
    {

        if (raiz->folha_dir == NULL && raiz->folha_esq == NULL)
        {
            free(raiz);
            return NULL;
        }

        if (raiz->folha_dir != NULL && raiz->folha_esq == NULL)
        {
            Raiz aux = raiz->folha_dir;
            free(raiz);
            return aux;
        }

        if (raiz->folha_dir == NULL && raiz->folha_esq != NULL)
        {
            Raiz aux = raiz->folha_esq;
            free(raiz);
            return aux;
        }

        if (raiz->folha_dir != NULL && raiz->folha_esq != NULL)
        {
            raiz->valor = bst_maior_valor(raiz->folha_esq)->valor;
            raiz->folha_esq = avl_remover(raiz->folha_esq, raiz->valor);
            return raiz;
        }
    }
    else if (valor_removido > raiz->valor)
    {
        raiz->folha_dir = avl_remover(raiz->folha_dir, valor_removido);
    }
    else
    {
        raiz->folha_esq = avl_remover(raiz->folha_esq, valor_removido);
    }
    return raiz;
}
