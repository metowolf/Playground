#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define ECH(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i) 
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn 20000
using namespace std;

int A[maxn+2],B[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	
	int n,m;
	while(~sf("%d%d",&n,&m),n&&m){
		REP(i,1,n)sf("%d",A+i);
		REP(i,1,m)sf("%d",B+i);
		sort(A+1,A+n+1);
		sort(B+1,B+m+1);
		int cur=1;
		int cost=0;
		REP(i,1,m){
			if(B[i]>=A[cur]){
				cost+=B[i];
				if(++cur>n)break;
			}
		}
		pf(cur<=n?"Loowater is doomed!\n":"%d\n",cost);
	}
	return 0;
}
