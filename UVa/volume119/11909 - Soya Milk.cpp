#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm> 
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
#define maxn 50
#define EPS (1e-9)
using namespace std;

const double PI=acos(-1.0);
double l,w,h,angle;

int main(){
	//freopen("input.txt","r",stdin);
	while(~sf("%lf%lf%lf%lf",&l,&w,&h,&angle)){
		double h1=tan(angle/180*PI)*l;
		if(h1<=h)pf("%.3f mL\n",w*(l*h-l*h1/2)+EPS);
		else pf("%.3f mL\n",w*(tan((90-angle)/180*PI)*h*h/2)+EPS);
	}
	return 0;
}
