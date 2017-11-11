#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#define sf scanf
#define pf printf
using namespace std;

const int MAXN=500+2;

int T,n,m,parent[MAXN],top,cnt;
double x[MAXN],y[MAXN],ans;

struct edge{
	int a,b;
	double c;
}V[MAXN*MAXN];

int Find(int x){return parent[x]==x?x:parent[x]=Find(parent[x]);}

double dis(double a,double b){return sqrt(a*a+b*b);}

bool cmp(edge a,edge b){return a.c<b.c;}

int main(){
	sf("%d",&T);
	while(T--){
		sf("%d%d",&m,&n);
		FOR(i,0,n)parent[i]=i;
		FOR(i,0,n)sf("%lf%lf",&x[i],&y[i]);
		top=0;
		FOR(i,0,n)FOR(j,i+1,n){
			V[top].a=i;
			V[top].b=j;
			V[top++].c=dis(x[i]-x[j],y[i]-y[j]);
		}
		sort(V,V+top,cmp);
		cnt=0;
		FOR(i,0,top){
			int fa=Find(V[i].a),fb=Find(V[i].b);
			if(fa!=fb){
				parent[fa]=fb;
				cnt++;
				if(cnt==n-m){
					ans=V[i].c;
					break;
				}
			}
		}
		pf("%.2lf\n",ans);
	}
	return 0;
}
