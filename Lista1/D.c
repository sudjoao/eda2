#include <stdio.h>

#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define exch(A,B) {int t = A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

int main(){
	int numbers[1000], cont=0;
	while(scanf("%d", &numbers[cont])!=EOF)cont++;
	for(int i =0; i<cont; i++){
		for(int j=i+1; j<cont; j++){
			cmpexch(numbers[i], numbers[j]);
		}
	}
	for(int i=0; i<cont; i++){
		printf("%d", numbers[i]);
		if(i == cont-1)
			printf("\n");
		else
			printf(" ");
	}
	return 0;
}
