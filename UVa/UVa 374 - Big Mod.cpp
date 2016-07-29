#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int qpow(LL a,LL k,LL mod){
	LL t=1;
	while(k){
		if(k&1)t=t*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return t;
}

int main(){
	int a,b,c;
	while(~scanf("%d%d%d",&a,&b,&c)){
		printf("%d\n",qpow(a,b,c));
	}
	return 0;
}
