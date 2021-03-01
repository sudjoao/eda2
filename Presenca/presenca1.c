#include <stdio.h>
#include <stdlib.h>

#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define lesseq(A,B) (Key(A) <= Key(B))
#define exch(A,B) {int t = A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

int *intercala(int *a, int la, int ra, int *b, int lb, int rb)
 {
         int ta=(ra-la+1);
         int tb=(rb-lb+1);
 
         int *c=malloc(sizeof(int)*(ta+tb));
 
         int lc=0;
         int rc=(ta+tb-1);
 
         int ia=la, ib=lb,ic=lc;
 
         while(ia<=ra && ib<=rb)
         {
                 if(lesseq(a[ia],b[ib]))
                         c[ic++]=a[ia++];
                 else
                         c[ic++]=b[ib++];
         }
         while(ia<=ra)
                 c[ic++]=a[ia++];
         while(ib<=rb)
                 c[ic++]=b[ib++];
         return c;
 }

void mergesort(int *v,int l,int r)
{
		if(l>=r) return;
		int meio=(l+r)/2;
		mergesort(v,l,meio);
		mergesort(v,meio+1,r);
		int *c=intercala(v,l,meio,v,meio+1,r);
		for(int i=0;i<r-l+1;i++)
				v[l++]=c[i];
		free(c);
}

int main(){
	int n;
	int v[140000];
	int in;
	int i=0;
	int cont = 0;
	scanf("%d", &n);
	while(n--)
		scanf("%d", &v[i++]);
	mergesort(v, 0, i);
	for(int j=0; j<i; j++)
	printf("%d: %d\n", j,v[j]);
	while(scanf("%d", &in)!=EOF){
		for(int j=0; j<i; j++){
			if(in == v[j]){
				printf("sim\n");
				break;
			}
			else if(j==i-1)
				printf("nao\n");
		}
	}
	return 0;
}
