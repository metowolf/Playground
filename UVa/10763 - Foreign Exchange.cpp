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
typedef pair<int,int> PII;

int n;

int main(){
	while(~sf("%d",&n),n){
		vector<int>A(n),B(n); 
		while(n--){
			int a,b;
			sf("%d%d",&a,&b);
			A.push_back(a);
			B.push_back(b);
		}
		sort(A.begin(),A.end());
		sort(B.begin(),B.end());
		pf(A==B?"YES\n":"NO\n");
	}
	return 0;
}

