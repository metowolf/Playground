#include<bits/stdc++.h>
using namespace std;

double length(double x,double y){
	return sqrt(x*x+y*y);
}

int main(){
	double L,C,r1,r2;
	while(scanf("%lf%lf%lf%lf",&L,&C,&r1,&r2)){
		if(!(L||C||r1||r2))break;
		if(L<C)swap(L,C);
		if(r1<r2)swap(r1,r2);
		double a=length(L-r1-r2,C-r1-r2);
		double b=r1+r2;
		printf(a>=b&&r1*2<=C?"S\n":"N\n");
	}
	return 0;
}
