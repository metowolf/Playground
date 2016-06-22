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
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf   scanf
#define pf   printf
#define inf  (~0U>>2)
#define eps  (1e-8)
#define maxn 50
//#pragma comment(linker,"/STACK:36777216")
using namespace std;

string s[]={"x^y^z","x^z^y","(x^y)^z","(x^z)^y","y^x^z","y^z^x","(y^x)^z","(y^z)^x","z^x^y","z^y^x","(z^x)^y","(z^y)^x"};
int id=0;
long double x,y,z;
long double ans=-1e10;

int main(){
	cin>>x>>y>>z;
	if(powl(y,z)*logl(x)>ans)ans=powl(y,z)*logl(x),id=0;
	if(powl(z,y)*logl(x)>ans)ans=powl(z,y)*logl(x),id=1;
	if(z*y*logl(x)>ans)ans=z*y*logl(x),id=2;
	if(y*z*logl(x)>ans)ans=y*z*logl(x),id=3;
	if(powl(x,z)*logl(y)>ans)ans=powl(x,z)*logl(y),id=4;
	if(powl(z,x)*logl(y)>ans)ans=powl(z,x)*logl(y),id=5;
	if(z*x*logl(y)>ans)ans=z*x*logl(y),id=6;
	if(x*z*logl(y)>ans)ans=x*z*logl(y),id=7;
	if(powl(x,y)*logl(z)>ans)ans=powl(x,y)*logl(z),id=8;
	if(powl(y,x)*logl(z)>ans)ans=powl(y,x)*logl(z),id=9;
	if(y*x*logl(z)>ans)ans=y*x*logl(z),id=10;
	if(x*y*logl(z)>ans)ans=x*y*logl(z),id=11;
	pf("%s",s[id].c_str());
	return 0;
}
