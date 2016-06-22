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
#define inf  (~0ULL>>2)
#define eps  (1e-8)
#define maxn 50
using namespace std;

inline bool Leap(int x){return x%400==0||(x%4==0&&x%100);} 

int main(){
	int a,b,t=0;
	sf("%d",&a);
	for(b=a;t+=365+Leap(++a),t%7||Leap(a)^Leap(b););
	pf("%d",a);
	return 0;
}
