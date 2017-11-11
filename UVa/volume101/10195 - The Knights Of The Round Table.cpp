#include<bits/stdc++.h>
using namespace std;

double area(double a,double b,double c){
	double p=(a+b+c)/2;
	return sqrt(p*(p-a)*(p-b)*(p-c));
}

int main(){
	double a,b,c,ans;
	while(~scanf("%lf%lf%lf",&a,&b,&c)){
		if(a+b+c)ans=area(a,b,c)*2/(a+b+c);
		else ans=0;
		printf("The radius of the round table is: %.3f\n",ans);
	}
	return 0;
}
