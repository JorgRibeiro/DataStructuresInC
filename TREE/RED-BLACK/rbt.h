#ifndef RBT_H
#define RBT_H

typedef struct no
{
    int chave;                                  // Valor do no
    char cor;                                   // Cor do no
    struct no *raiz_esq;                        // ponteiro para o no Esquerdo 
    struct no *raiz_dir;                        // ponteiro para o no Direito
    struct no *raiz_pai;                        // ponteiro para o Pai desse No
}no;

typedef no * Raiz;

Raiz rbt_inicializar(Raiz raiz, int valor);     // Inicializa a Raiz com a cor = Preta e o Pai = NULL
Raiz rbt_inserir(Raiz raiz, int valor);         // Insere um novo nó vermelho para a arvore

void rbt_preorder(Raiz raiz);                   // Printa os valores na ordem: Raiz->Esquerda->Direita
void rbt_inorder(Raiz raiz);                    // Printa os valores na ordem: Esquerda->Raiz->Direita
void rbt_posorder(Raiz raiz);                   // Printa os valores na ordem: Esquerda->Direita->Raiz
void rbt_reverso(Raiz raiz);                    // Printa os valores na ordem: Direita->Raiz->Esquerda

void rbt_info(Raiz raiz, int valor);            // Mostra todas as informações de um no

Raiz rbt_remover (Raiz raiz, int valor_removido);

#endif