#include<bits/stdc++.h>
#define maxn 32768
using namespace std;

bool P[maxn+2];

void genprime(){
	P[0]=P[1]=1;
	for(int i=2;i*i<=maxn;i++)if(!P[i])
		for(int j=i*i;j<=maxn;j+=i)P[j]=1;
}

int main(){
	genprime();

	int n;
	while(~scanf("%d",&n),n){
		int ans=0;
		for(int i=1;i*2<=n;i++)ans+=(!P[i]&&!P[n-i]);
		printf("%d\n",ans);
	}
	return 0;
}
