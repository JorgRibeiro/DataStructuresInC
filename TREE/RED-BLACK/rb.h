#ifndef RB_H
#define RB_H

enum cor { VERMELHO, PRETO, DUPLO_PRETO };

typedef struct no
{
    int chave;                                  		// Valor do no
    enum cor cor;                                  		// Cor do no
    struct no *esq, *dir, *pai;               			// PONTEIRO para o NO ESQUERDO, DIREITO E PAI
                         
}no;

typedef no * Raiz;

void inicializar(arvore *raiz);					// INICIALIZA a RAIZ 
void adicionar (int valor, arvore *raiz);			// ADICIONA um NOVO no na Arvore
void remover (int valor, arvore *raiz);'			// REMOVE um no da Arvore

int altura(arvore raiz);					// Calcula a ALTURA da Arvore
int maior(int a, int b);					// Compara dois numeros e retorna o MAIOR
int maior_elemento(arvore raiz);				// Procura o NO com MAIOR valor
int menor_elemento(arvore raiz);				// Procura o NO com MENOR valor
void pre_order(arvore raiz);					// RAIZ -> ESQ -> DIR
void pos_order(arvore raiz);					// ESQ ->  RAIZ -> DIR		
void in_order(arvore raiz);					// ESQ -> DIR ->  RAIZ 	

void imprimir_elemento(arvore raiz);				// Imprime o valor e na cor do elemento
void imprimir(arvore raiz);					// PRE-ORDER


void ajustar(arvore *raiz, arvore elemento);			// Verifica se ha dois vermelhos seguidos e ajusta
void reajustar(arvore *raiz, arvore elemento);			// 
void rotacao_simples_direita(arvore *raiz, arvore pivo);	// Rotacao SIMPLES para a DIREITA
void rotacao_simples_esquerda(arvore *raiz, arvore pivo);	// Rotacao SIMPLES para a ESQUERDA


enum cor cor(arvore elemento);					// Define a cor do NO
int eh_raiz(arvore elemento);					// Verifica se o NO eh a RAIZ
int eh_filho_esquerdo(arvore elemento);				// Verifica se o FILHO eh do NO ESQUERDO
arvore irmao(arvore elemento);					// Retorna o ponteiro do NO IRMAO
arvore tio(arvore elemento);					// Retorna o ponteiro do NO RIO
void retira_duplo_preto(arvore *raiz, arvore elemento);		//

#endif
