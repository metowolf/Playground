#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
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
#define maxn 1000
using namespace std;

int p[maxn*4];

int find(int x){return p[x]==x?x:p[x]=find(p[x]);}
int join(int x,int y){p[find(x)]=find(y);}

int main(){

	//freopen("input.txt","r",stdin);
	
	int T,_=0,n,m;
	char s[22];
	sf("%d",&T);
	while(T--){
		int tot=0;
		map<string,int>R;
		sf("%d%d",&n,&m);
		REP(i,1,maxn)p[i]=i;
		
		REP(i,1,n){
			sf("%s",s);
			int &x=R[s];
			if(!x)x=++tot;
			sf("%s",s);
			int &y=R[s];
			if(!y)y=++tot;
			join(x*2,y*2);
		}
		
		bool flag=1;
		REP(i,1,m){
			sf("%s",s);
			int &x=R[s];
			if(!x)x=++tot;
			sf("%s",s);
			int &y=R[s];
			if(!y)y=++tot;
			if(find(x*2)==find(y*2))flag=0;
			join(x*2+1,y*2);
			join(y*2+1,x*2);
		}
		pf("Case %d: %s\n",++_,flag?"YES":"NO");
	}
	return 0;		
}
