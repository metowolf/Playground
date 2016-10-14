#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

/*LL H(int n){
	LL res=0;
	for(int i=1;i<=n;i++)res+=n/i;
	return res;
}*/

LL _H(LL n){
	LL res=0;
	for(LL i=1;i*i<=n;i++)res+=2*(n/i);
	LL t=sqrt(n);
	return res-t*t;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL n;
		scanf("%lld",&n);
		printf("%lld\n",_H(n));
	}
	return 0;
}
