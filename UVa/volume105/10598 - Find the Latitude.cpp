#include<bits/stdc++.h>
using namespace std;

const double PI=acos(-1.0);
double R,n;

int main(){
	int _=0;
	while(~scanf("%lf%lf",&R,&n),R||n){
		printf("Case %d:\n",++_);
		for(int i=1;i<=10;i++){
			double r=n/2/PI/i;
			double ans=90-360*asin(r/R)/2/PI;
			ans-=360*n/2/PI/R;
			printf("%.5f\n",ans);
		}
	}
	return 0;
}
