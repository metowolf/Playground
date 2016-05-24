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
using namespace std;

int n;
int M[maxn+2][maxn+2];
char ans[maxn+2][maxn+2];

void DFS(int now,int no){
	//pf("%d %d\n",now,no);
	ans[no][now]='N';
	REP(i,1,n)if(M[now][i]&&ans[no][i]=='Y'&&i!=no)DFS(i,no);
}

int main(){
	//freopen("input.txt","r",stdin);
	int T,_=0;
	sf("%d",&T);
	while(T--){
		sf("%d",&n);
		REP(i,1,n)REP(j,1,n)sf("%d",&M[i][j]);
		CLR(ans,'Y');
		REP(i,2,n+1)DFS(1,i);
		pf("Case %d:\n",++_);
		REP(i,1,n)if(ans[n+1][i]=='Y')REP(j,1,n)ans[i][j]=ans[j][i]='N';
		REP(i,1,n){
			pf("+");REP(k,2,2*n)pf("-");pf("+\n");
			REP(j,1,n)pf("|%c%s",ans[i][j],j==n?"|\n":"");
		}
		pf("+");REP(k,2,2*n)pf("-");pf("+\n");
	}
	return 0;
}
