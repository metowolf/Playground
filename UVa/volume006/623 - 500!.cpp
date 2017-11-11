#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define ECH(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i) 
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn 3000
using namespace std;

struct bign{
	int len,v[maxn+2];
	bign(){len=0,CLR(v,0);}
	void print(){uREP(i,len,1)pf("%d",v[i]);}
	
	bign operator*(int b){
		REP(i,1,len)v[i]*=b;
		REP(i,1,len){
			v[i+1]+=v[i]/10;
			v[i]%=10;
			if(v[i+1])len=max(len,i+1);
		}
		return *this;
	}
};

int main(){
	//freopen("input.txt","r",stdin);
	int n;
	while(~sf("%d",&n)){
		bign ans;
		ans.v[1]=ans.len=1;
		REP(i,1,n)ans=ans*i;
		pf("%d!\n",n);
		ans.print();pf("\n");
	}
	return 0;
}
