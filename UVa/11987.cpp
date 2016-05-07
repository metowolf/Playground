#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define CLR(c,x) memset(c,x,sizeof(c))
#define ESP 1e-8
#define sf scanf
#define pf printf
#define INF ~0U>>1
#define maxn 100000
using namespace std;

int n,m,op;
int father[maxn*2+10],sum[maxn*2+10],cnt[maxn*2+10];

int Find(int x){
	if(father[x]==x)return x;
	else{
		father[x]=Find(father[x]);
		sum[father[x]]+=sum[x],sum[x]=0;
		cnt[father[x]]+=cnt[x],cnt[x]=0;
		return father[x];
	}
}

void Union(int a,int b){
	int fa=Find(a),fb=Find(b);
	if(fa==fb)return;
	father[fa]=fb;
	sum[fb]+=sum[fa],sum[fa]=0;
	cnt[fb]+=cnt[fa],cnt[fa]=0;
}

void Modify(int a,int b){
	int fa=Find(a),fb=Find(b);
	if(fa==fb)return;
	sum[fa]-=a;
	cnt[fa]--;
	father[a]=fb;
	sum[fb]+=a;
	cnt[fb]++;
}

void solve(){
	int a,b;
	while(m--){
		sf("%d",&op);
		if(op==1)sf("%d%d",&a,&b),Union(a,b);
		else if(op==2)sf("%d%d",&a,&b),Modify(a,b);
		else sf("%d",&a),b=Find(a),pf("%d %d\n",cnt[b],sum[b]);
	}
}

void init(){
	REP(i,1,n)father[i]=father[i+n]=i+n,sum[i+n]=i,cnt[i+n]=1,sum[i]=cnt[i]=0;
}

int main(){
	while(~sf("%d%d",&n,&m))init(),solve();
	return 0;
}

