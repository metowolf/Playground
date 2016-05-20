#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm> 
#include<unordered_map>
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
#define maxn 4000
using namespace std;

int n;
unordered_map<int,int>Hash;
int A[maxn+2],B[maxn+2],C[maxn+2],D[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	int T;
	sf("%d",&T);
	while(T--){
		sf("%d",&n);
		REP(i,1,n)sf("%d%d%d%d",A+i,B+i,C+i,D+i);
		Hash.clear();
		REP(i,1,n)REP(j,1,n){
			if(!Hash.count(A[i]+B[j]))Hash[A[i]+B[j]]=1;
			else ++Hash[A[i]+B[j]];
		}
		int cnt=0;
		REP(i,1,n)REP(j,1,n)if(Hash.count(-C[i]-D[j]))cnt+=Hash[-C[i]-D[j]];
		pf("%d\n",cnt);
		if(T)pf("\n");
	}
	return 0;
}
