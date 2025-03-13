#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

Raiz avl_inserir(Raiz raiz, int novo_valor)
{
    if (raiz == NULL)
    {
        Raiz novo = (Raiz)malloc(sizeof(no));
        novo->valor = novo_valor;
        novo->raiz_dir = NULL;
        novo->raiz_esq = NULL;
        novo->fb = 0;
        return novo;
    }
    else if (novo_valor > raiz->valor)
    {
        raiz->raiz_dir = avl_inserir(raiz->raiz_dir, novo_valor);
    }
    else
    {
        raiz->raiz_esq = avl_inserir(raiz->raiz_esq, novo_valor);
    }
    raiz = rotacionar(raiz);
    return raiz;
}

int avl_fator_balanceamento(Raiz raiz){
    int esquerda = avl_altura(raiz->raiz_esq);
    int direita = avl_altura(raiz->raiz_dir);
    return direita - esquerda;
}

void atualizar_fb(Raiz raiz){
    if(raiz != NULL){
        raiz->fb = avl_fator_balanceamento(raiz);
        atualizar_fb(raiz->raiz_dir);
        atualizar_fb(raiz->raiz_esq);
    }
}

Raiz rotacionar(Raiz raiz)
{
    if (raiz == NULL) return NULL;

    raiz->fb = avl_fator_balanceamento(raiz);

    // Rotação dupla à esquerda
    if (raiz->fb == 2) {
        if (raiz->raiz_dir->fb < 0) { 
            raiz->raiz_dir = rot_simples_direita(raiz->raiz_dir);
        }
        raiz = rot_simples_esquerda(raiz);
    }
    // Rotação dupla à direita
    else if (raiz->fb == -2) {
        if (raiz->raiz_esq->fb > 0) { 
            raiz->raiz_esq = rot_simples_esquerda(raiz->raiz_esq);
        }
        raiz = rot_simples_direita(raiz);
    }

    return raiz;
}

Raiz rot_simples_direita(Raiz raiz){

    Raiz pai, dir, esq;
    pai = raiz;
    esq = raiz->raiz_esq;
    dir = raiz->raiz_esq->raiz_dir;

    esq->raiz_dir = pai;
    pai->raiz_esq = dir;
    
    atualizar_fb(esq);

    return esq;

}

Raiz rot_simples_esquerda(Raiz raiz){
    Raiz pai, dir, esq;
    pai = raiz;
    dir = raiz->raiz_dir;
    esq = raiz->raiz_dir->raiz_esq;

    dir->raiz_esq = pai;
    pai->raiz_dir = esq;

    atualizar_fb(dir);

    return dir;

}

void avl_preorder(Raiz raiz)
{
    if (raiz != NULL)
    {
        printf("[%d %d]", raiz->valor, raiz->fb);
        avl_preorder(raiz->raiz_esq);
        avl_preorder(raiz->raiz_dir);
    }
}

void avl_inorder(Raiz raiz)
{
    if (raiz != NULL)
    {
        avl_inorder(raiz->raiz_esq);
        printf("[%d]", raiz->valor);
        avl_inorder(raiz->raiz_dir);
    }
}

void avl_posorder(Raiz raiz)
{
    if (raiz != NULL)
    {
        avl_posorder(raiz->raiz_esq);
        avl_posorder(raiz->raiz_dir);
        printf("[%d]", raiz->valor);
    }
}

void avl_reverso(Raiz raiz)
{
    if (raiz != NULL)
    {
        avl_reverso(raiz->raiz_dir);
        printf("[%d]", raiz->valor);
        avl_reverso(raiz->raiz_esq);
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
        int altura_esq = avl_altura(raiz->raiz_esq);
        int altura_dir = avl_altura(raiz->raiz_dir);
        if (altura_esq > altura_dir)
        {
            return altura_esq + 1;
        }
        else
        {
            return altura_dir + 1;
        }
    }
}

int avl_quant_folhas(Raiz raiz)
{
    if (raiz != NULL)
    {
        int folhas = avl_quant_folhas(raiz->raiz_dir);
        folhas = folhas + avl_quant_folhas(raiz->raiz_esq);
        if (raiz->raiz_dir == NULL && raiz->raiz_esq == NULL)
        {
            return folhas + 1;
        }
        else
            return folhas;
    }

    return 0;
}

void avl_caminho(Raiz raiz, int chave)
{
    if (raiz->valor < chave)
    {
        printf("[%d]", raiz->valor);
        avl_caminho(raiz->raiz_dir, chave);
    }
    else if (raiz->valor > chave)
    {
        printf("[%d]", raiz->valor);
        avl_caminho(raiz->raiz_esq, chave);
    }
    else
        (printf("[%d]", raiz->valor));
}

int avl_valida_caminho(Raiz raiz, int chave)
{
     if (raiz == NULL)
    {
        return 0;
    }

    if (raiz->valor < chave)
    {
        return avl_valida_caminho(raiz->raiz_dir, chave);
    }
    else if (raiz->valor > chave)
    {
        return avl_valida_caminho(raiz->raiz_esq, chave);
    }
    else if (raiz->valor == chave)
    {
        return 1;
    }

    return 0;
}

Raiz avl_maior_valor(Raiz raiz)
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

Raiz avl_remover(Raiz raiz, int valor_removido)
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
            raiz->valor = avl_maior_valor(raiz->raiz_esq)->valor;
            raiz->raiz_esq = avl_remover(raiz->raiz_esq, raiz->valor);
            atualizar_fb(raiz);
            raiz = rotacionar(raiz);
            return raiz;
        }
    }
    else if (valor_removido > raiz->valor)
    {
        raiz->raiz_dir = avl_remover(raiz->raiz_dir, valor_removido);
    }
    else
    {
        raiz->raiz_esq = avl_remover(raiz->raiz_esq, valor_removido);
    }
    atualizar_fb(raiz);
    raiz = rotacionar(raiz);
    return raiz;
}
