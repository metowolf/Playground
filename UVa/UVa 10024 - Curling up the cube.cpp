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
#define maxn 50
using namespace std;

int M[7][7];
int U,D,L,R,F,B;
int cnt;

void DFS(int x,int y){
	D=0,M[x][y]=0;cnt++;
	if(M[x+1][y]&&F==1)F=U,U=B,B=D,DFS(x+1,y),B=U,U=F,F=D;
	if(M[x-1][y]&&B==1)B=U,U=F,F=D,DFS(x-1,y),F=U,U=B,B=D;
	if(M[x][y-1]&&L==1)L=U,U=R,R=D,DFS(x,y-1),R=U,U=L,L=D;
	if(M[x][y+1]&&R==1)R=U,U=L,L=D,DFS(x,y+1),L=U,U=R,R=D;
}	

bool solve(){
	cnt=0;
	REP(i,1,6)REP(j,1,6)if(M[i][j]){DFS(i,j);return cnt==6;}
}

int main(){
	//freopen("input.txt","r",stdin);
	int T;
	sf("%d",&T);
	while(T--){
		REP(i,1,6)REP(j,1,6)sf("%d",&M[i][j]);
		U=D=L=R=F=B=1;
		pf(solve()?"correct\n":"incorrect\n");
		if(T)pf("\n");
	}
	return 0;
}
