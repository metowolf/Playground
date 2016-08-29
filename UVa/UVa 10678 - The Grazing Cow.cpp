#include<bits/stdc++.h>
using namespace std;

double a,b,c;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%lf%lf",&c,&a);
		a/=2,c/=2;
		b=sqrt(a*a-c*c);
		printf("%.3f\n",acos(-1.0)*a*b);
	}
	return 0;
}
