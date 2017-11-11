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
#define maxn 3000
using namespace std;

bool vis[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	int n,L,R,t;
	while(~sf("%d",&n)){
		bool flag=1;
		REP(i,1,n-1)vis[i]=0;
		if(n)sf("%d",&L);
		REP(i,2,n){
			sf("%d",&R);
			t=abs(R-L);
			L=R;
			if(t<1||t>=n||vis[t])flag=0;
			vis[t]=1;
		}
		pf(flag?"Jolly\n":"Not jolly\n");
	}
	return 0;
}
