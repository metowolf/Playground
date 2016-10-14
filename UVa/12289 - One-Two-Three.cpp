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

static char *num[]={"one","two","three"};

int main(){
	//freopen("input.txt","r",stdin);
	int T;
	sf("%d",&T);
	while(T--){
		char s[10];
		sf("%s",s);
		FOR(ans,0,3){
			if(strlen(s)==5)ans=2;
			int cnt=0;
			for(int i=0;s[i];i++)cnt+=num[ans][i]!=s[i];
			if(cnt<=1){
				pf("%d\n",ans+1);
				break;
			}
		}
	}
	return 0;
}
