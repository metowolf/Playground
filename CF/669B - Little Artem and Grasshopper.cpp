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

int n;
int cnt[maxn+2];
int A[maxn+2];
char s[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	sf("%d",&n);
	REP(i,1,n)sf(" %c",s+i);
	REP(i,1,n)sf("%d",A+i);
	
	int now=1,flag;
	for(;;){
		s[now]=='>'?now+=A[now]:now-=A[now];
		if(now>n||now<1){flag=1;break;}
		if(++cnt[now]>=2){flag=0;break;}
	}
	pf(flag?"FINITE":"INFINITE");
	return 0;
}
