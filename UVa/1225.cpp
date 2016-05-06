#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#define sf scanf
#define pf printf
#define maxn 
using namespace std;

int num[10];

void cnt(int x){
	while(x){
		num[x%10]++;
		x/=10;
	}
}

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		int n;
		sf("%d",&n);
		CLR(num,0);
		REP(i,1,n)cnt(i);
		REP(i,0,9)pf(i==9?"%d\n":"%d ",num[i]);
	}
	return 0;
}
