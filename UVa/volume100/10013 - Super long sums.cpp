#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define ECH(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i) 
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn 1000000
using namespace std;

int m,a,b;
int A[maxn+10];

int main(){
	//freopen("input.txt","r",stdin);
	int T;
	sf("%d",&T);
	while(T--){
		CLR(A,0);
		sf("%d",&m);
		uREP(i,m,1)sf("%d %d",&a,&b),A[i]=a+b;
		REP(i,1,m)A[i+1]+=A[i]/10,A[i]%=10;
		while(A[m+1])m++,A[m+1]+=A[m]/10,A[m]%=10;
		uREP(i,m,1)pf("%d",A[i]);
		pf("\n");
		if(T)pf("\n");
	}
	return 0;
}
