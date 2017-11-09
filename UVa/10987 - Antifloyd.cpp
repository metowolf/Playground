#include<bits/stdc++.h>
using namespace std;

const int maxn=100;

int n;
int A[maxn+10][maxn+10];
bool B[maxn+10][maxn+10];

void solve(){
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)B[i][j]=1;
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(A[i][k]+A[k][j]<A[i][j]){
					printf("Need better measurements.\n");
					return;
				}
				if(i==j||j==k||i==k)continue;
				if(A[i][k]+A[k][j]==A[i][j])B[i][j]=0;
			}
	int cnt=0;
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)cnt+=B[i][j];
	printf("%d\n",cnt);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)if(B[i][j])
			printf("%d %d %d\n",i,j,A[i][j]);
}

int main(){
	int T,_=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			for(int j=1;j<i;j++)scanf("%d",&A[i][j]),A[j][i]=A[i][j];
			A[i][i]=0;
		}
		printf("Case #%d:\n",++_);
		solve();
		printf("\n");
	}
	return 0;
}
