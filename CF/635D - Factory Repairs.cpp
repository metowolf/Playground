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
#define maxn 200000
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int n,k,a,b,q;
int sum[2][maxn+2];
int A[maxn+2];

inline lowbit(int x){return (x&-x);}

void add(int op,int x,int v){
	for(int i=x;i<=n;i+=lowbit(i))sum[op][i]+=v;
}

int query(int op,int x){
	int t=0;
	for(int i=x;i;i-=lowbit(i))t+=sum[op][i];
	return t;
}

int main(){
	//freopen("input.txt","r",stdin);
	sf("%d%d%d%d%d",&n,&k,&a,&b,&q);
	while(q--){
		int op;
		sf("%d",&op);
		if(op==1){
			int x,y;
			sf("%d%d",&x,&y);
			int t=A[x];
			A[x]+=y;
			add(0,x,min(b,A[x])-min(b,t));
			add(1,x,min(a,A[x])-min(a,t));	
		}
		else{
			int x;
			sf("%d",&x);
			pf("%d\n",query(0,x-1)+query(1,n)-query(1,x+k-1));
		}
	}
	return 0;
}
