/*
2 - Mostre o enésimo número da sequência: 
3, 6, 15, 42, 123...
*/
#include <stdio.h>
int seq2(int num){
	if (num <= 1) return 3;
	else return seq2(num - 1) * 3 - 3;
}
int main(){
	int x, valor;
	printf("Informe x: ");
	scanf("%d", &x);
	for (int i = 1; i<=x; i++){
    	printf("posicao %d = %d\n", i,seq2(i));   
	}
}
