#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

long long dp[2500+2][4+2];

int main(){
	int n;
	scanf("%d",&n);
	dp[0][0]=1;
	REP(i,1,n)REP(k,1,4)REP(j,0,i-1)if(i-j<(n+1)/2)
		dp[i][k]+=dp[j][k-1];
	printf("%lld\n",dp[n][4]);
	return 0;
}
