#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define ECH(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i) 
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
//#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn 50

int n;

int main(){
    int _=0;
    while(~sf("%d",&n)){
    	if(n==-1)break;
    	int cnt=1,ans=0;
		while(cnt*2<=n)cnt<<=1,++ans;
		if(_)pf("\n");
		pf("Case %d: %d",++_,ans+(cnt!=n));
	}
	return 0;
}
