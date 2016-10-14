#include<bits/stdc++.h>
#define eps 1e-9
using namespace std;

int p,q,r,s,t,u;

inline double f(double x){
	return p*powl(1/2.7182818284,x)+q*sinl(x)+r*cosl(x)+s*tanl(x)+t*x*x+u;
}

int main(){

	//freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);

	while(~scanf("%d%d%d%d%d%d",&p,&q,&r,&s,&t,&u)){
		double L=0,R=1;
		if(f(L)*f(R)>0){
			printf("No solution\n");
			continue;
		}
		while(L+eps<R){
			double mid=(L+R)/2;
			if(f(mid)>0)L=mid;
			else R=mid;
		}
		printf("%.4f\n",L);
	}
	return 0;
}
