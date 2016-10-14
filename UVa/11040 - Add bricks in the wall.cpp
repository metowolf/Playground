#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf scanf
#define pf printf
#define maxn 300000
#define endl '\n'
using namespace std;

int A[10][10];

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		CLR(A,0);
		REP(i,1,5)REP(j,1,i)sf("%d",&A[i*2-1][j*2-1]);
		for(int i=9;i>=1;i--){
			if(i%2==1){
				REP(j,1,i)if(!A[i][j])A[i][j]=(A[i-2][j-1]-A[i][j-1]-A[i][j+1])/2;
			}
			else REP(j,1,i)A[i][j]=A[i+1][j]+A[i+1][j+1];
		}
		REP(i,1,9)REP(j,1,i)pf("%d%c",A[i][j],j==i?'\n':' ');
	}
	return 0;
}
