#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
using namespace std;

const int maxn=1000;
const int INF=~0U>>2;

int A[maxn+2][2],DP[maxn+2][2];

int main(){
	int n,m,x,y;
	scanf("%d%d%d%d",&n,&m,&x,&y);
	REP(i,1,n)REP(j,1,m){
		char c;
		scanf(" %c",&c);
		A[j][c=='#']++;
	}
	REP(j,1,m)A[j][0]+=A[j-1][0],A[j][1]+=A[j-1][1];
	REP(j,1,m)DP[j][0]=DP[j][1]=INF;
	REP(i,0,m-1)REP(j,x,y){
		DP[i+j][0]=min(DP[i+j][0],DP[i][1]+A[i+j][0]-A[i][0]);
		DP[i+j][1]=min(DP[i+j][1],DP[i][0]+A[i+j][1]-A[i][1]);
	}
	printf("%d\n",min(DP[m][0],DP[m][1]));
	return 0;
}
