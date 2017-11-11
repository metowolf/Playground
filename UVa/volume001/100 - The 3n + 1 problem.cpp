#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#pragma comment(linker,"/STACK:36777216")
#pragma GCC optimize("O2")
#define sf scanf
#define pf printf
#define maxn 1000000
#define endl '\n'
using namespace std;

int cache[maxn+2];

int f(long long x){
	//pf("[%d]\n",x);
	if(x<=maxn&&cache[x])return cache[x];
	if(x==1)return 1;
	if(x&1)return x<=maxn?cache[x]=f(3*x+1)+1:f(3*x+1)+1;
	else return x<=maxn?cache[x]=f(x/2)+1:f(x/2)+1;
}

int main(){
	int L,R;
	while(~sf("%d%d",&L,&R)){
		int ans=0,l=min(L,R),r=max(L,R);
		REP(i,l,r)ans=max(ans,f(i));
		pf("%d %d %d\n",L,R,ans);
	}
	//pf("%d",f(991935));
	//REP(i,990990,1000000)pf("%d %d\n",i,f(i));
	return 0;
}
