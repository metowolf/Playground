#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,m,_=0;
	while(~scanf("%d%d",&n,&m),n||m){
		int v=(n-1)/m;
		printf("Case %d: ",++_);
		if(v>26)printf("impossible\n");
		else printf("%d\n",v);
	}
	return 0;
}
