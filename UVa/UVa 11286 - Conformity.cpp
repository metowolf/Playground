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
#define INF  ~0U>>2
#define EPS  1e-8
#define maxn 105
using namespace std;

int n,maxx;
int A[5];

int main(){
	//freopen("input.txt","r",stdin);
	while(~scanf("%d",&n),n){
		maxx=0;
		map<int,int>H;
		while(n--){
			for(int i=0;i<5;i++)scanf("%d",A+i);
			sort(A,A+5);
			int t=0;
			for(int i=0;i<5;i++)t=t*500+A[i];
			maxx=max(maxx,H[t]+=1);
		}
		int cnt=0;
		for(map<int,int>::iterator it=H.begin();it!=H.end();it++){
			if(it->second==maxx)cnt+=maxx;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
