#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf scanf
#define pf printf
#define maxn 100000
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;

int n,t;
PII A[maxn+2];
int B[maxn+2];

int main(){
	while(~sf("%d",&n)){
		long long sum=0;
		REP(i,1,n)sf("%d",&t),sum+=t,A[i]=PII(i,t);
		if(sum%2||n==1)pf("No\n");
		else{
			pf("Yes\n");
			REP(i,1,n)B[i]=-1;
			sort(A+1,A+n+1,[](PII a,PII b){return a.second>b.second;});
			sum/=2;
			REP(i,1,n){
				if(A[i].second<=sum){
					sum-=A[i].second;
					B[A[i].first]=1;
				}
			}
			REP(i,1,n)pf("%d%c",B[i],i==n?'\n':' ');
		}
	}	
	return 0;
}
