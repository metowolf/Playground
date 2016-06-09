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

int n,m,q;
int A[maxn+2],DP[maxn+2][30];
int value[maxn+2],cnt[maxn+2],num[maxn+2],Left[maxn+2],Right[maxn+2];

int RMQ(int L,int R){
	if(L>R)return 0;
	int k=log(1.0*(R-L+1))/log(2.0);
	return max(DP[L][k],DP[R-(1<<k)+1][k]);
}

int main(){
	//freopen("input.txt","r",stdin);
	while(~sf("%d",&n),n){
		sf("%d",&q);
		m=0;
		REP(i,1,n)sf("%d",A+i);
		REP(i,1,n){
			if(!m||value[m]!=A[i]){
				value[++m]=A[i];
				cnt[m]=1;
			}
			else cnt[m]++;
			num[i]=m;
		}
		cnt[m+1]=n;
		int k=1;
		int tL=1,tR=cnt[1];
		REP(i,1,m){
			REP(j,1,cnt[i]){
				Left[k]=tL;
				Right[k++]=tR;
			}
			tL+=cnt[i];
			tR+=cnt[i+1];
		}
		
		REP(i,1,m)DP[i][0]=cnt[i];
		for(int j=1;(1<<j)<=m;j++)
			for(int i=1;i+(1<<j)-1<=m;i++)DP[i][j]=max(DP[i][j-1],DP[i+(1<<(j-1))][j-1]);
		
		while(q--){
			int L,R;
			sf("%d%d",&L,&R);
			if(num[L]==num[R])pf("%d\n",R-L+1);
			else pf("%d\n",max(max(Right[L]-L+1,R-Left[R]+1),RMQ(num[L]+1,num[R]-1)));
		}
	}
	return 0;
}
