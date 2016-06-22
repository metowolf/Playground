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
#define maxn 50
using namespace std;

int main(){
	int n;
	sf("%d",&n);
	vector<int>V(n);
	FOR(i,0,n)sf("%d",&V[i]);
	sort(V.begin(),V.end());
	int last=0;
	FOR(i,0,n){
		if(V[i]>last){
			V[i]=last+1;
			last=V[i];
		}
	}
	pf("%d",last+1);
	return 0;
}

