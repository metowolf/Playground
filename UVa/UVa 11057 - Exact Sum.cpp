#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <cstdlib>
#include   <cstdio>
#include   <vector>
#include    <cmath>
#include    <queue>
#include      <map>
#include<unordered_set>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#pragma GCC  optimize("O2")
#define sf   scanf
#define pf   printf
#define INF  ~0U>>2
#define EPS  1e-8
#define maxn 10000
using namespace std;

int n,ans;
int A[maxn+2];
unordered_set<int>S;

int main(){
	while(~sf("%d",&n)){
		int L,R,sum;
		REP(i,1,n)sf("%d",A+i);
		sf("%d",&sum);
		ans=INF;
		S.clear();
		REP(i,1,n){
			if(S.count(sum-A[i])){
				if(abs(sum-A[i]-A[i])<ans){
					ans=abs(sum-A[i]-A[i]);
					L=A[i],R=sum-A[i];
				}
			}
			S.insert(A[i]);
		}
		pf("Peter should buy books whose prices are %d and %d.\n",min(L,R),max(L,R));
		puts("");
	}
	return 0;
}
