#include<bits/stdc++.h>
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
using namespace std;

const int INF=~0U>>2;
const int maxn=5e4;

int Min[maxn*4+10],Max[maxn*4+10];

int read(){
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

void up(int root){
	Min[root]=min(Min[root<<1],Min[root<<1|1]);
	Max[root]=max(Max[root<<1],Max[root<<1|1]);
}

void build(int root,int l,int r){
	if(l==r){
		Min[root]=Max[root]=read();
		return;
	}
	int mid=l+r>>1;
	build(lson),build(rson);
	up(root);
}

int qmin(int root,int l,int r,int L,int R){
	if(r<L||R<l)return INF;
	if(L<=l&&r<=R)return Min[root];
	int mid=l+r>>1;
	return min(qmin(lson,L,R),qmin(rson,L,R));
}

int qmax(int root,int l,int r,int L,int R){
	if(r<L||R<l)return -INF;
	if(L<=l&&r<=R)return Max[root];
	int mid=l+r>>1;
	return max(qmax(lson,L,R),qmax(rson,L,R));
}

int main(){
	int n=read(),q=read();
	build(1,1,n);
	while(q--){
		int L=read(),R=read();
		printf("%d\n",qmax(1,1,n,L,R)-qmin(1,1,n,L,R));
	}
	return 0;
}

