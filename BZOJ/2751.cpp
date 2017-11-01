#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef long long LL;
typedef pair<LL,LL> PLL;

const LL mod=1e9+7;
const int maxn=1e5;

LL read(){
	LL x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

LL power(LL a,LL k){
	LL t=1;
	while(k){
		if(k&1)t=t*a%mod;
		k>>=1;
		a=a*a%mod;
	}
	return t;
}

PLL q[maxn+10];

int main(){
	LL n=read(),m=read(),k=read();
	LL ans=1,sum=n*(n+1)/2%mod,t=1;
	for(int i=1;i<=k;i++)q[i].X=read(),q[i].Y=read();
	sort(q+1,q+k+1);
	for(int i=1;i<=k;i++){
		if(q[i].X!=q[i-1].X)ans=ans*t%mod,t=sum+mod-q[i].Y,m--;
		else if(q[i].Y!=q[i-1].Y)t=t+mod-q[i].Y;
	}
	ans=ans*t%mod*power(sum,m)%mod;
	printf("%lld\n",ans);
	return 0;
}
