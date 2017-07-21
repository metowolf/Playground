#include<bits/stdc++.h>
using namespace std;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		double ans=1;
		for(int i=4;i<=n;i+=2)
			ans*=(i-3)*1./(i-2);
		printf("%.4f\n",1-ans);
	}
	return 0;
}
