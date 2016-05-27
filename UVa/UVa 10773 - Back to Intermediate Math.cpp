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
#define eps 1e-8
using namespace std;

double d,v,u;

int main(){
	//freopen("input.txt","r",stdin);
	int T,_=0;
	sf("%d",&T);
	while(T--){
		sf("%lf%lf%lf",&d,&v,&u);
		pf("Case %d: ",++_);
		if(v>=u||v==0)pf("can't determine\n");
		else pf("%.3f\n",d/(sqrt(u*u-v*v))-d/u+eps);
	}
	return 0;
}
