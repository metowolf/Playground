#include<bits/stdc++.h>
using namespace std;

const int maxn=10;

char A[maxn+10][maxn+10];
int num[maxn+10][maxn+10];

int main(){
	
	freopen("input.txt","r",stdin);

	int n,m,_=0;
	while(~scanf("%d%d",&n,&m),n){
		int cnt=0;
		for(int i=1;i<=n;i++)scanf("%s",A[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++){
				if(A[i][j]!='*'&&(i==1||j==1||A[i-1][j]=='*'||A[i][j-1]=='*'))num[i][j]=++cnt;
				else num[i][j]=0;
			}

		if(_)puts("");
		printf("puzzle #%d:\n",++_);		
		printf("Across\n");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(A[i][j]!='*'){
					printf("%3d.",num[i][j]);
					while(A[i][j]!='*'&&j<=m){
						putchar(A[i][j++]);
					}
					putchar('\n');
				}
			}
		}
		printf("Down\n");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(A[i][j]!='*'&&(i==1||A[i-1][j]=='*')){
					int ti=i;
					printf("%3d.",num[ti][j]);
					while(A[ti][j]!='*'&&ti<=n){
						putchar(A[ti++][j]);
					}
					putchar('\n');
				}
			}
		}
	}
	return 0;
}

