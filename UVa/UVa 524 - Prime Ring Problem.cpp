#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define maxn 16
using namespace std;

int n;
bool P[50+2];
int A[maxn+2];
bool vis[maxn+2];


void Initial(){
	for(int i=2;i*i<=50;i++)if(!P[i])
		for(int j=i*i;j<=50;j+=i)P[j]=1;
}

void DFS(int deep){
	if(deep==n+1){
		if(!P[A[n]+A[1]]){
			printf("1");
			REP(i,2,n)printf(" %d",A[i]);
			printf("\n");
		}
		return;
	}
	REP(i,1,n)if(!vis[i]&&!P[A[deep-1]+i]){
		vis[i]=1;
		A[deep]=i;
		DFS(deep+1);
		vis[i]=0;
	}
}

int main(){
	Initial();
	int _=0;
	while(~scanf("%d",&n)){
		if(_)puts("");
		printf("Case %d:\n",++_);
		REP(i,1,n)vis[i]=0;
		A[1]=1;vis[1]=1;
		if(n>1)DFS(2);
	}
	return 0;
}
