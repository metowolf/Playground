#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf scanf
#define pf printf
#define maxn 300000
#define endl '\n'
using namespace std;

int n;

int main(){
	int _=0;
	int T;
	sf("%d",&T);
	while(T--){
		sf("%d",&n);
		if(n<0)n=-n;
		int cnt=0;
		for(int i=1;;i++){
			cnt+=i;
			if(cnt>=n&&(cnt-n)%2==0){
				if(_++)puts("");
				pf("%d\n",i);
				break;
			}
		}
	}
	return 0;
}
