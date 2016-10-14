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
using namespace std;

const double eps=1e-8;

inline int dcmp(double x){return x>eps?1:x<-eps?-1:0;}

int main(){
	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
	
	for(int a=1;4*a<=2000;a++)
		for(int b=a;a+3*b<=2000;b++)
			for(int c=b;a+b+2*c<=2000;c++){
				long long p=(a*b*c);
				long long s=(a+b+c);
				if(p<=1000000)continue;
				long long d=(1000000*s)/(p-1000000);
				if(d<c||s+d>2000)continue;
				if(fabs((a+b+c+d)/100.0-(a*b*c*d)/100000000.0)<eps)
					pf("%0.2f %0.2f %0.2f %0.2f\n",a/100.0,b/100.0,c/100.0,d/100.0);
			}
	return 0;
}
