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
#define maxn 50
using namespace std;
typedef long long LL;

struct Hash{
	static const int mask=0x7fffff;
	int p[0x800000],q[0x800000];
	
	void clear(){CLR(q,0);}
	int& operator [](int k){
		int i;
		for(i=k&mask;q[i]&&p[i]!=k;i=(i+1)&mask);
		p[i]=k;
		return q[i];
	}
}Hash;


int n,P[10];

void init(){
	P[0]=1;
	REP(i,1,9)P[i]=P[i-1]*10;
}

int nxt(int k){
	LL t=(LL)k*k;
	while(t>=P[n])t/=10;
	return t;
}

int main(){
	init();
	int T;
	sf("%d",&T);
	while(T--){
		int k;
		sf("%d%d",&n,&k);
		int ans=k;
		Hash.clear();
		do{
			Hash[k]=1;
			k=nxt(k);
			ans=max(ans,k);
		}while(!Hash[k]);
		pf("%d\n",ans);
	}
	return 0;
}
