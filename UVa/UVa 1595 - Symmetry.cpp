#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#include<climits>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf scanf
#define pf printf
#define maxn 300000
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;

int n;
set<PII>S;
set<PII>::iterator it;

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		S.clear();
		int _min=INT_MAX;
		int _max=INT_MIN;
		sf("%d",&n);
		REP(i,1,n){
			int x,y;
			sf("%d%d",&x,&y);
			if(_min>x)_min=x;
			if(_max<x)_max=x;
			S.insert(PII(x,y));
		}
		int m2=_min+_max;
		bool flag=1;
		for(it=S.begin();it!=S.end();it++){
			if(!S.count(PII(m2-it->first,it->second))){flag=0;break;}
		}
		pf(flag?"YES\n":"NO\n");
	}
	return 0;
}
			
		
