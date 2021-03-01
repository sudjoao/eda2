#include <stdio.h>
int main(){
	int lines, num, sum=0;
	scanf("%d", &lines);
	while(lines--){
		scanf("%d", &num);
		sum+=num;
	}
	printf("%d\n", sum);

	return 0;
}
