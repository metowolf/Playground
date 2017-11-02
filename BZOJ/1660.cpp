#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=8e4;

LL A[maxn+10],ans=0;
stack<int>S;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%lld",A+i);
	for(int i=n;i>=1;i--){
		while(!S.empty()&&A[S.top()]<A[i])S.pop();
		if(!S.empty())ans+=S.top()-i;
		else ans+=n+1-i;
		S.push(i);
	}
	printf("%lld\n",ans-n);
	return 0;
}
