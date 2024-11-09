/*
1 - Mostre o enésimo número da sequência, n >= 1:
4, 7, 13, 25, 49...7
*/

#include <stdio.h>
int seq1(int num){
	if (num <= 1) return 4;
	else return seq1(num - 1) * 2 - 1;
}
int main(){
	int x, valor;
	printf("Informe x: ");
	scanf("%d", &x);
	for (int i = 1; i<=x; i++){
    	printf("posicao %d = %d\n", i,seq1(i));   
	}
}
