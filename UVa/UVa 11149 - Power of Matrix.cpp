#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf scanf
#define pf printf
#define maxn 40
#define endl '\n'
#define MOD 10
using namespace std;

struct Mat{
	int n,v[maxn+2][maxn+2];
	Mat(){}
	Mat(int n){this->n=n;CLR(v,0);}
	
	Mat operator +(Mat c){
		Mat t(n);
		REP(i,1,n)REP(j,1,n)t.v[i][j]=(v[i][j]+c.v[i][j])%MOD;
		return t;
	}
	
	Mat operator *(Mat c){
		Mat t(n);
		REP(i,1,n)REP(j,1,n)if(v[i][j])REP(k,1,n)
			t.v[i][k]=(t.v[i][k]+v[i][j]*c.v[j][k])%MOD;
		return t;
	}
	
	friend Mat operator ^(Mat a,int k){
		Mat t(a.n);
		REP(i,1,a.n)t.v[i][i]=1;
		while(k){
			if(k&1)t=t*a;
			a=a*a;
			k>>=1;
		}
		return t;
	}
};

Mat solve(Mat A,int k){
	//pf("%d\n",k);
	if(k==1)return A;
	Mat t(A.n);
	REP(i,1,A.n)t.v[i][i]=1;
	if(k==0)return t;
	t=(t+(A^(k/2)))*solve(A,k/2);
	if(k&1)t=t+(A^k);
	return t;
}

int main(){
	//freopen("input.txt","r",stdin);

	int n,k;
	while(~sf("%d%d",&n,&k),n){
		Mat A(n);
		REP(i,1,n)REP(j,1,n)sf("%d",&A.v[i][j]),A.v[i][j]%=MOD;
		A=solve(A,k);
		REP(i,1,n)REP(j,1,n)pf("%d%c",A.v[i][j],j==n?'\n':' ');
		puts("");
	}	
	return 0;
}
