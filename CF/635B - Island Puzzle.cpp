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
#define maxn (200000)
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

int n,lena=0,lenb=0;
int A[maxn+2],B[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	sf("%d",&n);
	REP(i,1,n){
		int t;
		sf("%d",&t);
		if(t)A[++lena]=t;
	}
	REP(i,1,n){
		int t;
		sf("%d",&t);
		if(t)B[++lenb]=t;
	}
	int id=1;
	REP(i,1,lenb)if(B[i]==A[1]){id=i;break;}
	int flag=1;
	REP(i,1,lena)if(A[i]!=B[(id+i-1-1)%lenb+1]){flag=0;break;}
	pf(flag?"YES":"NO");
	return 0;
}
