#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<stack>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf scanf
#define pf printf
#define maxn 128
#define endl '\n'
using namespace std;

stack<char>S;
char s[maxn+2];

int main(){
	int T;
	sf("%d\n",&T);
	while(T--){
		gets(s);
		while(!S.empty())S.pop();
		for(int i=0;s[i];i++){
			if(S.empty())S.push(s[i]);
			else if(S.top()=='('&&s[i]==')')S.pop();
			else if(S.top()=='['&&s[i]==']')S.pop();
			else S.push(s[i]);
		}
		pf(S.size()?"No\n":"Yes\n");
	}
	return 0;
}
