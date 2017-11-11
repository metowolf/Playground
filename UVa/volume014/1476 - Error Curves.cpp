#include<bits/stdc++.h>
#define maxn 10000
using namespace std;

int n;
int a[maxn+2],b[maxn+2],c[maxn+2];

double f(double x){
	double ans=a[0]*x*x+b[0]*x+c[0];
	for(int i=1;i!=n;++i)
		ans=max(ans,a[i]*x*x+b[i]*x+c[i]);
	return ans;
}

inline int _int(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
	while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
	return x*f;
}

int main(){
	int T;
	T=_int();
	while(T--){
		n=_int();
		for(int i=0;i!=n;++i)a[i]=_int(),b[i]=_int(),c[i]=_int();
		double L=0,R=1000;
		while(L+1e-10<R){
			double x1=L+(R-L)/2.002,x2=L+R-x1;
			if(f(x1)<f(x2))R=x2;
			else L=x1;
		}
		printf("%.4f\n",f(L));
	}
	return 0;
}
