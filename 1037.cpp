#include<stdio.h>
#include<string.h>

#define max(a,b) (a>b ? a:b)

int main(){
	int i,j,N, scores1[100], scores2[100], *s1=scores1, *s2=scores2,*tmp;
	int s[100],ans;
	scanf("%d", &N);

	memset(scores1, 0, sizeof scores1);
	memset(scores2, 0, sizeof scores2);

	for(i=0;i<N;i++){
		for(j=0; j<=i; j++){
			scanf("%d", &s[j]);
		}
		
		for(j=0; j<=i; j++){
			if(j==0){
				s2[j] = s1[j] + s[j];
			}else{
				s2[j] = max(s1[j] + s[j], s1[j-1] + s[j]);
			}
		}
		tmp = s1;
		s1 = s2;
		s2 = tmp;
	}
	ans = 0;
	for(i=0;i<N;i++){
		if(s1[i]>ans) ans=s1[i];
	}
	printf("%d", ans);
}