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
#define maxn 15
#define endl '\n'
using namespace std;

int n;
int A[maxn+2];
bool flag;

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		sf("%d",&n);
		REP(i,1,n)sf("%d",A+i);
		REP(__,1,1000){
			A[n+1]=A[1];
			REP(i,1,n)A[i]=abs(A[i]-A[i+1]);
			flag=0;
			REP(i,1,n)if(A[i]){flag=1;break;}
			if(!flag)break;
		}
		pf(flag?"LOOP\n":"ZERO\n");
	}
	return 0;
}
