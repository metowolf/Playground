#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <cstdlib>
#include   <cstdio>
#include   <vector>
#include    <cmath>
#include    <queue>
#include     <list>
#include      <map>
#include      <set>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#pragma GCC  optimize("O2")
#define INF  1e5
#define EPS  1e-8
#define maxn 10000000
using namespace std;

bool vis[maxn+2];
long long Prime[700000],top=0;

void Init(){
	for(long long i=2;i<=maxn;i++)if(!vis[i]){
		Prime[top++]=i;
		for(long long j=i*i;j<=maxn;j+=i)vis[j]=1;
	}
}

int main(){

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	Init();
	//return 0;
	long long n;
	while(~scanf("%lld",&n),n){
		if(n<0)n=-n;
		int cnt=0;
		long long ans=0;
		FOR(i,0,top){
			if(Prime[i]>n)break;
			if(n%Prime[i]==0){
				cnt++,ans=Prime[i];
				while(n%Prime[i]==0)n/=Prime[i];
			}
		}
		if(n>ans)ans=n,cnt++;
		printf("%lld\n",cnt>1?ans:-1);
	}
	return 0;
}

