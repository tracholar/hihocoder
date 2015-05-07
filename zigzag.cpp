#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

int Smax(int * A, int n){
	int S[100];
	int i;
	int head[100]={1,0,1};
	for(i=0;i<n;i++){
		if(i<2) S[i] = A[i];
		else if(i==2) S[i] = S[0] + A[2];
		else{
			if(S[i-2]<S[i-3]){
				S[i] = S[i-3]+A[i];
				head[i] = head[i-3];
			}else{
				S[i] = S[i-2]+A[i];
				head[i] = head[i-2];
			}
			
		}
	}
	if(head[n-1])
		return S[n-2];
	else
		return S[n-1];
}

int main(){
	int A[100] = 	
{ 94, 40, 49, 65, 21, 21, 106, 80, 92, 81, 679, 4, 61,  
  6, 237, 12, 72, 74, 29, 95, 265, 35, 47, 1, 61, 397,
  52, 72, 37, 51, 1, 81, 45, 435, 7, 36, 57, 86, 81, 72 };
	int n=0;
	while(A[n]) n++;
	printf("%d\n", Smax(A, n));
	getchar();
}