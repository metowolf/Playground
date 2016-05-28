#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define ECH(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i) 
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn 4000000
using namespace std;
typedef long long LL;

int n;
int phi[maxn+2];
LL f[maxn+2],s[maxn+2];

void phi_table(int n){
	phi[1]=1;
	REP(i,2,n)if(!phi[i]){
		for(int j=i;j<=n;j+=i){
			if(!phi[j])phi[j]=j;
			phi[j]=phi[j]/i*(i-1);
		}
	}
}

int main(){
	//freopen("input.txt","r",stdin);
	CLR(phi,0);phi_table(maxn);
	CLR(f,0);REP(i,1,maxn)for(int j=2*i;j<=maxn;j+=i)f[j]+=i*phi[j/i];
	CLR(s,0);REP(i,2,maxn)s[i]=s[i-1]+f[i];
	while(~sf("%d",&n),n)pf("%lld\n",s[n]);
	return 0;
}
