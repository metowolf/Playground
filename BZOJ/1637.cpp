#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> PII;

const int maxn=5e4;

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

PII A[maxn+10];
map<int,int>M;

int main(){
	int n=read();
	for(int i=1;i<=n;i++){
		int a=read(),b=read();
		A[i]=PII(b,a);
	}
	sort(A+1,A+n+1);
	int cnt[2]={0};
	int ans=0;
	for(int i=1;i<=n;i++){
		cnt[A[i].Y]++;
		int t=M[cnt[1]-cnt[0]];
		if(t)ans=max(ans,A[i].X-A[t+1].X);
		else M[cnt[1]-cnt[0]]=i;
	}
	printf("%d\n",ans);
	return 0;
}
