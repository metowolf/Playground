#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <cstdlib>
#include   <cstdio>
#include   <vector>
#include    <cmath>
#include    <queue>
#include      <map>
#include      <set>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf   scanf
#define pf   printf
#define inf  (~0U>>2)
#define eps  (1e-8)
#define maxn (200000)
//#pragma comment(linker,"/STACK:36777216")
using namespace std;
typedef pair<int,int> PII;

int n,maxx,d;
int pos=0,ptr=0;
PII A[maxn+2];
set<PII>S;

int main(){
	//freopen("input.txt","r",stdin);
	sf("%d%d%d",&d,&maxx,&n);
	FOR(i,0,n)sf("%d%d",&A[i].first,&A[i].second);
	sort(A,A+n);
	
	long long cost=0;
	S.emplace(0,0);
	
	bool flag=1;
	FOR(i,0,n-1)if(A[i+1].first-A[i].first>maxx)flag=0;
	if(d-A[n-1].first>maxx||A[0].first>maxx)flag=0;
	if(!flag)return pf("-1\n")*0;
	//int TLE=0;// avoid TLE
	while(pos<d){
		int poi=ptr==n?d:A[ptr].first;
		int pid=-1,pcost=-1;
		while(1){
			pid=S.begin()->second;
			if(pos-pid>=maxx)S.erase(S.begin());
			else{
				pcost=S.begin()->first;
				break;
			}
			//if(++TLE>10000000)return pf("-1\n")*0;
		}
		poi=min(poi,pid+maxx);
		cost+=(long long)(poi-pos)*pcost;
		for(pos=poi;ptr<n&&A[ptr].first<=pos;++ptr)S.emplace(A[ptr].second,A[ptr].first);
	}
	pf("%I64d\n",cost);
	return 0;
}

