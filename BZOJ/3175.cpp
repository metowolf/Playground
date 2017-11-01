#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
using namespace std;

const int maxn=200;
const int dx[]={-2,-2,-1,-1,1,1,2,2};
const int dy[]={-1,1,-2,2,-2,2,-1,1};

int n;
char A[maxn+10][maxn+10];

struct edge{int to,nxt;}E[maxn*maxn*8+10];
int head[maxn*maxn+10],cnt=0;

void addedge(int from,int to){
	E[++cnt]={to,head[from]};
	head[from]=cnt;
}

bool use[maxn*maxn+10];
int from[maxn*maxn+10];

bool match(int x){
	for(int i=head[x];i;i=E[i].nxt)if(!use[E[i].to]){
		use[E[i].to]=true;
		if(from[E[i].to]==-1||match(from[E[i].to])){
			from[E[i].to]=x;
			return true;
		}
	}
	return false;
}

int hungary(int N){
	int tot=0;
	for(int i=0;i<N;i++)from[i]=-1;
	for(int i=0;i<N;i++){
		memset(use,0,sizeof(use));
		tot+=match(i);
	}
	return tot;
}

int num[maxn+10][maxn+10];

int main(){
	int tot=0;
	scanf("%d",&n);
	FOR(i,0,n)FOR(j,0,n){
		scanf(" %c",&A[i][j]);
		if(A[i][j]=='0')num[i][j]=tot++;
	}
	FOR(i,0,n)FOR(j,0,n)if(A[i][j]=='0'){
		FOR(ii,4,8){
			int x=i+dx[ii],y=j+dy[ii];
			if(x<0||x>=n||y<0||y>=n||A[x][y]=='1')continue;
			addedge(num[i][j],num[x][y]);
			addedge(num[x][y],num[i][j]);
		}
	}
	printf("%d\n",tot-hungary(tot)/2);
	return 0;
}
