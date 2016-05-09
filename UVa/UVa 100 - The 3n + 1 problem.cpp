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

int f(int x){
	int cnt=1;
	while(x!=1){
		if(x&1)x=3*x+1;
		else x/=2;
		cnt++;
	}
	return cnt;
}

int main(){
	int L,R;
	while(~sf("%d%d",&L,&R)){
		int ans=0;
		REP(i,min(L,R),max(L,R))ans=max(ans,f(i));
		pf("%d %d %d\n",L,R,ans);
	}
	return 0;
}
