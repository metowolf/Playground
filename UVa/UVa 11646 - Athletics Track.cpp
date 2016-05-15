#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define ECH(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i) 
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
//#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn 50
#define eps 1e-12
using namespace std;

double f(double L,double W){
	double len=sqrt(L*L+W*W)/2;
	double angle=acos((len*len*2-W*W)/(2*len*len));
	double ans=len*angle*2;
	ans+=(L+L);
	return ans;
}	

int main(){
	int _=0;
	double a,b;
	while(~sf("%lf : %lf",&a,&b)){
		double L=eps,R=400;
		while(L+eps<R){
			double mid=(L+R)/2;
			if(f(mid*a,mid*b)<400)L=mid;
			else R=mid;
		}
		pf("Case %d: %.10f %.10f\n",++_,a*L,b*L);
	}
	return 0;
}
