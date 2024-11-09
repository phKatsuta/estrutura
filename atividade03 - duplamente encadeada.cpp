/*
Atividade 03
Monte uma lista duplamente encadeada com [n] 
membros, n>0. Percorra a lista do começo ao 
fim e do fim para o começo.

typedef struct temp{
	int chave;
	struct temp *prox;
	struct temp *ante;
} membro;

start -> 1 -> 2 -> 3 -> 4 -> 5(finish) -> NULL
NULL 	<-	 <-   <-   <-   <-
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

typedef struct temp{
    int chave;
    struct temp *prox;
    struct temp *ante;
} membro;

membro *start = NULL, *novo = NULL, *aux = NULL;
int q = 0;

void insere_lista(int ch, int p) {
    if (p < 1 || p > q + 1) {
        printf("\n\tPosição incorreta!\n\n");
        return;
    }
    novo = (membro *) malloc(sizeof(membro));
    novo->chave = ch;
    q++;
    
    if (start == NULL) {
        start = novo;
        start->prox = NULL;
        start->ante = NULL;
        return;
    }
    
    if (p == 1) {
        novo->prox = start;
        novo->ante = NULL;
        start->ante = novo;
        start = novo;
        return;
    }

    aux = start;
    for (int i = 1; i <= p - 2; i++) aux = aux->prox;
    
    novo->prox = aux->prox;
    if (aux->prox != NULL) aux->prox->ante = novo; // Atualiza o ponteiro ante do próximo nó
    aux->prox = novo;
    novo->ante = aux;
}

void remove_lista(int p) {
    if (p < 1 || p > q) {
        printf("\n\tPosicao incorreta!\n\n");
        return;
    }
    q--;
    
    if (p == 1) {
        aux = start;
        start = start->prox;
        if (start != NULL) start->ante = NULL; // Atualiza o ponteiro ante do novo primeiro nó
        free(aux);
        return;
    }

    aux = start;
    for (int i = 1; i <= p - 2; i++) aux = aux->prox;
    
    novo = aux->prox;
    aux->prox = novo->prox;
    if (novo->prox != NULL) novo->prox->ante = aux; // Atualiza o ponteiro ante do próximo nó
    free(novo);
}
void mostra_retorno() {
    if (start == NULL) {
		printf("\nNULL -> START");
		return;
	}
    
    aux = start;
    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    
    printf("\nNULL <- ");
    while (aux != NULL) {
        printf("%d <- ", aux->chave);
        aux = aux->ante;
    }
    printf("START \n\n");
}

void mostra_lista() {
    if (start == NULL){
		printf("\nSTART -> NULL");
		return;
	}
    
    aux = start;
    printf("\n\nSTART -> ");
    while (aux != NULL) {
        printf("%d -> ", aux->chave);
        aux = aux->prox;
    }
    printf("NULL\n\n");
}

int main() {
    int numLista=0, opc, posicao;
    srand(time(NULL));
    printf("\nAtividade 03");
    do{	
        system("cls"); // Limpa a tela no Windows
	    printf("\n1 - Carregar fila");
	    printf("\n2 - Mostrar fila (START -> NULL)");
	    printf("\n3 - Mostrar fila (NULL <- START)");
	    printf("\n4 - Mostrar fila");
	    printf("\n5 - Remover");
	    printf("\n[N] - Sair");
	    printf("\nSelecione a operacao: ");
	    scanf("%d", &opc);
	    switch (opc){
	    	case 1:
	    		do {
			        printf("\nPor favor, informe a quantidade de valores aleatorios a ser inserido na lista (numero > 0): ");
			        scanf("%d", &numLista);
			    } while (numLista <= 0);
				for (int i = 1; i <= numLista; i++){
					int randomNum = rand()%100;
					insere_lista(randomNum, i);
				}
			    break;
			case 2:
				if (q == 0){
					printf("\nLista vazia...");
					break;
				} else{
					printf("\nQuantidade de posicoes = %d", q);
					mostra_lista();
					break;
				}
			case 3:
				if (q == 0){
					printf("\nLista vazia...");
					break;
				} else{
					printf("\nQuantidade de posicoes = %d", q);
					mostra_retorno();
					break;
				}
			case 4:
				if (q == 0){
					printf("\nLista vazia...");
					break;
				} else{
					printf("\nQuantidade de posicoes = %d", q);
					mostra_lista();
					mostra_retorno();
					break;
				}
			case 5:
				if (q == 0){
					printf("\nLista vazia...");
					break;
				} else{
					mostra_lista();
					printf("\nQuantidade de posicoes = %d", q);
					printf("\nInforme a posicao a ser removida: ");
					scanf("%d", &posicao);
					remove_lista(posicao);
					break;					
				}

			default:
				printf("\nEncerrando...");
				exit(0);
    	}
        // Pausa para o usuário ver a saída antes de limpar a tela
        printf("\nPressione Enter para continuar...\n");
        getchar();  // Captura a nova linha após a entrada do usuário
        getchar();  // Aguarda o pressionamento da tecla Enter
	} while (opc >= 0 && opc <= 5);  // O loop continua enquanto a opção for válida

    return 0;
}

