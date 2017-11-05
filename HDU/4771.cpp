#include<bits/stdc++.h>
#define CLR(c,x) memset(c,x,sizeof(c))
using namespace std;  

const int inf=~0U>>1;
const int maxn=100;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};

int n,m,k;  

char mat[maxn+10][maxn+10];  

struct Node{int x,y,step;};
Node start;  
Node node[5];   

inline bool IN(int x,int y){return x>=1&&x<=n&&y>=1&&y<=m;}

bool vis[maxn+10][maxn+10];
int bfs(Node begin,Node end){  
	queue<Node>q; 
	CLR(vis,0);
	begin.step=0;  
	q.push(begin);
	vis[begin.x][begin.y]=1;
	while(!q.empty()){
		Node tmp=q.front();  
		q.pop();
		if(tmp.x==end.x&&tmp.y==end.y)return tmp.step;
		for(int i=0;i<4;i++){ 
			int x=tmp.x+dx[i];
			int y=tmp.y+dy[i];
			if(IN(x,y)&&!vis[x][y]&&mat[x][y]=='.'){  
				q.push((Node){x,y,tmp.step+1});  
				vis[x][y]=1;  
			}  
		}  
	}  
	return inf;
}  

void solve(){  
	int id[10];  
	int ans=inf;
	for(int i=0;i<k;i++)id[i]=i+1;  

	do{
		int step=bfs(start,node[id[0]]);  
		for(int i=1;i<k;i++)  
			step+=bfs(node[id[i-1]],node[id[i]]);  
		ans=min(ans,step);
	}while(next_permutation(id,id+k));

	printf("%d\n",ans==inf?-1:ans);  
}  

int main(){  
	while(scanf("%d%d",&n,&m),n||m){
		for(int i=1;i<=n;i++)for(int j=1;j<=m;j++){
			scanf(" %c",&mat[i][j]);
			if(mat[i][j]=='@')start=(Node){i,j,0};
		}
		scanf("%d",&k);  
		for(int i=1;i<=k;i++)
			scanf("%d%d",&node[i].x,&node[i].y);  
		solve(); 
	}  
	return 0;  
}  

