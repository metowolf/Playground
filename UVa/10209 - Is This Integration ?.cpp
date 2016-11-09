#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;

const double Pi=acos(-1.0);

int main(){
	double a,x,y,z;
	while(~scanf("%lf",&a)){
		z=a*a*(1-Pi/6-sqrt(3)/4);
		y=a*a*(1-Pi/4)-2*z;
		x=a*a-4*(y+z);
		printf("%.3lf %.3lf %.3lf\n",x,4*y,4*z);
	}
	return 0;
}

