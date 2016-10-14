#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;

int ans[maxn+2];

bool vis[maxn+2];
int P[maxn+2],cnt=0;

void init(){
	for(int i=5;i*i<=maxn;i+=4)if(!vis[i]){
		P[++cnt]=i;
		for(int j=i*i;j<=maxn;j+=i)vis[j]=1;
	}
	for(int i=5;i<=maxn;i+=4){
		for(int j=1;j<=cnt&&P[j]*P[j]<=i;j++)if(i%P[j]==0){
			if(!vis[i/P[j]])ans[i]=1;
		}
	}
	for(int i=5;i<=maxn;i+=4)ans[i]+=ans[i-4];
}


int main(){
	init();
	int n;
	while(~scanf("%d",&n),n){
		printf("%d %d\n",n,ans[n]);
	}
	return 0;
}
