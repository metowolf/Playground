#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#define sf scanf
#define pf printf
#define maxn 80
using namespace std;

char s[maxn+2];

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		sf("%s",s);
		int ans=0,t=0;
		for(int i=0;s[i];i++){
			if(s[i]=='X')t=0;
			else ans+=++t;
		}
		pf("%d\n",ans);
	}
	return 0;
}
