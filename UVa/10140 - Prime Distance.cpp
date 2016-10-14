#include<bits/stdc++.h>
#define maxn 100000
using namespace std;
typedef long long LL;

bool vis[maxn*10+2];
LL P[maxn+2],cnt=0;

void initial(){
	for(LL i=2;i<=maxn;i++)if(!vis[i]){
		P[++cnt]=i;
		for(LL j=i*i;j<=maxn;j+=i)vis[j]=1;
	}
}

int main(){
	initial();
	LL L,R;
	while(~scanf("%lld%lld",&L,&R)){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=cnt;i++){
			for(LL j=(L/P[i]+(L%P[i]!=0))*P[i];j<=R;j+=P[i])if(j!=P[i])vis[j-L]=1;
		}
		bool flag=0;
		LL pre=-1,maxx=-1,minx=~0U>>2;
		LL maxl,maxr,minl,minr;
		for(LL i=max(2LL,L);i<=R;i++)if(!vis[i-L]){
			if(pre==-1){pre=i;continue;}
			if(i-pre>maxx)maxx=i-pre,maxl=pre,maxr=i;
			if(i-pre<minx)minx=i-pre,minl=pre,minr=i;
			flag=1,pre=i;
		}
		if(!flag)printf("There are no adjacent primes.\n");
		else printf("%lld,%lld are closest, %lld,%lld are most distant.\n",minl,minr,maxl,maxr);
	}
	return 0;
}
