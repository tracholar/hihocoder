#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

#define MOD 1000000007
#define ll long long
#define UNDEF -1

ll dp[20][400];
int k_base = 200;
int bits[20], n_bits=0;

ll S(int n, int k){
	if(n<0) return 0;
	int sign = n%2 ? (-1):1;
	int ans=0;
	if(dp[n][k+k_base]!=UNDEF){
		return dp[n][k+k_base];
	}

	for(int j=0;j<=bits[n_bits-1-n];j++){
		int i = k - sign*j;
		ans += S(n-1, i)*10 + j;
	}
	dp[n][k+k_base] = ans;
	return ans;

}
ll cal(ll x, int k){
	
	int bit;
	n_bits = 0;
	while(x){
		bits[n_bits++] = x%10;
		x = x/10;
	}
	memset(dp, UNDEF, sizeof dp);
	return S(n_bits-1, k);
}
int main(){
	ll l,r;
	int k;
	scanf("%lld%lld%d", &l, &r, &k);
	printf("%lld\n", cal(r, k) - cal(l-1, k)); 
}