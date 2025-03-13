#ifndef BST_H
#define BST_H

typedef struct no{
    int valor;                  // Valor individual da raiz
    struct no *raiz_dir;        // Ponteiro para a raiz direita
    struct no *raiz_esq;        // Ponteiro para a raiz esquerda
} no;


typedef no * Raiz;


Raiz bst_inserir (Raiz raiz, int novo_valor);            // Funcao para adicionar uma nova raiz para a arvore


void bst_preorder(Raiz raiz);                       // Printa os valores na ordem: Raiz->Esquerda->Direita
void bst_inorder(Raiz raiz);                        // Printa os valores na ordem: Esquerda->Raiz->Direita
void bst_posorder(Raiz raiz);                       // Printa os valores na ordem: Esquerda->Direita->Raiz
void bst_reverso(Raiz raiz);                        // Printa os valores na ordem: Direita->Raiz->Esquerda

int bst_altura(Raiz raiz);                          // Calcula a altura de raiz
int bst_quant_folhas(Raiz raiz);                    // Calcula a Quantidade de folhas em uma raiz

void bst_caminho(Raiz raiz, int chave);             // Faz o caminho até o valor escolhido
int bst_valida_caminho(Raiz raiz, int chave);       // Verifica se o valor escolhido esta em na arvore

Raiz bst_maior_valor(Raiz raiz);                    // procura o maior valor de uma arvore
Raiz bst_menor_valor(Raiz raiz);                    // procura o menor valor de uma arvore
Raiz bst_remover (Raiz raiz, int valor_removido);   // remove o valor de uma arvore

#endif