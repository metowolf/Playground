#include<bits/stdc++.h>
using namespace std;

const int maxn=1000000;
int n,f[maxn+10];

void init(){
	memset(f,0,sizeof(f));
	for(int i=1;i<=n;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		f[a]++,f[b+1]--;
	}
}
void solve(){
	int sum=0,ans=0;
	for(int i=1;i<=maxn;i++){
		sum+=f[i];
		ans=max(ans,sum);
	}
	printf("%d\n",ans);
}
int main(){
	while(~scanf("%d",&n)){
		init();
		solve();
	}
	return 0;
}
