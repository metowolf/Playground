#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm> 
#include<cassert>
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
#define maxn 10000
using namespace std;

int ans[maxn+2];

vector<int>P;
vector<int>sum;

bool vis[maxn+2];
void init(){
	REP(i,2,maxn)if(!vis[i]){
		P.push_back(i);
		for(int j=i*i;j<=maxn;j+=i)vis[j]=1;
	}
	int t=0;
	sum.push_back(0);
	FOR(i,0,P.size())t+=P[i],sum.push_back(t);
	CLR(ans,0);
	FOR(i,0,sum.size())FOR(j,0,i){
		if(sum[i]-sum[j]<=maxn)ans[sum[i]-sum[j]]++;
	}
}		

int main(){
	init();
	int n;
	while(~sf("%d",&n),n)pf("%d\n",ans[n]);
	return 0;
}
