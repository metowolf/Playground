#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#define sf scanf
#define pf printf
#define INF (1e9)
#define eps 1e-8
using namespace std;

const int maxn=101;

int n,cas=0;
int x[maxn+2],y[maxn+2];
double F[maxn+2][maxn+2];

double dis(int a,int b){return sqrt(a*a+b*b);}

void solve(){
	sf("%d",&n);
	REP(i,1,n)sf("%d%d",x+i,y+i);
	REP(i,1,n)REP(j,i+1,n){
		double ans=dis(x[i]-x[j],y[i]-y[j]);
		F[i][j]=F[j][i]=(ans-10.0>eps)?INF:ans;
	}
	REP(k,1,n)REP(i,1,n)REP(j,1,n)F[i][j]=min(F[i][j],F[i][k]+F[k][j]);
	double ans=0;
	REP(i,1,n)REP(j,i+1,n)if(F[i][j]>ans)ans=F[i][j];
	
	pf("Case #%d:\n",++cas);
	pf((fabs(ans-INF)<eps)?"Send Kurdy\n":"%.4lf\n",ans);
	pf("\n");
}

int main(){
	int T;
	sf("%d",&T);
	while(T--)solve();
	return 0;
}
