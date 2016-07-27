#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	while(~scanf("%d",&n)){
		int cnt=0;
		for(int i=1;i<=5;i++){
			int x;
			scanf("%d",&x);
			cnt+=n==x;
		}
		printf("%d\n",cnt);
	}
	return 0;
}
