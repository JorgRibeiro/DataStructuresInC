#ifndef RBT_H
#define RBT_H

typedef struct no
{
    int chave;
    char cor;
    struct no *raiz_esq;
    struct no *raiz_dir;
    struct no *raiz_pai;
}no;

typedef no * Raiz;

Raiz rbt_inserir(Raiz raiz, int valor);
Raiz rbt_inicializar(Raiz raiz, int valor);

void rbt_preorder(Raiz raiz);                   // Printa os valores na ordem: Raiz->Esquerda->Direita
void rbt_inorder(Raiz raiz);                    // Printa os valores na ordem: Esquerda->Raiz->Direita
void rbt_posorder(Raiz raiz);                   // Printa os valores na ordem: Esquerda->Direita->Raiz
void rbt_reverso(Raiz raiz);                    // Printa os valores na ordem: Direita->Raiz->Esquerda

void rbt_info(Raiz raiz, int valor);

Raiz rbt_remover (Raiz raiz, int valor_removido);

#endif