#include<bits/stdc++.h>
#define L(x) c[x][0]
#define R(x) c[x][1]
using namespace std;
const int N=1e5+10;

int rnd[N]={0},siz[N]={0},c[N][2],sz=0,rt;
int w[N],sub[N]={0},ans=0;
int upd(int &x){
	siz[x]=siz[L(x)]+siz[R(x)]+1;
	sub[x]=max(max(sub[L(x)],sub[R(x)]),w[x]);
	ans=max(ans,sub[x]);
}
int rotate(int &x,int l){
	int r=l^1,y=c[x][l];
	c[x][l]=c[y][r];c[y][r]=x;
	upd(x);upd(y);x=y;
}
int query(int &x,int rk){
	if(!rk||!x)return 0;
	if(siz[L(x)]>=rk)return query(L(x),rk);
	if(siz[L(x)]<rk){
		int ret=query(R(x),rk-siz[L(x)]-1);
		return max(ret,max(sub[L(x)],w[x]));
	}
}
void add(int &x,int val,int l){
	if(!x){
		x=++sz;w[sz]=val;upd(sz);
		rnd[sz]=rand();return;
	}
	add(c[x][l],val,l);upd(x);
	if(rnd[c[x][l]]>rnd[x])rotate(x,l);
}
void ins(int &x,int rk,int val){
	if(siz[rt]+1==rk){add(rt,val,1);return;}
	if(siz[L(x)]+1==rk){
		add(L(x),val,1);upd(x);
		if(rnd[L(x)]>rnd[x])rotate(x,0);
	}else if(siz[L(x)]>=rk)ins(L(x),rk,val);
	else ins(R(x),rk-siz[L(x)]-1,val);
	upd(x);
}

int main(){
	int n,x;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int x;
		scanf("%d",&x);
		ins(rt,x+1,query(rt,x)+1);
		printf("%d\n",ans);
	}
	return 0;
}
