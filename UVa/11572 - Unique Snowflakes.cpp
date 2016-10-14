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
#define maxn 1000000
using namespace std;

struct Hash{
	static const int mask=0x7fffff;
	int p[mask+1],q[mask+1];
	void clear(){CLR(q,0);}
	int& operator [](int k){
		int i;
		for(i=k&mask;q[i]&&p[i]!=k;i=(i+1)&mask);
		p[i]=k;
		return q[i];
	}
}Hash;

int n;
int A[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	int T;
	sf("%d",&T);
	while(T--){
		int ans=0;
		Hash.clear();
		sf("%d",&n);
		REP(i,1,n)sf("%d",A+i);
		int L=1,R=1;
		while(R<=n){
			while(R<=n&&!Hash[A[R]])Hash[A[R++]]=1;
			ans=max(ans,R-L);
			Hash[A[L++]]=0;
		}
		pf("%d\n",ans);
	}
	return 0;
}
