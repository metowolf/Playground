#include<iostream>
#include<cstdio>
#include<cstring>
#define maxn 1000000
using namespace std;

int sieve[maxn+2];
int prime[maxn+2];
int cnt;

void gensieve(){
	cnt=1;
	for(int i=2;i<=maxn;i++){
		if(!sieve[i])prime[cnt]=i,sieve[i]=cnt++;
		for(int j=1;j<=sieve[i]&&i*prime[j]<=maxn;j++)sieve[i*prime[j]]=j;
	}
	cnt--;
}

int main(){
	gensieve();
	int n;
	while(~scanf("%d",&n),n){
		int ans=0,t=n;
		for(int i=1;i<=cnt&&prime[i]<=t;i++){
			if(t%prime[i]==0){
				ans++;
				while(t%prime[i]==0)t/=prime[i];
			}
		}
		printf("%d : %d\n",n,ans);
	}
	return 0;
}
