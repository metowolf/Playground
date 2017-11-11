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

int n,t;
int ans1,ans2;

int main(){
	//freopen("input.txt","r",stdin);
	int T,_=0;
	sf("%d",&T);
	while(T--){
		ans1=ans2=0;
		sf("%d",&n);
		REP(i,1,n){
			sf("%d",&t);
			ans1+=10*((t+1)/30+((t+1)%30!=0));
			ans2+=15*((t+1)/60+((t+1)%60!=0));
		}
		pf("Case %d:",++_);
		if(ans1<=ans2)pf(" Mile");
		if(ans2<=ans1)pf(" Juice");
		pf(" %d\n",min(ans1,ans2));
	}
	return 0;
}
