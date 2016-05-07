#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define FOOR(i,a,b) for(int i=a;i<=b;i++)
#define PB push_back
#define maxn 100+2
#define INF 1e9
using namespace std;

int n,m,ans;
struct edge{
	int from,to,value;
};
vector<edge>E;
int father[maxn*maxn];
int Find(int x){return father[x]==x?x:father[x]=Find(father[x]);}
bool cmp(edge a,edge b){return a.value<b.value;}

int kruskal(int start){
	FOOR(i,1,n)father[i]=i;
	int Min=INF,Max=-INF,cnt=1;
	FOR(i,start,E.size()){
		edge &e=E[i];
		int fa=Find(e.from),fb=Find(e.to);
		if(fa!=fb){
			father[fa]=fb;
			Min=min(Min,e.value);
			Max=max(Max,e.value);
			cnt++;
		}
		if(cnt==n)break;
	}
	//printf("[%d,%d]\n",Max,Min);
	if(cnt==n)return Max-Min;
	else return INF;
}

void solve(){
	E.clear();
	ans=INF;
	
	FOR(i,0,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		E.PB((edge){a,b,c});
	}
	sort(E.begin(),E.end(),cmp);
	FOR(i,0,E.size()){
		ans=min(ans,kruskal(i));
	}
	printf("%d\n",ans==INF?-1:ans);
}

int main(){
	while(~scanf("%d%d",&n,&m),n||m)solve();
	return 0;
}
