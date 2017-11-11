#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef long long LL;

priority_queue<LL,vector<LL>,greater<LL> >Q;

int main(){
	int n;
	while(~scanf("%d",&n),n){
		while(!Q.empty())Q.pop();
		for(int i=1;i<=n;i++){
			LL x;
			scanf("%lld",&x);
			Q.push(x);
		}
		LL ans=0;
		for(int i=1;i<n;i++){
			LL x=Q.top();Q.pop();
			LL y=Q.top();Q.pop();
			ans+=x+y;
			Q.push(x+y);
		}
		printf("%lld\n",ans);
	}
	return 0;
}

