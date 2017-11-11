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
#define maxn 800
using namespace std;

int p[maxn+2];
int findset(int x){return p[x]==x?x:p[x]=findset(p[x]);}

int main(){
	int T,n,a,b,cnt1,cnt2;
	char op;
	string s;
	
	sf("%d",&T);
	while(T--){
		sf("\n%d\n",&n);
		REP(i,1,n)p[i]=i;
		cnt1=cnt2=0;
		while(1){
			if(!getline(cin,s)||s.empty())break;
			sscanf(s.c_str(),"%c%d%d",&op,&a,&b);
			if(op=='c')p[findset(a)]=findset(b);
			else findset(a)==findset(b)?cnt1++:cnt2++;
		}
		pf("%d,%d\n",cnt1,cnt2);
		if(T)pf("\n");
	}
	return 0;
}
