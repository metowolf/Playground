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
#define maxn 50
using namespace std;

int n,X,Y,x,y;

int main(){
	//freopen("input.txt","r",stdin);
	while(~sf("%d",&n),n){
		sf("%d%d",&X,&Y);
		REP(i,1,n){
			sf("%d%d",&x,&y);
			if(x==X||y==Y)pf("divisa\n");
			else{
				pf(y>Y?"N":"S");
				pf(x>X?"E":"O");
				pf("\n");
			}
		}
	}
	return 0;
}
