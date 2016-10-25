#include<bits/stdc++.h>
#define maxn 1000
using namespace std;
typedef unsigned long long ULL;

ULL n;
ULL f[maxn*maxn+100];

ULL qpow(ULL a,ULL k,ULL mod){
	ULL t=1;
	while(k){
		if(k&1)t=t*a%mod;
		k>>=1;
		a=a*a%mod;
	}
	return t;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		ULL a,b;
		scanf("%llu%llu%llu",&a,&b,&n);
		ULL loop=0;
		f[0]=0,f[1]=1%n;
		for(int i=2;i<=n*n+10;i++){
			f[i]=(f[i-2]+f[i-1])%n;
			if(f[i-1]==f[0]&&f[i]==f[1]){
				loop=i-1;
				break;
			}
		}

		/*for(int i=0;i<=loop+2;i++)cout<<i<<":"<<f[i]<<endl;
		cout<<loop<<endl;*/

		printf("%llu\n",f[qpow(a%loop,b,loop)]);
	}
	return 0;
}

