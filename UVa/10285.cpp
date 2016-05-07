#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf scanf
#define pf printf
#define maxn 100
#define endl '\n'
using namespace std;

string name;
int n,m;
int dx[]={1,-1,0,0},dy[]={0,0,1,-1};
int A[maxn+2][maxn+2],B[maxn+2][maxn+2];

int dp(int x,int y){
	if(B[x][y])return B[x][y];
	int ans=0;
	FOR(i,0,4){
		int _x=x+dx[i],_y=y+dy[i];
		if(_x<1||_x>n||_y<1||_y>m)continue;
		if(A[_x][_y]<A[x][y])ans=max(ans,dp(_x,_y));
	}
	return B[x][y]=ans+1;
}

int main(){
	int T;
	sf("%d",&T);
	while(T--){
		cin>>name;
		sf("%d%d",&n,&m);
		REP(i,1,n)REP(j,1,m)sf("%d",&A[i][j]);
		CLR(B,0);
		int ans=0;
		REP(i,1,n)REP(j,1,m)B[i][j]=dp(i,j),ans=max(ans,B[i][j]);
		pf("%s: %d\n",name.c_str(),ans);
	}
	return 0;
}
