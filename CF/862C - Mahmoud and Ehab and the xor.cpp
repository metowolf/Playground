#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,x;
	scanf("%d%d",&n,&x);
	if(n==1)printf("YES\n%d\n",x);
	else if(n==2&&x==0)printf("NO\n");
	else if(n==2&&x!=0)printf("YES\n0 %d\n",x);
	else{
		int t=0;
		for(int i=1;i<=n-3;i++)t^=i;
		printf("YES\n");
		for(int i=1;i<=n-3;i++)printf("%d ",i);
		printf("%d %d %d\n",t^x^(1<<18),1<<19,(1<<18)^(1<<19));
	}
	return 0;
}
