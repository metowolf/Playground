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
#define maxn 100000
using namespace std;

int n,S;
int A[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	while(~sf("%d%d",&n,&S)){
		REP(i,1,n)sf("%d",A+i);
		int L=0,R=0,t=0,ans=n+1;
		for(L=1;L<=n;t-=A[L++]){
			while(R<n&&t<S)t+=A[++R];
			if(R==n&&t<S)break;
			ans=min(ans,R-L+1);
		}
		pf("%d\n",ans==n+1?0:ans);
	}
	return 0;
}
