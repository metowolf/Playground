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
#define maxn 100
#define INF (~0U>>2)
using namespace std;

int n;
int A[maxn+2][maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	int _=0;
	int a,b;
	while(1){
		n=0;
		REP(i,1,maxn)REP(j,1,maxn)A[i][j]=(i==j)?0:INF;
		while(sf("%d%d",&a,&b),a||b){
			A[a][b]=1;
			n=max(n,max(a,b));
		}
		if(!n)break;
		REP(k,1,n)REP(i,1,n)REP(j,1,n)A[i][j]=min(A[i][j],A[i][k]+A[k][j]);
		int sum=0,cnt=0;
		REP(i,1,n)REP(j,1,n)if(i!=j&&A[i][j]!=INF)sum+=A[i][j],++cnt;
		pf("Case %d: average length between pages = %.3f clicks\n",++_,sum*1.0/cnt);
	}
	return 0;
}
