#include<stdio.h>
#include<string.h>

#define max(a,b) (a>b?a:b)
int main(){
	int N, M,i,j;

	int P[100010], need[500], value[500];

	scanf("%d%d", &N, &M);
	memset(P, 0, sizeof P);

	for(i=0; i<N; i++){
		scanf("%d%d", need+i, value+i);
	}
	for(i=0; i<N; i++){
		for(j=M; j>=need[i]; j--){
			P[j] = max(P[j], P[j - need[i]] + value[i]);
		}
	}
	printf("%d", P[M]);
}