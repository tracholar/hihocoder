#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define StrMaxLen 1000010
int MaxPoliSubstr(char * str){
	char * newstr=new char[2 * StrMaxLen * sizeof(char)];
	int i,j=0;
	newstr[j++] = '#';
	int len=1;
	for(i=0;str[i]!='\0';i++){
		newstr[j++] = str[i];
		newstr[j++] = '#';
		len += 2;
	}
	newstr[j] = 0;

	int * f = new int[2 * StrMaxLen * sizeof(char)];
	memset(f, 0, 2 * StrMaxLen * sizeof(char) * sizeof(int));
	int maxlen = 1;
	int maxright = 0, maxright_j=0;
	
	for(i=0;i<len-maxlen;i++){
		if(2*maxright_j>=i){
			f[i] = min(f[2*maxright_j-i], f[maxright_j] - (i-maxright_j));
		}
		for(j=f[i]+1; (i-j+1>0) & (newstr[i-j]==newstr[i+j]); j++) ;
		f[i] = j-1;
		maxlen = max(maxlen, f[i]);

		
		if(maxright < i+f[i]){
			maxright = i+f[i];
			maxright_j = i;

		}
		
	}
	delete newstr;
	delete f;
	return maxlen;
}

int main(){
	char * s = new char[StrMaxLen];
	int T;
	scanf("%d", &T);
	while(T--){
		scanf("%s", s);
		printf("%d\n", MaxPoliSubstr(s));
	}
}