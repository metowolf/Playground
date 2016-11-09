#include<iostream>
#include<cstdio>
#define maxn 200
#define mod 1000000
using namespace std;

int C[maxn+2][maxn+2];

void initial(){
	for(int i=0;i<=maxn;i++)C[i][0]=1;
	for(int i=1;i<=maxn;i++)
		for(int j=1;j<=i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
}

int main(){
	initial();
	int n,k;
	while(~scanf("%d%d",&n,&k),n||k){
		printf("%d\n",C[n+k-1][k-1]);
	}
	return 0;
}
