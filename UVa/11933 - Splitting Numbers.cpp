#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(~scanf("%d",&n),n){
		int a=0,b=0;
		int flag=0;
		for(long long i=1;i<=n;i<<=1)if(n&i){
			if(flag)b|=i;else a|=i;
			flag^=1;
		}
		printf("%d %d\n",a,b);
	}
	return 0;
}
