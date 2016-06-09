#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define ECH(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i) 
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn 3
using namespace std;

int n;
int A[maxn*maxn+2][maxn*maxn+2];
bool row[maxn*maxn+2][maxn*maxn+2],col[maxn*maxn+2][maxn*maxn+2];
bool lar[maxn+2][maxn+2][maxn*maxn+2];

void debug(){
	FOR(i,0,n*n)FOR(j,0,n*n)pf("%d%c",A[i][j],j+1==n*n?'\n':' ');
}

bool DFS(int id){
	int x=id/(n*n),y=id-x*n*n;
	if(id==n*n*n*n)return 1;
	if(A[x][y]){return DFS(id+1);}
	else{
		REP(i,1,n*n)if(!row[x][i]&&!col[y][i]&&!lar[x/n][y/n][i]){
			A[x][y]=i;
			row[x][i]=col[y][i]=lar[x/n][y/n][i]=1;
			if(DFS(id+1))return 1;
			row[x][i]=col[y][i]=lar[x/n][y/n][i]=0;
			A[x][y]=0;
		}
	}
	return 0;
}

int main(){
	int _=0;
	while(~sf("%d",&n)){
		CLR(A,0),CLR(row,0),CLR(col,0),CLR(lar,0);
		FOR(i,0,n*n)FOR(j,0,n*n){
			sf("%d",&A[i][j]);
			if(A[i][j]){
				row[i][A[i][j]]=1;
				col[j][A[i][j]]=1;
				lar[i/n][j/n][A[i][j]]=1;
			}
		}
		bool ans=DFS(0);
		if(_++)pf("\n");
		if(ans)debug();
		else pf("NO SOLUTION\n");
	}
	return 0;
}
