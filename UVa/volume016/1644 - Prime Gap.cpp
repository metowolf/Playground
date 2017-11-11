#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
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
vector<int>V;

bool P[1299709+2];
void init(){
	for(int i=2;i<=1299709;i++)if(!P[i]){
		V.push_back(i);
		for(int j=i+i;j<=1299709;j+=i)P[j]=1;
	}
}

int main(){
	init();
	while(~sf("%d",&n),n){
		int L=*--lower_bound(V.begin(),V.end(),n);
		int R=*upper_bound(V.begin(),V.end(),n);
		pf("%d\n",P[n]?R-L:0); 
	}
	return 0;
}
