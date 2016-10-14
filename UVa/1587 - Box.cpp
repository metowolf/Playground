#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#define sf scanf
#define pf printf
#define maxn 
using namespace std;
typedef pair<int,int> PII;

vector<PII>V;

bool judge(){
	for(int i=0;i<6;i+=2){
		if(V[i].first!=V[i+1].first||V[i].second!=V[i+1].second)return 0;
	}
	if(V[0].first!=V[2].first||V[0].second!=V[4].first||V[2].second!=V[4].second)return 0;
	return 1;
}

bool cmp(const PII a,const PII b){
	return a.first==b.first?a.second>b.second:a.first>b.first;
}

int main(){
	int a,b;
	while(~sf("%d%d",&a,&b)){
		V.clear();
		if(a<b)swap(a,b);
		V.push_back(PII(a,b));
		REP(i,1,5){
			sf("%d%d",&a,&b);
			if(a<b)swap(a,b);
			V.push_back(PII(a,b));
		}
		sort(V.begin(),V.end(),cmp);
		pf(judge()?"POSSIBLE\n":"IMPOSSIBLE\n");
	}
	return 0;
}
