#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define maxn 100
using namespace std;

int n,ans;
int A[maxn+2];

int gcd(int a,int b){return b?gcd(b,a%b):a;}

int main(){
	int T;
	scanf("%d\n",&T);
	while(T--){
		char c;
		n=ans=0;
		while(1){
			scanf("%d",&A[++n]);
			while((c=getchar())==' ');
			ungetc(c,stdin);
			if(c==10||c==-1)break;
		}
		REP(i,1,n)REP(j,i+1,n)ans=max(ans,gcd(A[i],A[j]));
		printf("%d\n",ans);
	}
	return 0;
}
