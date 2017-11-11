#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define maxn 501
using namespace std;

int ans[maxn+2];

int gcd(int a,int b){return b?gcd(b,a%b):a;}

void Initial(){
	ans[1]=0;
	REP(i,2,maxn){
		ans[i]=ans[i-1];
		FOR(j,1,i)ans[i]+=gcd(i,j);
	}
}

int main(){
	Initial();
	int n;
	while(~scanf("%d",&n),n)printf("%d\n",ans[n]);
	return 0;
}
