#include <stdio.h>
#include <stdlib.h>
#include "rbt.h"

Raiz rbt_inserir(Raiz raiz, int novo_valor)
{
    Raiz novo = (Raiz)malloc(sizeof(no));           // Criando um novo no
    novo->chave = novo_valor;                       // Atribuindo seu valor
    novo->raiz_esq = NULL;                          
    novo->raiz_dir = NULL;
    novo->cor = 'r';                                // colocando sua cor como RED

    if (raiz == NULL)                               // Se a arvore for vazia, retorna o novo no como raiz
    {                    
        novo->cor = 'b';                            // Define a cor da raiz como PRETA
        novo->raiz_pai = NULL;
        return novo;
    }
    else
    {
        Raiz posicao = raiz;                         // Um ponteiro auxiliar para rodar o código

        while (1)                                    // Um laço infinito até achar a posição do novo nó
        {
            if (novo_valor > posicao->chave)         // Se encontrar o novo_valor for maior que o da chave
            {
                if (posicao->raiz_dir == NULL)       // Se não houver um no na direita, o novo_no se posiciona 
                {
                    posicao->raiz_dir = novo;
                    novo->raiz_pai = posicao;
                    break;
                }
                else                                 // Se houver um no na direita, a procura continua     
                {
                    posicao = posicao->raiz_dir;
                }
            }
            else                                     // Se encontrar o novo_valor for menor que o da chave
            {       
                if (posicao->raiz_esq == NULL)       // Se não houver um no na esquerda, o novo_no se posiciona 
                {
                    posicao->raiz_esq = novo;
                    novo->raiz_pai = posicao;
                    break;
                }
                else                                // Se houver um no na esquerda, a procura continua       
                {
                    posicao = posicao->raiz_esq;
                }
            }
        }
    }

    raiz = rbt_ajuste(raiz, novo);                  // Ao final da inserção, a raiz e o novo nó entram para um ajuste

    return raiz;
}

Raiz rbt_ajuste(Raiz raiz, Raiz novo)
{
    Raiz posiciona = novo;

    while (posiciona->raiz_pai != NULL)
    {
        Raiz pai = posiciona->raiz_pai;
        Raiz vo = posiciona->raiz_pai->raiz_pai;

        if(posiciona->cor == 'r' && pai->cor == 'r' ){          // quebra da regra, Pai e filho vermelhos
            if(posiciona == pai->raiz_dir){                     // posiciona é igual ao filho direito de pai
                Raiz Tio;                                       // Tio é criado
                if(pai == vo->raiz_dir){                        // Pai é igual ao filho direito de vo
                    Tio = vo->raiz_esq;                         // Tio é esquerdo de vo
                    if(Tio == NULL){                            // rotação simples esquerda
                        
                    } else {
                        Tio->cor = 'b';
                        pai->cor = 'b';
                        if(vo->raiz_pai != NULL){ vo->cor = 'r'; }  // se Vo não for a raiz
                       
                    }
                } else {                                        // Pai é igual ao filho esquerdo de vo

                }
            } else {                                            // posiciona é igual ao filho esquerdo de pai

            }


        }

        posiciona = posiciona->raiz_pai;
    }
    
    

    return raiz;
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

