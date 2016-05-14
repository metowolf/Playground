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
#define maxn 50
using namespace std;

int n;
string s[maxn+2];

bool cmp(string a,string b){
	return a+b>b+a;
}

int main(){
    while(~sf("%d",&n),n){
    	REP(i,1,n)cin>>s[i];
    	sort(s+1,s+n+1,cmp);
    	REP(i,1,n)pf("%s",s[i].c_str());
    	pf("\n");
    }
	return 0;
}
