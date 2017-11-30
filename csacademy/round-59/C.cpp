#include<bits/stdc++.h>
using namespace std;

int n;
int A[2][3000+10];
char s[3000+10];
char ts[3000+10][3000+10];

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%s",ts[i]+1);
	A[1][1]=1;
	for(int i=1;i<=n;i++){
		char t='z'+1;
		for(int j=1;j<=i;j++)if(A[i%2][j])
			t=min(t,min(ts[i+1][j],ts[i+1][j+1])),s[i]=ts[i][j];
		for(int j=1;j<=i+1;j++)A[(i+1)%2][j]=0;
		for(int j=1;j<=i;j++)if(A[i%2][j]){
			if(ts[i+1][j]==t)A[(i+1)%2][j]=1;
			if(ts[i+1][j+1]==t)A[(i+1)%2][j+1]=1;
		}
		/*for(int j=1;j<=i;j++)printf("%d",A[i&1][j]);
		printf("\n");*/
	}
	for(int i=1;i<=n;i++)putchar(s[i]);
	return 0;
}
