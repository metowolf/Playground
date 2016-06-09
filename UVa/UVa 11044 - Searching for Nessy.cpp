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
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	int T;
	sf("%d",&T);
	while(T--){
		int a,b;
		sf("%d%d",&a,&b);
		pf("%d\n",(a/3)*(b/3));
	}
	return 0;
}
