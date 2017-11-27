#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

LL qpow(LL a,LL k,LL mod){
	LL t=1;
	while(k){
		if(k&1)t=t*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return t;
}

double bbp(int n,int b,int K){
	double t=0;
	for(int k=0;k<=n;k++)t+=(double)qpow(16,n-k,8*k+b)/(8*k+b);
	for(int k=n+1;k<=n+1+100;k++)t+=powf(16,n-k)/(8*k+b);
	return K*t;
}

int main(){
	int T,_=0;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);n--;
		double t=bbp(n,1,4)+bbp(n,4,-2)+bbp(n,5,-1)+bbp(n,6,-1);
		t=t-(int)t;
		if(t<0)t++;
		t*=16;
		printf("Case #%d: %d %c\n",++_,n+1,t<10?(int(t)+'0'):((int)t-10+'A'));
	}
	return 0;
}

