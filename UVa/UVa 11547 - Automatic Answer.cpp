#include<bits/stdc++.h>
using namespace std;
int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		printf("%d\n",(abs((n*567/9+7492)*235/47-498))%100/10);
	}	
	return 0;
}
