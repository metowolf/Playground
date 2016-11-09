#include<bits/stdc++.h>
#define mod 1000000009
using namespace std;
typedef long long LL;

LL exgcd(LL a,LL b,LL &x,LL &y){
	if(!b){
		x=1,y=0;
		return a;
	}
	LL t=exgcd(b,a%b,y,x);
	y-=x*(a/b);
	return t;
}

LL inv(LL a,LL p){
	LL t,x,y;
	t=exgcd(a,p,x,y);
	return t==1?(x+p)%p:-1;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		LL ans=1;
		for(int i=1;i<=n;i++){
			LL t;
			scanf("%lld",&t);
			ans=ans*(2*t+1);
			if(ans>=mod)ans%=mod;
		}
		ans=(ans+mod-1)%mod;
		//ans=ans*inv(2,mod)%mod;
		ans=ans*500000005%mod;
		printf("%lld\n",ans);
	}
	return 0;
}

