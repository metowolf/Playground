#include<bits/stdc++.h>
using namespace std;

const int maxn=100;

int A[maxn+10][maxn+10];

int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=n;i>=1;i--)
		for(int j=1;j<=m;j++)
			scanf("%d",&A[i][j]);
	for(int i=0;i<=max(n,m);i++)A[i][0]=A[i][0]=-1;

	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			A[i][j]+=max(A[i-1][j],A[i][j-1]);
	
	stack<int>ST;
	int x=n,y=m;
	while(x!=1||y!=1){
		if(x>1&&y>1){
			if(A[x-1][y]>A[x][y-1])ST.push(0),x--;
			else ST.push(1),y--;
		}
		else if(x==1)ST.push(1),y--;
		else ST.push(0),x--;
	}
	
	while(!ST.empty()){
		putchar(ST.top()?'R':'F');
		ST.pop();
	}

	return 0;
}
