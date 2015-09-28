/**
* 问题描述参见 http://hihocoder.com/contest/hiho65/problem/1
* 输入每辆车的起始位置和离开位置，最大速度
* 基本思想是第一辆车离开时，第i辆车都不会超过第i-1辆车的位置
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
		for(int j=0; j<N; j++){  // 最小步进时间
			if(end[j]>start[j])  // 过滤已到达车辆
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