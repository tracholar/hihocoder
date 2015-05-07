#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int main(){
	int N;
	int res = 0;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		int d;
		scanf("%d",&d);
		res ^= d;
	}
	if(res==0){
		printf("Bob");
	}else{
		printf("Alice");
	}
}