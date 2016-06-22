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
#define maxn 100000
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int n,m;
double A[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	sf("%d%d",&n,&m);
	REP(i,1,n){
		int L,R;
		sf("%d%d",&L,&R);
		A[i]=(R/m-(L-1)/m)*1.0/(R-L+1);
	}
	A[0]=A[n];
	double ans=0;
	REP(i,1,n)ans+=A[i-1]+A[i]-A[i-1]*A[i];
	pf("%.15f",ans*2000);
	return 0;
}
