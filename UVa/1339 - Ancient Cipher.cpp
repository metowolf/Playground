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
#define maxn 100
using namespace std;

int cnt1[26],cnt2[26];
char s1[maxn+2],s2[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	while(~sf("%s%s",s1,s2)){
		CLR(cnt1,0),CLR(cnt2,0);
		for(int i=0;s1[i];i++)cnt1[s1[i]-'A']++;
		for(int i=0;s2[i];i++)cnt2[s2[i]-'A']++;
		sort(cnt1,cnt1+26);
		sort(cnt2,cnt2+26);
		bool flag=1;
		FOR(i,0,26)if(cnt1[i]!=cnt2[i])flag=0;
		pf(flag?"YES\n":"NO\n");
	}
	return 0;
}
