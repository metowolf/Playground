#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf scanf
#define pf printf
#define maxn 300000
#define endl '\n'
using namespace std;

int n;
queue<int>Q;

int main(){
	while(~sf("%d",&n),n){
		while(!Q.empty())Q.pop();
		REP(i,1,n)Q.push(i);
		pf("Discarded cards:");
		bool flag=0;
		while(Q.size()>=2){
			pf(flag?", %d":" %d",Q.front());
			flag=1;
			Q.pop();
			Q.push(Q.front());
			Q.pop();
		}
		pf("\nRemaining card: %d\n",Q.front());
	}
	return 0;
}
