#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long LL;

const int maxn=1e3;

struct Point{long long x,y,z;};
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y,a.z-b.z};}
LL operator *(Point a,Point b){return (LL)a.x*b.x+(LL)a.y*b.y+(LL)a.z*b.z;}

int n;
long long r,H;
Point P[maxn+10];
bool vis[maxn+10];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%lld%lld",&n,&H,&r);
		for(int i=1;i<=n;i++){
			scanf("%lld%lld%lld",&P[i].x,&P[i].y,&P[i].z);
			vis[i]=0;
		}
		queue<Point>Q;
		for(int i=1;i<=n;i++)if(P[i].z-r<=0){
			Q.push(P[i]);
			vis[i]=1;
		}
		while(!Q.empty()){
			Point o=Q.front();
			Q.pop();
			for(int i=1;i<=n;i++)if(!vis[i]&&(P[i]-o)*(P[i]-o)<=(LL)(r+r)*(r+r)){
				Q.push(P[i]);
				vis[i]=1;
			}
		}
		bool flag=0;
		for(int i=1;i<=n;i++)if(vis[i]&&P[i].z+r>=H)flag=1;
		printf(flag?"Yes\n":"No\n");
	}
	return 0;
}
