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
#define maxn 1000
using namespace std;

char s[maxn+2];
vector<char>V;

int main(){
	//freopen("input.txt","r",stdin);
	while(1){
		V.clear();
		gets(s);
		if(!strcmp(s,"DONE"))break;
		for(int i=0;s[i];i++){
			if(isalpha(s[i]))V.push_back(tolower(s[i]));
		}
		int len=V.size();
		bool flag=1;
		FOR(i,0,len)if(V[i]!=V[len-1-i]){flag=0;break;}
		pf(flag?"You won't be eaten!\n":"Uh oh..\n");
	}
	return 0;
}
