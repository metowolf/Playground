#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;

int main(){
	LL n;
	while(~scanf("%lld",&n)){
		int ans=0;
		for(LL i=n+1;i<=n<<1;i++)ans+=((i*n)%(i-n)==0);
		printf("%d\n",ans);
		for(LL i=n+1;i<=n<<1;i++){
			if((i*n)%(i-n))continue;
			printf("1/%lld = 1/%lld + 1/%lld\n",n,(i*n)/(i-n),i);
		}
	}
	return 0;
}
