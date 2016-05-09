#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#define sf scanf
#define pf printf
#define maxn 200
#define eps 1e-8
using namespace std;

int n;
double X[maxn+2],Y[maxn+2];
double d[maxn+2][maxn+2];

double dis(double a,double b){return sqrt(a*a+b*b);}

int main(){
	int kase=1;
	while(~sf("%d",&n),n){
		REP(i,1,n)sf("%lf%lf",X+i,Y+i);
		REP(i,1,n)REP(j,i,n)d[i][j]=d[j][i]=dis(X[i]-X[j],Y[i]-Y[j]);
		REP(k,1,n)REP(i,1,n)REP(j,1,n)d[i][j]=min(d[i][j],max(d[i][k],d[k][j]));
		pf("Scenario #%d\n",kase++);
		pf("Frog Distance = %.3lf\n\n",d[1][2]);
	}
	return 0;
}
