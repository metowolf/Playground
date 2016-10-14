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
#define maxn 100000
using namespace std;

char A[maxn+2],B[maxn+2];

int main(){
	//freopen("input.txt","r",stdin);
	while(~sf("%s%s",A,B)){
		int i=0,j=0;
		while(A[i]){
			while(B[j]&&A[i]!=B[j])j++;
			if(!B[j])break;
			i++,j++;
		}
		pf(A[i]?"No\n":"Yes\n");
	}
	return 0;
}
