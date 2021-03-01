#include <stdio.h>
#include <stdlib.h>
#define Key(A) (A)
#define less(A,B) (Key(A) < Key(B))
#define lesseq(A,B) (Key(A) <= Key(B))
#define exch(A,B) {int t = A; A=B; B=t;}
#define cmpexch(A,B) {if(less(B,A)) exch(A,B);}

int separa(int *v, int l, int r){
    int c = v[r];
    int j= l;
    for(int i=l; i<r; i++){
        if(lesseq(v[i], c)){
            exch(v[j], v[i]);
            j++;
        }
    }
    exch(v[j], v[r]);
    return j;
}

void quick_sort(int *v, int l, int r){
    if(r<=l) return;
    cmpexch(v[(l+r)/2], v[r]);
    cmpexch(v[l], v[(l+r)/2]);
    cmpexch(v[r], v[(l+r)/2]);

    int j = separa(v, l, r);
    quick_sort(v, l, j-1);
    quick_sort(v,j+1, r);
}
int main(){
    int n;
    scanf("%d", &n);
    int *v = malloc(sizeof(int)*n);
    for(int i=0; i<n; i++)
        scanf("%d", &v[i]);
    quick_sort(v, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d", v[i]);
        i==n-1? printf("\n") : printf(" ");
    }
    free(v);
}