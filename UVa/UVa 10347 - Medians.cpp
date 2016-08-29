#include<bits/stdc++.h>
using namespace std;
int main(){
	double a,b,c;
	while(~scanf("%lf%lf%lf",&a,&b,&c)){
		double s=(a+b+c)/2;
		if(a>0&&b>0&&c>0&&a+b>c&&a+c>b&&b+c>a)
			printf("%.3f\n",4./3*sqrt(s*(s-a)*(s-b)*(s-c)));
		else
			printf("-1.000\n");
	}
	return 0;
}
