#include<bits/stdc++.h>
using namespace std;
int main(){
	int ans;
	while(~scanf("%d",&ans)){
		int t,cnt=0;
		for(int i=1;i<=5;i++)scanf("%d",&t),cnt+=t==ans;
		printf("%d\n",cnt);
	}
	return 0;
}
