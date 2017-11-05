#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;
typedef long long LL;

const int maxn=200;
const LL mod=1e9+7;

LL n,m,p,q;
LL C[maxn+10][maxn+10];
LL sum[maxn+10][maxn+10];
LL Fac[maxn*2+10],Odd[maxn*2+10];

void init(){
	REP(i,0,maxn)C[i][0]=C[i][i]=sum[i][0]=1;
	REP(i,1,maxn)FOR(j,1,i){
		C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	REP(i,0,maxn)REP(j,1,maxn)
		sum[i][j]=(sum[i][j-1]+C[i][j])%mod;
	Fac[0]=Odd[1]=1;
	REP(i,1,2*maxn){
		Fac[i]=Fac[i-1]*i%mod;	
		if(i>1&&(i&1))Odd[i]=Odd[i-2]*i%mod;
	}
}

void solve(){
	LL ans=0,t,res=1;
	REP(i,0,n)REP(j,0,m){
		if(i+2*j>n||(j+2*i)>m||2*(i+j)>p)break;
		res=1;
		t=(2*i>1)?Odd[2*i-1]:1;
		res=(((((C[n][i]*C[m][2*i])%mod)*t)%mod)*Fac[i])%mod;
		t=(2*j>1)?Odd[2*j-1]:1;
		res=((((res*C[m-2*i][j])%mod*C[n-i][2*j])%mod*t)%mod*Fac[j])%mod;

		LL tp=p-2*(i+j),tq=q,tn=n-(i+2*j),tm=m-(j+2*i);
		for(LL k=0;k<=tp+tq;k++){
			if(k>tn||k>tm)break;
			LL minp=max(0LL,k-tq),maxp=min(k,tp);
			t=minp?sum[k][minp-1]:0;
			LL tmp=(
					(((C[tn][k]*C[tm][k])%mod*Fac[k])%mod)
					*(sum[k][maxp]-t)
				   )%mod;
			ans=(ans+tmp*res)%mod;
		}
	}
	ans--;
	printf("%lld\n",(ans%mod+mod)%mod);
}

int main(){
	init();

	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lld%lld%lld%lld",&n,&m,&p,&q);
		solve();
	}
	return 0;
}
