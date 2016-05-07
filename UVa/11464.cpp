#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define CLR(c,x) memset(c,x,sizeof(c))
#define ESP 1e-8
#define sf scanf
#define pf printf
#define maxn 15
#define INF ~0U>>1
using namespace std;

int n;
int pow2[20];
int m[maxn+3][maxn+3],cm[maxn+3][maxn+3];
int ans;

bool su1(int x){
	REP(i,1,n){
		cm[1][i]=x%2,x/=2;
		if(m[1][i]&&!cm[1][i])return 0;
	}
	return 1;
}

void Try(){
	int t,cnt=0;
	REP(i,1,n)cnt+=(cm[1][i]-m[1][i]);
	REP(i,2,n)REP(j,1,n){
		t=(cm[i-2][j]+cm[i-1][j-1]+cm[i-1][j+1])%2;
		if(!t&&m[i][j])return;else cm[i][j]=t;
		if(t&&!m[i][j])cnt++;
	}
	ans=min(ans,cnt);
}

int solve(){
	sf("%d",&n);
	REP(i,1,n)REP(j,1,n)sf("%d",&m[i][j]);
	for(int i=0;i<pow2[n];i++)if(su1(i))Try();
	return ans==INF?-1:ans;
}

void init(){
	CLR(m,0);CLR(cm,0);
	ans=INF;
}

int main(){
	pow2[0]=1;
	REP(i,1,16)pow2[i]=pow2[i-1]*2;
	int T;
	while(~sf("%d",&T)){
		REP(kase,1,T){
			init();
			pf("Case %d: %d\n",kase,solve());
		}
	}
	return 0;
}

