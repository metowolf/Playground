#include<bits/stdc++.h>
using namespace std;

const int maxn=300;

struct edge{int from,to,dis;};

int F[maxn+10];
int find(int x){return F[x]==x?x:F[x]=find(F[x]);}

int n;
int w[maxn+10];
vector<edge>E;

bool cmp(edge a,edge b){return a.dis<b.dis;}

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",w+i);
		E.push_back((edge){i,n+1,w[i]});
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int t;
			scanf("%d",&t);
			if(i<j)E.push_back((edge){i,j,t});
		}
	for(int i=1;i<=n+1;i++)F[i]=i;
	int ans=0;
	sort(E.begin(),E.end(),cmp);
	for(int i=0;i<E.size();i++){
		edge &e=E[i];
		int fa=find(e.from),fb=find(e.to);
		if(fa!=fb){
			F[fa]=fb;
			ans+=e.dis;
		}
	}
	printf("%d\n",ans);
	return 0;
}

