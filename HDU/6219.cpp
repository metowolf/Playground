#include<bits/stdc++.h>
using namespace std;

const int maxn=100;

struct Point{int x,y;};
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
int operator ^(Point a,Point b){return a.x*b.y-a.y*b.x;}
int operator *(Point a,Point b){return a.x*b.x+a.y*b.y;}
bool operator <(Point a,Point b){return (a^b)>0||(a^b)==0&&(a*a)<(b*b);}
int dot(Point a,Point b){return a*b;}
int cross(Point a,Point b){return a^b;}

int n;
Point P[maxn+10],C[maxn+10];
int f[maxn+10][maxn+10];

int gao(int tot){
	int res=0;
	memset(f,0,sizeof(f));
	for(int i=1;i<tot;i++){
		int j=i-1;
		while(j>=0&&(C[i]^C[j])==0)j--;
		bool flag=j==i-1;
		while(j>=0){
			int area=C[j]^C[i];
			int k=j-1;
			while(k>=0&&((C[j]-C[i])^(C[k]-C[j]))>0)k--;
			if(k>=0)area+=f[j][k];
			if(flag)f[i][j]=area;
			res=max(res,area);
			j=k;
		}
		if(flag)for(int j=1;j<i;j++)f[i][j]=max(f[i][j],f[i][j-1]);
	}
	return res;
}

int solve(){
	int res=0;
	for(int i=0;i<n;i++){
		int m=0;
		for(int j=0;j<n;j++)
			if(P[i].y>P[j].y||(P[i].x>=P[j].x&&P[j].y==P[i].y))C[m++]=P[j]-P[i];
		sort(C,C+m);
		res=max(res,gao(m));
	}
	return res;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<n;i++)scanf("%d%d",&P[i].x,&P[i].y);
		int ans=solve();
		printf("%d.%d\n",ans/2,ans%2*5);
	}
	return 0;
}

