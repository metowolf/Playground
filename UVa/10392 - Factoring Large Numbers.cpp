#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;

LL n;

int main(){
	while(~scanf("%lld",&n),~n){
		for(long long i=2;i*i<=n;i++){
			while(n%i==0)printf("    %lld\n",i),n/=i;
		}
		if(n!=1)printf("    %lld\n",n);
		putchar('\n');
	}
	return 0;
}
