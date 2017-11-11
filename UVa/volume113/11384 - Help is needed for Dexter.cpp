#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define CLR(c,x) memset(c,x,sizeof(c))
#define ESP 1e-8
#define sf scanf
#define pf printf
#define INF ~0U>>1
using namespace std;

long long n;

void solve(){
	int t=0;
	while(n){
		t++;
		n>>=1;
	}
	pf("%d\n",t);
}

int main(){
	while(~sf("%lld",&n))solve();
	return 0;
}
