#include<bits/stdc++.h>
#define maxn 1000000
using namespace std;

int n,A[maxn+2];
char s[maxn+2];

int main(){
	int _=0;
	while(~scanf("%s",s+1)){
		n=strlen(s+1);
		A[0]=0;
		for(int i=1;i<=n;i++)A[i]=A[i-1]+(s[i]=='1');
		int m;
		scanf("%d",&m);
		printf("Case %d:\n",++_);
		while(m--){
			int L,R;
			scanf("%d%d",&L,&R);
			if(L>R)swap(L,R);
			if(A[R+1]-A[L]==0||A[R+1]-A[L]==R-L+1)printf("Yes\n");
			else printf("No\n");
		}
	}
	return 0;
}
