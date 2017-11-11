#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <cstdlib>
#include   <cstdio>
#include   <vector>
#include    <cmath>
#include    <queue>
#include      <map>
#include      <set>
#define RPE(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#define sf   scanf
#define pf   printf
#define inf  (~0U>>2)
#define eps  (1e-8)
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
#define maxn 10000
using namespace std;

const double PI=acos(-1.0);

double area(double a,double b,double c){
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main(){
	double a,b,c;
	while(~sf("%lf%lf%lf",&a,&b,&c)){
		double angle=acos((a*a+b*b-c*c)/(2*a*b));
		double R=c/sin(angle)/2;
		double mid=area(a,b,c);
		double r=mid*2/(a+b+c);
		pf("%.4f %.4f %.4f\n",PI*R*R-mid+eps,mid-PI*r*r+eps,PI*r*r+eps);
	}
	return 0;
}

