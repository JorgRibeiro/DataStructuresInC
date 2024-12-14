#ifndef AVL_H
#define AVL_H

typedef struct no{
    int valor;              // Valor individual da raiz
    int fb;                 // Fator de Balanco
    struct no *raiz_dir;    // Ponteiro para a raiz direita
    struct no *raiz_esq;    // Ponteiro para a raiz esquerda
} no;

typedef no * Raiz;


Raiz avl_inserir (Raiz raiz, int novo_valor);   // Funcao para adicionar uma nova raiz para a arvore

int avl_fator_balanceamento(Raiz raiz);         // Funcao para calcular o Fator de Balanceamento
void atualizar_fb(Raiz raiz);                   // Funcao para aplicar o valor de Fator de Balanceamento nas raizes da arvore

Raiz rotacionar(Raiz raiz);                     // Funcao para Rotacionar os valores desbalanceados

Raiz rot_simples_direita(Raiz raiz);            // rotacao simples para a direita
Raiz rot_simples_esquerda(Raiz raiz);           // rotacao simples para a esquerda

void avl_preorder(Raiz raiz);                   // Printa os valores na ordem: Raiz->Esquerda->Direita
void avl_inorder(Raiz raiz);                    // Printa os valores na ordem: Esquerda->Raiz->Direita
void avl_posorder(Raiz raiz);                   // Printa os valores na ordem: Esquerda->Direita->Raiz
void avl_reverso(Raiz raiz);                    // Printa os valores na ordem: Direita->Raiz->Esquerda

int avl_altura(Raiz raiz);                      // Calcula a altura de raiz
int avl_quant_folhas(Raiz raiz);                // Calcula a Quantidade de folhas em uma raiz

void avl_caminho(Raiz raiz, int chave);         // Faz o caminho até o valor escolhido
int avl_valida_caminho(Raiz raiz, int chave);   // Verifica se o valor escolhido esta em na arvore

Raiz avl_maior_valor(Raiz raiz);                    // procura o maior valor de uma arvore
Raiz avl_remover (Raiz raiz, int valor_removido);   // remove o valor de uma arvore

#endif