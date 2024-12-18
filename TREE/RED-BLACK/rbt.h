#ifndef RBT.H
#define RBT.H

typedef struct no
{
    int valor;
    char cor = 'red';
    struct rbt *raiz_dir;
    struct rbt *raiz_esq;
    
}no;

typedef no * Raiz;

Raiz rbt_inserir(Raiz raiz, int valor);

void rbt_preorder(Raiz raiz);                   // Printa os valores na ordem: Raiz->Esquerda->Direita
void rbt_inorder(Raiz raiz);                    // Printa os valores na ordem: Esquerda->Raiz->Direita
void rbt_posorder(Raiz raiz);                   // Printa os valores na ordem: Esquerda->Direita->Raiz
void rbt_reverso(Raiz raiz);                    // Printa os valores na ordem: Direita->Raiz->Esquerda

Raiz rbt_remover (Raiz raiz, int valor_removido);

#endif