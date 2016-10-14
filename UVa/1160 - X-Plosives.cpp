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
#define maxn 100000
using namespace std;

int p[maxn+2];

int findset(int x){return p[x]==x?x:p[x]=findset(p[x]);}

int main(){
	//freopen("input.txt","r",stdin);
	
	int a,b;
	
	while(~sf("%d",&a)){
		REP(i,0,maxn)p[i]=i;
		int cnt=0;
		while(~a){
			sf("%d",&b);
			int ta=findset(a),tb=findset(b);
			if(ta==tb)cnt++;
			else p[ta]=tb;
			sf("%d",&a);
		}
		pf("%d\n",cnt);
	}
	
	return 0;
}
