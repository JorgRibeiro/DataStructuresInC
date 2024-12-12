#ifndef AVL_H
#define AVL_H

typedef struct no{
    int valor;
    struct no *folha_dir;
    struct no *folha_esq;
} no;


typedef no * Raiz;


Raiz bst_inserir (Raiz raiz, int novo_valor);

int avl_fator_balanceamento(Raiz raiz);

void bst_preorder(Raiz raiz);
void bst_inorder(Raiz raiz);
void bst_posorder(Raiz raiz);
void bst_reverso(Raiz raiz);

int bst_altura(Raiz raiz);
int bst_quant_folhas(Raiz raiz);

void bst_caminho(Raiz raiz, int chave);
int bst_valida_caminho(Raiz raiz, int chave);

Raiz bst_maior_valor(Raiz raiz);
Raiz bst_remover (Raiz raiz, int valor_removido);

#endif