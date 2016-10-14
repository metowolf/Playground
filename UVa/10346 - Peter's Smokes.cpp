#include<bits/stdc++.h>
using namespace std;
int main(){
	long long n,k;
	while(~scanf("%lld%lld",&n,&k)){
		long long ans=n;
		while(n>=k)ans+=n/k,n=n/k+n%k;
		printf("%lld\n",ans);
	}
	return 0;
}
