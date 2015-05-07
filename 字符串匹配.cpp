#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int NaiveSearch(char*str, char*p){
	int i,j;
	int n=strlen(str), m = strlen(p);
	for(i=0;i<n-m+1;i++){
		if(strncmp(str+i,p,m)==0)
			return i;
	}
	return -1;
}

int RabinKarp(char*str, char*p){
	int d=256,P = 91;
	int n=strlen(str), m = strlen(p);
	int dm1 = 1;
	int i,j;
	for(i=0;i<m-1;i++)
		dm1 = (dm1 * d) % P;
	int pp=0,t=0;
	for(i=0;i<m;i++){
		pp = (pp*d+p[i])%P;
		t = (t*d+str[i])%P;
	}
	for(i=0;i<n-m+1;i++){
		if(pp==t){
			if(strncmp(str+i, p, m)==0){
				return i;
			}
		}
		if(i<n-m){
			t = (((t - dm1*str[i])*d+str[i+m])%P + P)%P;
		}
	}
	return -1;
}
void PrefixFunction(int * pi, char * p){
	int m = strlen(p);
	int i,j=-1;
	pi[0] = -1;
	for(i=1;i<m;i++){
		while(j>=0 && p[j+1]!=p[i]) j=pi[j];
		if(p[j+1]==p[i]) j++;
		pi[i] = j;
	}
}
int KMP(char * str, char * p){
	int n=strlen(str), m = strlen(p);
	int pi[10010];
	PrefixFunction(pi, p);
	int i,j=-1;
	int res=0;
	for(i=0;i<n;i++){
		
		while(j>=0 && str[i]!=p[j+1]) j=pi[j];
		if(str[i]==p[j+1]) j++;
		if(j==m-1){
			res++;
			//j = -1;
		}
		
	}
	return res;
}
int Match(char * str, char * p){
	return KMP(str,p);
}

int main(){
	char * str = (char*)malloc(1000010);
	char p[10010];
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s%s", p, str);

		printf("%d\n",Match(str,p));
	}
}