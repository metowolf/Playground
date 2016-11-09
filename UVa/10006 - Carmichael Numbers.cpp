#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;

LL qpow(LL a,LL k,LL mod){
	LL t=1;
	while(k){
		if(k&1)t=t*a%mod;
		k>>=1;
		a=a*a%mod;
	}
	return t;
}

bool isPrime(LL x){
	if(x<2)return 0;
	for(LL i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}

bool isFermat(LL x){
	for(LL i=2;i<x;i++)if(qpow(i,x,x)!=i)return 0;
	return 1;
}

int main(){
	int n;
	while(~scanf("%d",&n),n){
		if(!isPrime(n)&&isFermat(n))printf("The number %d is a Carmichael number.\n",n);
		else printf("%d is normal.\n",n);
	}
	return 0;
}
