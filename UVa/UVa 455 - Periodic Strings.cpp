#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
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
		int len=strlen(s);
		REP(i,1,len){
			if(len%i)continue;
			bool flag=1;
			FOR(j,i,len)if(s[j-i]!=s[j]){flag=0;break;}
			if(flag){
				pf("%d\n",i);
				break;
			}
		}
		if(T)puts("");
	}		
	return 0;
}
