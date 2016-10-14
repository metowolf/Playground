#include<bits/stdc++.h>
using namespace std;

int n;
int w[1<<16];
int sum[1<<16];

int main(){
	int n;
	while(~scanf("%d",&n)){
		int cnt=1<<n;
		for(int i=0;i<cnt;i++)scanf("%d",w+i);
		for(int i=0;i<cnt;i++){
			sum[i]=0;
			for(int j=0;j<n;j++)sum[i]+=w[i^(1<<j)];
		}
		int ans=0;
		for(int i=1;i<cnt;i++)
			for(int j=0;j<n;j++)ans=max(ans,sum[i]+sum[i^(1<<j)]);
		printf("%d\n",ans);
	}
	return 0;
}
