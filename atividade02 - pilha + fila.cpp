/*Atividade 02
Monte [1 pilha] e uma [fila] com [n] membros,
n>0. Junte essas duas estruturas, de modo que 
1 único ponteiro possa percorrê-los até o fim.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct temp {
    int chave;
    struct temp *prox;
} membro;

membro *topo = NULL, *inicio = NULL, *novo = NULL, *aux = NULL, *fim = NULL;

void insere_pilha(int num) {
    novo = (membro*) malloc(sizeof(membro));
    if (novo == NULL) {
        printf("\nErro na alocação de memória.\n");
        return;
    }
    novo->chave = num;
    if (topo == NULL) novo->prox = NULL;
    else novo->prox = topo;
    topo = novo;
}

void insere_fila(int num) {
    novo = (membro*) malloc(sizeof(membro));
    if (novo == NULL) {
        printf("\nErro na alocação de memória.\n");
        return;
    }
    novo->chave = num;
    novo->prox = NULL;
    if (inicio == NULL) inicio = novo;
    else fim->prox = novo;
    fim = novo;
}
void mostra() {
    aux = topo;
    while (aux != NULL) {
        printf("%d\n", aux->chave);
        printf("|\nV\n");
        aux = aux->prox;
    }
    printf("NULL / Start -> ");
    aux = inicio;
    while (aux != NULL) {
        printf("%d -> ", aux->chave);
        aux = aux->prox;
    }
    printf("NULL\n");
}

int main() {
    int valor;

    printf("\nAtividade 02 - Pilha + Lista\n");

    // Preenchendo a pilha
    do {
        printf("\nInforme a quantidade de valores aleatorios a serem carregados na pilha: ");
        scanf("%d", &valor);
    } while (valor <= 0);

    for (int i = 1; i <= valor; i++) {
        int randomNum = rand() % 100;
        insere_pilha(randomNum);
    }

    // Preenchendo a fila
    do {
        printf("\nPor favor, informe a quantidade de valores aleatorios a serem inseridos na fila: ");
        scanf("%d", &valor);
    } while (valor <= 0);

    for (int i = 1; i <= valor; i++) {
        int randomNum = rand() % 100;
        insere_fila(randomNum);
    }

    // Exibindo pilha e fila
    printf("\nResultado pilha + fila:\n");
    mostra();

    return 0;
}
