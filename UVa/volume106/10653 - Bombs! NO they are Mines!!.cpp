#include<bits/stdc++.h>
#define maxn 1000
using namespace std;

struct Point{int x,y,d;};

int n,m;
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
bool A[maxn+2][maxn+2];
bool vis[maxn+2][maxn+2];

int BFS(Point S,Point T){
	queue<Point>Q;
	Q.push(S);
	vis[S.x][S.y]=1;
	while(!Q.empty()){
		Point t=Q.front();
		Q.pop();
		if(t.x==T.x&&t.y==T.y)return t.d;
		for(int i=0;i<4;i++){
			int x=t.x+dx[i],y=t.y+dy[i];
			if(x<0||x>=n||y<0||y>=m||vis[x][y]||A[x][y])continue;
			vis[x][y]=1;
			Q.push((Point){x,y,t.d+1});
		}
	}
}

int main(){
	while(~scanf("%d%d",&n,&m),n+m){
		
		for(int i=0;i<n;i++)for(int j=0;j<m;j++)A[i][j]=vis[i][j]=0;
		
		int t;
		scanf("%d",&t);
		while(t--){
			int x,y,tt;
			scanf("%d%d",&x,&tt);
			while(tt--){
				scanf("%d",&y);
				A[x][y]=1;
			}
		}

		Point S,T;
		S.d=0;
		scanf("%d%d%d%d",&S.x,&S.y,&T.x,&T.y);
		printf("%d\n",BFS(S,T));
	}
	return 0;
}

