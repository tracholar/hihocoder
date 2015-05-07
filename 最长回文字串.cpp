/**
author: tracholar
github: http://github.com/tracholar
最长回文字串的DP算法，时间复杂度O(n^2)   
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;


int MaxLenSubStr(char * s){
	int maxlen = 0;
	int dp[10000];
	int i,j,x,y;
	int n = strlen(s);

	memset(dp, 0, sizeof dp);
	for(x=0; x<n; x++){
		
		for(y=x; y<n; y++){
			j = y;
			i = j - x;
			if(s[i]!=s[j])  dp[i*n+j] = 0;
			else if(i==j) {
				dp[i*n+j] = 1;
				maxlen = max(maxlen, 1);
			}
			else{
				if(dp[i*n+j] = j-1>i ? dp[(i+1)*n + j - 1]:1){
					maxlen = max(maxlen, j-i+1);
				}
			}
		}
	}
	return maxlen;
}
int main(){
	char s[100];
	int i,T;
	scanf("%d", &T);
	for(i=0;i<T;i++){
		scanf("%s", s);
		printf("%d", MaxLenSubStr(s));
	}
	

}