#include<iostream>
#include<cstdio>
using namespace std;
typedef long long LL;

LL gcd(LL a,LL b){return b?gcd(b,a%b):a;}
LL lcm(LL a,LL b){return a/gcd(a,b)*b;}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		LL A,C;
		scanf("%lld%lld",&A,&C);
		if(C%A)printf("NO SOLUTION\n");
		else{
			LL t=C/A;
			for(LL B=t;B<=C;B+=t)if(lcm(A,B)==C){
				printf("%lld\n",B);
				break;
			}
		}
	}
	return 0;
}
