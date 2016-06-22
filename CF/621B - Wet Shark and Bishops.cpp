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
#define maxn 3000
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int n;
int A[maxn+2],B[maxn+2];

int main(){
	sf("%d",&n);
	REP(i,1,n){
		int x,y;
		sf("%d%d",&x,&y);
		++A[x+y];
		++B[(y-x<0)?2000-y+x:y-x];
	}
	int sum=0;
	REP(i,0,maxn)sum+=A[i]*(A[i]-1)/2+B[i]*(B[i]-1)/2;
	pf("%d",sum);
	return 0;
}
