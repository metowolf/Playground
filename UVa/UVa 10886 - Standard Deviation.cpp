#include<bits/stdc++.h>
using namespace std;

int n;
unsigned long long seed;

long double gen(){
	static const long double Z=(long double)1.0/(1LL<<32);
	seed>>=16;
	seed&=(1ULL<<32)-1;
	seed*=seed;
	return seed*Z;
}

int main(){
	int T,_=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%llu",&n,&seed);
		long double sum=0,sum2=0;
		for(int i=1;i<=n;i++){
			long double x=gen();
			sum+=x;
			sum2+=x*x;
		}
		printf("Case #%d: %.5Lf\n",++_,sqrt((sum2-2*sum/n*sum)/n+sum/n*sum/n));
	}
	return 0;
}

