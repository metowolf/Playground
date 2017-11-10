#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

int main(){
	LL n,a=1,b=1,cnt=2;
	scanf("%lld",&n);
	n-=2;
	while(n>=a+b){
		n-=a+b;
		a+=b;
		swap(a,b);
		cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}
	
