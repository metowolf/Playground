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
#pragma GCC  optimize("O2")
#define sf   scanf
#define pf   printf
#define INF  ~0U>>2
#define EPS  1e-8
#define maxn 8
using namespace std;

int n;
int P[maxn+2];
double R[maxn+2],D[maxn+2];

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		sf("%d",&n);
		REP(i,1,n)sf("%lf",R+i);
		sort(R+1,R+n+1);
		double ans=INF;
		do{
			double t=2*R[1];
			D[1]=R[1];
			REP(i,2,n){
				D[i]=R[i];
				FOR(j,1,i)D[i]=max(D[i],D[j]+sqrt((R[i]+R[j])*(R[i]+R[j])-(R[i]-R[j])*(R[i]-R[j])));
				t=max(t,D[i]+R[i]);
			}
			ans=min(ans,t);
		}while(next_permutation(R+1,R+n+1));
		
		pf("%0.3f\n",ans);
	}
	return 0;
}
