#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define maxn 100
using namespace std;

char A[maxn+2][maxn+2];
int dx[]={1,0,-1,0,1,-1,-1,1},dy[]={0,1,0,-1,1,1,-1,-1};

int main(){
	int n,m,_=0;
	while(~scanf("%d%d",&n,&m),n||m){
		if(_)putchar('\n');
		memset(A,0,sizeof(A));
		REP(i,1,n)REP(j,1,m)scanf(" %c",&A[i][j]);
		printf("Field #%d:\n",++_);
		REP(i,1,n){
			REP(j,1,m){
				if(A[i][j]=='*')putchar('*');
				else{
					int cnt=0;
					for(int k=0;k<8;k++)cnt+=A[i+dx[k]][j+dy[k]]=='*';
					putchar('0'+cnt);
				}
			}
			putchar('\n');
		}
	}
	return 0;
}
