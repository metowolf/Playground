#include<bits/stdc++.h>
using namespace std;
int main(){
	int T,_=0;
	scanf("%d",&T);
	while(T--){
		int n,k,p;
		scanf("%d%d%d",&n,&k,&p);
		printf("Case %d: %d\n",++_,(k+p-1)%n+1);
	}
	return 0;
}
