#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

Raiz rbt_inserir(Raiz raiz, int novo_valor)
{
        Raiz novo = (Raiz)malloc(sizeof(no));
        novo->chave = novo_valor;
        novo->raiz_esq = NULL;
        novo->raiz_dir = NULL;
        novo->cor = 'r'; 

    if (raiz == NULL)
    { // Se a arvore for vazia, Inicializa a raiz
        novo->cor = 'b'; // Define a cor da raiz como PRETA
        novo->raiz_pai = NULL;
        return novo;
    } else{
        Raiz posicao = raiz;                    // Um ponteiro auxiliar para rodar o código
        
        while(1){
            if(novo_valor > posicao->chave){
                if(posicao->raiz_dir == NULL){
                    posicao->raiz_dir = novo;
                    novo->raiz_pai = posicao;
                    break;
                } else {
                    posicao = posicao->raiz_dir;
                }
            } else {
                 if(posicao->raiz_esq == NULL){
                    posicao->raiz_esq = novo;
                    novo->raiz_pai = posicao;
                    break;
                } else {
                    posicao = posicao->raiz_esq;
                }
            }
        }
    }

    raiz = rbt_ajuste(raiz, novo);

    return raiz;
}

Raiz rbt_ajuste(Raiz raiz, Raiz novo)
{
    Raiz posicao = novo;      

   while(posicao != raiz){
        if(posicao->cor == 'r' && posicao->raiz_pai->cor == 'r'){
            if(posicao == posicao->raiz_pai->raiz_dir){
              
                if(posicao->raiz_pai->raiz_pai->raiz_esq != NULL){      
                    if(rbt_tio_E(posicao) == 1)   {                       // tio esquerdo eh vermelho  -   recolorir
                    posicao->raiz_pai->cor = 'b';
                    posicao->raiz_pai->raiz_pai->raiz_esq->cor = 'b';
                    if(posicao->raiz_pai->raiz_pai != raiz){
                        posicao->raiz_pai->raiz_pai->cor = 'r';
                        }
                    }
                } else {                                                 // tio esquerdo eh preto externo  -  rotacao simples esquerda       
                   
                    Raiz vo = posicao->raiz_pai->raiz_pai;
                    Raiz pai = posicao->raiz_pai;

                    pai->raiz_esq = vo;
                    
                    if(vo->raiz_pai != NULL){
                        pai->raiz_pai = vo->raiz_pai;
                        if(vo == vo->raiz_pai->raiz_dir){
                            vo->raiz_pai->raiz_dir = pai;
                        } else { vo->raiz_pai->raiz_esq = pai;}
                    }else {pai->raiz_pai = NULL;}

                    vo->raiz_dir = NULL;
                    vo->raiz_pai = pai;

                    pai->cor = 'b';
                    vo->cor = 'r';

                    if(vo == raiz){
                        return pai;
                    }
                }
            } else if(posicao == posicao->raiz_pai->raiz_esq){
                if(rbt_tio_D(posicao) == 1){                                  // tio direito eh vermelho
                    posicao->raiz_pai->cor = 'b';
                    posicao->raiz_pai->raiz_pai->raiz_dir->cor = 'b';
                    if(posicao->raiz_pai->raiz_pai != raiz){
                        posicao->raiz_pai->raiz_pai->cor = 'r';
                    }
                }
            }
        }

        posicao = posicao->raiz_pai;
   }

    return raiz;
}

int rbt_tio_E(Raiz raiz)
{

    if(raiz->raiz_pai->raiz_pai->raiz_esq->cor == 'r'){
        return 1;
    }

     if(raiz->raiz_pai->raiz_pai->raiz_esq->cor == 'b'){
        return 2;
    }

    return 0;

}

int rbt_tio_D(Raiz raiz)
{
     if(raiz->raiz_pai->raiz_pai->raiz_dir == NULL){
        return 0;
    }

    if(raiz->raiz_pai->raiz_pai->raiz_dir->cor == 'r'){
        return 1;
    }

     if(raiz->raiz_pai->raiz_pai->raiz_dir->cor == 'b'){
        return 2;
    }
}

int rbt_quant_no_preto(Raiz raiz)
{
    if (raiz == NULL) {
        return 0; 
    }

    int altura_esq = rbt_quant_no_preto(raiz->raiz_esq);
    int altura_dir = rbt_quant_no_preto(raiz->raiz_dir);

    int maior_caminho = (altura_esq > altura_dir) ? altura_esq : altura_dir;

    if (raiz->cor == 'b') {
        return maior_caminho + 1; 
    }

    return maior_caminho; 
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
            printf("Quant de nos pretos: %d\n", rbt_quant_no_preto(raiz->raiz_dir) + rbt_quant_no_preto(raiz->raiz_esq));
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
               /* raiz = rbt_ajuste(raiz);*/
                return raiz;
            }
        }
    }
    /*raiz = rbt_ajuste(raiz);*/
    return raiz;
}
