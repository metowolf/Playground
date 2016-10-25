#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;

int main(){
	int _=0;
	LL n;
	while(~scanf("%lld",&n),n){
		LL ans=0;int cnt=0;
		for(LL i=2;i*i<=n;i++){
			LL t=1;
			while(n%i==0)t*=i,n/=i;
			if(t!=1)ans+=t,cnt++;
		}
		if(n!=1)ans+=n,cnt++;
		ans+=max(0,2-cnt);
		printf("Case %d: %lld\n",++_,ans);
	}
	return 0;
}
