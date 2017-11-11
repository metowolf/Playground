#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,_=0;
	scanf("%d",&T);
	while(T--){
		int n;double ans=0;
		scanf("%d",&n);
		n-=180000;
		if(n>0)ans+=min(n,300000)*0.1;
		n-=300000;
		if(n>0)ans+=min(n,400000)*0.15;
		n-=400000;
		if(n>0)ans+=min(n,300000)*0.2;
		n-=300000;
		if(n>0)ans+=n*0.25;
		if(ans>0&&ans<2000)ans=2000;
		printf("Case %d: %d\n",++_,(int)(ans+0.99));
	}
	return 0;
}
