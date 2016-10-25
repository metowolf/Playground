#include<iostream>
#include<cstdio>
#define maxn 1000000
using namespace std;

bool P[maxn+2];

void initial(){
	P[0]=P[1]=1;
	for(int i=2;i*i<=maxn;i++)if(!P[i])
		for(int j=i*i;j<=maxn;j+=i)P[j]=1;
}

int main(){
	initial();
	
	int n;
	while(~scanf("%d",&n),n){
		for(int i=1;i<=n;i++)if(!P[i]&&!P[n-i]){
			printf("%d = %d + %d\n",n,i,n-i);
			break;
		}
	}
	return 0;
}

