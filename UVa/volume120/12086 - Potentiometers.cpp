#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define ECH(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i) 
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
//#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn 200000
#define lson root<<1,l,mid
#define rson root<<1|1,mid+1,r
using namespace std;

int n;
int sum[(maxn+2)<<2];

void build(int root,int l,int r){
	if(l==r){
		sf("%d",&sum[root]);
		return;
	}
	int mid=l+(r-l)/2;
	build(lson),build(rson);
	sum[root]=sum[root<<1]+sum[root<<1|1];
}

void modify(int root,int l,int r,int id,int x){
	if(l==r){
		sum[root]=x;
		return;
	}
	int mid=l+(r-l)/2;
	if(mid>=id)modify(lson,id,x);
	else modify(rson,id,x);
	sum[root]=sum[root<<1]+sum[root<<1|1];
}

int query(int root,int l,int r,int L,int R){
	if(L<=l&&r<=R)return sum[root];
	if(r<L||R<l)return 0;
	int mid=l+(r-l)/2;
	return query(lson,L,R)+query(rson,L,R);
}	

int main(){
	//freopen("input.txt","r",stdin);
	
	int _=0;
    while(~sf("%d",&n),n){
    	build(1,1,n);
    	char op[5];
    	if(_)puts("");
    	pf("Case %d:\n",++_);
		while(~sf("%s",op)){
			if(op[0]=='E')break;
			if(op[0]=='S'){
				int id,x;
				sf("%d%d",&id,&x);
				modify(1,1,n,id,x);
			}
			if(op[0]=='M'){
				int l,r;
				sf("%d%d",&l,&r);
				pf("%d\n",query(1,1,n,l,r));
			}
		}
    }
	return 0;
}
