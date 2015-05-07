#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;



int dp[100][100];

int LCS(char * X, char * Y, int m, int n){
	//printf("%d\t%d\n", m, n);
	if(m<0 || n<0){
		return 0;
	}
	if(dp[m][n]!=-1) return dp[m][n];
	if(X[m]==Y[n]){
		dp[m][n] = 1 + LCS(X,Y,m-1,n-1);
		return dp[m][n];
	}
	
	dp[m][n] = max(LCS(X,Y,m-1,n), LCS(X,Y,m,n-1));
	return dp[m][n];
	
}
int main(){
	char * s = "hfhfadfasldfjklaspdjlfkas;df", *p="hgfjflakdfjlas;jdflasdfjkasldfjasdfj;asjfl;asjdfl;sd";
	memset(dp, -1, sizeof dp);
	printf("%d\n", LCS(s,p,strlen(s)-1,strlen(p)-1));
	getchar();
}