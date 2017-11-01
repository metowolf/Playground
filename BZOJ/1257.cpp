#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n,m;
	scanf("%lld%lld",&n,&m);
	LL ans=0;
	if(n>m)ans=(n-m)*m;
	for(LL i=1,j;i<=min(n,m);i=j+1){
		j=min(m/(m/i),n);
		ans+=(j-i+1)*m-(i+j)*(j-i+1)/2LL*(m/i);
	}
	printf("%lld\n",ans);
	return 0;
}

