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
#define maxn 500
using namespace std;

int n;
int A[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	int T;
	sf("%d",&T);
	while(T--){
		sf("%d",&n);
		REP(i,1,n)sf("%d",A+i);
		sort(A+1,A+n+1);
		int ans=0;
		REP(i,1,n/2)ans+=A[n+1-i]-A[i];
		pf("%d\n",ans);
	}
	return 0;
}
