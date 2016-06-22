#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define sf scanf
#define pf printf
#define mk make_pair
using namespace std;

typedef pair<double,double> PII;

vector<pair<PII,int> >V;

PII vec(PII a,PII b){return mk(b.first-a.first,b.second-a.second);}
double cross(PII a,PII b){return a.first*b.second-a.second*b.first;}

int main(){
	int n;
	sf("%d",&n);
	REP(i,1,n){
		double a,b;
		sf("%lf%lf",&a,&b);
		V.push_back(mk(mk(a,b),i));
	}
	sort(V.begin(),V.end());
	FOR(i,2,n){
		if(cross(vec(V[i-1].first,V[i-2].first),vec(V[i-1].first,V[i].first))!=0){
			pf("%d %d %d\n",V[i-2].second,V[i-1].second,V[i].second);
			break;
		}
	}
	return 0;
}
