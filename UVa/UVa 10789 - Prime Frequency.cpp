#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf scanf
#define pf printf
#define maxn 2001
#define endl '\n'
using namespace std;

int cnt[128+2];
bool P[maxn+2];
char s[maxn+2];

void init(){
	CLR(P,0);
	P[0]=P[1]=1;
	REP(i,2,maxn)if(!P[i])for(int j=i*i;j<=maxn;j+=i)P[j]=1;
}

int main(){
	
	//freopen("input.txt","r",stdin);

	init();
	int T,_=0;
	sf("%d",&T);
	while(T--){
		CLR(cnt,0);
		sf(" %s",s);
		for(int i=0;s[i];++i)cnt[s[i]]++;
		pf("Case %d: ",++_);
		bool flag=0;
		REP(i,1,128)if(!P[cnt[i]])pf("%c",(char)i),flag=1;
		if(!flag)pf("empty");
		pf("\n");
	}
	return 0;
}

