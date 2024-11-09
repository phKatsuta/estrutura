/*
//Atividade 01
Monte uma estrutura ligada por ponteiros com 
[n] membros, n>0.
Crie uma função para pesquisar a existência de 
uma chave qualquer [ch] nesta estrutura;
caso [ch] exista, indique em que posição está;
se não existir, imprima uma mensagem de erro.
*/
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
typedef struct temp{
	int chave;
	struct temp *prox;
} membro;
membro *start, *novo, *aux;
int q;
void insere_lista (int ch, int p){
	if(p<1 || p> q+1){
		printf("\n\tPosição incorreta!\n\n");
		return;
	}
	novo = (membro *) malloc (sizeof(membro));
	novo -> chave = ch;
	q++;
	if(start == NULL){
		start = novo;
		start -> prox = NULL;
		return;
	}
	if (p == 1){
		novo -> prox = start;
		start = novo;
		return;
	}
	aux = start;
	for (int i = 1; i <= p-2; i++) aux = aux -> prox;
	novo -> prox = aux -> prox;
	aux -> prox = novo;
}
void remove_lista(int p){
	if (p < 1 || p > q){
		printf("\n\tPosição incorreta!\n\n");
		return;
	}
	q--;
	if (p == 1){
		aux = start;
		start = start -> prox;
		free(aux);
		return;
	}
	aux = start;
	for (int i = 1; i <= p-2; i++) aux = aux -> prox;
	novo = aux -> prox;
	aux -> prox = novo -> prox;
	free(novo);
}
void mostra_lista(){
	if (start == NULL) return;
	aux = start;
	printf("\n\n");
	while (aux != NULL){
		printf("%d -> ", aux -> chave);
		aux = aux -> prox;
	}
	printf("NULL\n\n");
}
void pesquisa_lista(int pesquisa){
	aux = start;
	int p = 1;
	while (aux != NULL){
		if (aux -> chave == pesquisa){
			printf("Valor [%d] encontrado na posicao [%d].\n", pesquisa, p);
			return;	
		}
		aux = aux -> prox;
		p++;
	}
	printf("\nDesculpe, valor indisponivel!");
}
main(){
	int numLista, numPesquisa;
	srand(time(NULL));
	printf("\nAtividade 01");
	do{
		printf("\nPor favor, informe o numero de valores aleatórios a ser inserido na lista (numero > 0): ");
		scanf("%d", &numLista);
	} while (numLista <= 0);
	for (int i = 1; i <= numLista; i++){
		int randomNum = rand()%100;
		insere_lista(randomNum, i);
	}
	mostra_lista();
	
	do {
        printf("\nInforme o valor a ser pesquisado: ");
        if (scanf("%d", &numPesquisa) != 1) {
            // Limpar o buffer de entrada
            while (getchar() != '\n');
            printf("\nEntrada invalida. \nEncerrando...\n");
            break; // Sai do loop
        }
        pesquisa_lista(numPesquisa);
    } while (1); // Loop infinito até ser interrompido pelo break
 return 0;
}


