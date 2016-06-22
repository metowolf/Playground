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
#define REP(i,a,b)  for(int i=a;i<=b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define FOR(i,a,b)  for(int i=a;i!=b;++i)
#define CLR(c,x)    memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf   scanf
#define pf   printf
#define inf  (~0U>>2)
#define eps  (1e-8)
#define maxn 100
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int n,m,q;
int A[maxn+2][maxn+2];
struct node{int type,r,c,x;}P[maxn*maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	sf("%d%d%d",&n,&m,&q);
	REP(i,1,q){
		sf("%d",&P[i].type);
		if(P[i].type==1)sf("%d",&P[i].r);
		if(P[i].type==2)sf("%d",&P[i].c);
		if(P[i].type==3)sf("%d%d%d",&P[i].r,&P[i].c,&P[i].x);
	}
	uREP(i,q,1){
		node &e=P[i];
		if(e.type==1){
			int t=A[e.r][m];
			uREP(i,m,2)A[e.r][i]=A[e.r][i-1];
			A[e.r][1]=t;
		}
		if(e.type==2){
			int t=A[n][e.c];
			uREP(i,n,2)A[i][e.c]=A[i-1][e.c];
			A[1][e.c]=t;
		}
		if(e.type==3){
			A[e.r][e.c]=e.x;
		}
	}
	REP(i,1,n)REP(j,1,m)pf("%d%c",A[i][j],j==m?'\n':' ');
		
	return 0;
}
