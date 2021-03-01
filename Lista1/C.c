#include <stdio.h>

int main(){
	int num, qnt=0;
	while(scanf("%d", &num)!=EOF)
		qnt++;
	printf("%d\n", qnt);
	return 0;
}
