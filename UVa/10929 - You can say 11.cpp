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
#define maxn 1000
using namespace std;

char s[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	while(~sf("%s",s)){
		int len=strlen(s),cnt1=0,cnt2=0;
		if(len==1&&s[0]=='0')break;
		for(int i=0;i<len;i+=2)cnt1+=s[i]-'0';
		for(int i=1;i<len;i+=2)cnt2+=s[i]-'0';
		pf((cnt1-cnt2)%11?"%s is not a multiple of 11.\n":"%s is a multiple of 11.\n",s);
	}
	return 0;
}
