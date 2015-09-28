/**
* ���������μ� http://hihocoder.com/contest/hiho65/problem/1
* ����ÿ��������ʼλ�ú��뿪λ�ã�����ٶ�
* ����˼���ǵ�һ�����뿪ʱ����i���������ᳬ����i-1������λ��
*/
#include<iostream>
#define MAXN 3
#define NIL -1
using namespace std;

int main(){
	int N;
	double start[MAXN], end[MAXN], speed[MAXN], runtime[MAXN]={0};
	int prev[MAXN];
	memset(runtime, 0 , sizeof(double)*MAXN);

	scanf("%d", &N);
	for(int i=0;i<N;i++){
		scanf("%lf%lf%lf", start+i, end+i, speed+i);
		prev[i] = i-1;
	}
	prev[0] = NIL;

	int leftcar = N;
	while(leftcar>0){
		double span = 1e10;
		for(int j=0; j<N; j++){  // ��С����ʱ��
			if(end[j]>start[j])  // �����ѵ��ﳵ��
				span = min(span, (end[j]-start[j])/speed[j]); 
		}

		for(int j=0; j<N; j++){
			if(end[j]>start[j]){
				runtime[j] += span;
				start[j] = min(end[j], start[j]+speed[j]*span);
				if(prev[j]!=NIL)
					start[j] = min(start[j], start[prev[j]]);
				if(start[j]==end[j]) {
					
					leftcar--;
				}
			}
		}
		for(int j=0;j<N;j++){
			int k=j;
			do{
				k++;
			}while(k<N && prev[k]==NIL);

			prev[k] = prev[j];
			prev[j]=NIL;
		}
	}
}