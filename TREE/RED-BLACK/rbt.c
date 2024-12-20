#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

Raiz rbt_inserir(Raiz raiz, int novo_valor)
{
    if (raiz == NULL)
    { // Se a arvore for vazia, Inicializa a raiz
        Raiz novo = (Raiz)malloc(sizeof(no));
        novo->chave = novo_valor;
        novo->cor = 'b'; // Define a cor da raiz como PRETA
        novo->raiz_esq = NULL;
        novo->raiz_dir = NULL;
        novo->raiz_pai = NULL;
        return novo;
    }
    else if (novo_valor > raiz->chave) // Se o novo_valor for maior que a chave
    {
        if (raiz->raiz_dir == NULL) // Se não existir um DIREITO nesse NO
        {
            Raiz novo = (Raiz)malloc(sizeof(no));
            raiz->raiz_dir = novo;
            novo->chave = novo_valor;
            novo->cor = 'r'; // Define a cor do no como Vermelha
            novo->raiz_esq = NULL;
            novo->raiz_dir = NULL;
            novo->raiz_pai = raiz;
        }
        else // Se existir um node DIREITO nesse NO
        {
            raiz->raiz_dir = rbt_inserir(raiz->raiz_dir, novo_valor); // Ele vai continuar a busca, ate um no vazio
        }
    }
    else if ((novo_valor < raiz->chave)) // Se o novo_valor for menor que a chave
    {
        if (raiz->raiz_esq == NULL) // Se não existir um ESQUERDO nesse NO
        {
            Raiz novo = (Raiz)malloc(sizeof(no));
            raiz->raiz_esq = novo;
            novo->chave = novo_valor;
            novo->cor = 'r'; // Define a cor do no como Vermelha
            novo->raiz_esq = NULL;
            novo->raiz_dir = NULL;
            novo->raiz_pai = raiz;
        }
        else
        {
            raiz->raiz_esq = rbt_inserir(raiz->raiz_esq, novo_valor); // Ele vai continuar a busca, ate um no vazio
        }
    }

    return raiz;
}

Raiz rbt_ajuste(Raiz raiz)
{
    return raiz;
}

int rbt_quant_preto(Raiz raiz)
{
    if (raiz != NULL)
    {
        return rbt_quant_preto(raiz->raiz_dir) - rbt_quant_preto(raiz->raiz_esq);
        if(raiz->cor == 'b'){
            return 1;
        } else {
            return 0;
        }
    }
    return 0;
}

void rbt_preorder(Raiz raiz)
{
    if (raiz != NULL)
    {
        printf("[%d %c]", raiz->chave, raiz->cor);
        rbt_preorder(raiz->raiz_esq);
        rbt_preorder(raiz->raiz_dir);
    }
}

void rbt_posorder(Raiz raiz)
{
    if (raiz != NULL)
    {
        rbt_posorder(raiz->raiz_esq);
        rbt_posorder(raiz->raiz_dir);
        printf("[%d %c]", raiz->chave, raiz->cor);
    }
}

void rbt_inorder(Raiz raiz)
{
    if (raiz != NULL)
    {
        rbt_inorder(raiz->raiz_esq);
        printf("[%d %c]", raiz->chave, raiz->cor);
        rbt_inorder(raiz->raiz_dir);
    }
}

void rbt_reverso(Raiz raiz)
{
    if (raiz != NULL)
    {
        rbt_reverso(raiz->raiz_dir);
        printf("[%d %c]", raiz->chave, raiz->cor);
        rbt_reverso(raiz->raiz_esq);
    }
}

void rbt_info(Raiz raiz, int valor)
{
    if (raiz != NULL)
    {
        if (valor > raiz->chave)
        {
            rbt_info(raiz->raiz_dir, valor);
        }
        else if (valor < raiz->chave)
        {
            rbt_info(raiz->raiz_esq, valor);
        }
        else
        {
            printf("---- INFO ----\n");
            printf("Valor: %d\n", raiz->chave);
            printf("Cor: %c\n", raiz->cor);
            if (raiz->raiz_dir == NULL)
                printf("Direito: NULL\n");
            else
                printf("Direito: %d\n", raiz->raiz_dir->chave);

            if (raiz->raiz_esq == NULL)
                printf("Esquerdo: NULL\n");
            else
                printf("Esquerdo: %d\n", raiz->raiz_esq->chave);

            if (raiz->raiz_pai == NULL)
                printf("Pai: NULL\n");
            else
                printf("Pai: %d\n", raiz->raiz_pai->chave);
            printf("Quantidade de nos pretos: %d\n",rbt_quant_preto(raiz));
        }
    }
}

Raiz rbt_maior_valor(Raiz raiz)
{
    if (raiz != NULL)
    {
        Raiz procura = raiz;
        while (procura->raiz_dir != NULL)
        {
            procura = procura->raiz_dir;
        }
        return procura;
    }
    return raiz;
}

Raiz rbt_remover(Raiz raiz, int valor_removido)
{
    if (raiz != NULL)
    {
        if (valor_removido > raiz->chave)
        {
            raiz->raiz_dir = rbt_remover(raiz->raiz_dir, valor_removido);
        }
        else if (valor_removido < raiz->chave)
        {
            raiz->raiz_esq = rbt_remover(raiz->raiz_esq, valor_removido);
        }
        else
        {
            if (raiz->raiz_dir == NULL && raiz->raiz_esq == NULL)
            {
                free(raiz);
                return NULL;
            }
            else if (raiz->raiz_dir != NULL && raiz->raiz_esq == NULL)
            {
                raiz->raiz_dir->raiz_pai = raiz->raiz_pai;
                Raiz temp = raiz->raiz_dir;
                free(raiz);
                return temp;
            }
            else if (raiz->raiz_dir == NULL && raiz->raiz_esq != NULL)
            {
                raiz->raiz_esq->raiz_pai = raiz->raiz_pai;
                Raiz temp = raiz->raiz_esq;
                free(raiz);
                return temp;
            }
            else
            {
                raiz->chave = rbt_maior_valor(raiz->raiz_esq)->chave;
                raiz->raiz_esq = rbt_remover(raiz->raiz_esq, raiz->chave);
                return raiz;
            }
        }
    }
    return raiz;
}
