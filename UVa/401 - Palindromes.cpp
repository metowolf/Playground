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

char* msg[]={"not a palindrome","a regular palindrome","a mirrored string","a mirrored palindrome"};
char rev[]="A   3  HIL JM O   2TUVWXY51SE Z  8 ";
char r(char ch){return isalpha(ch)?rev[ch-'A']:rev[ch-'0'+25];}

int main(){
	//freopen("input.txt","r",stdin);
	char s[30];
	while(~sf("%s",s)){
		int len=strlen(s);
		int p=1,q=1;
		for(int i=0;i<(len+1)/2;i++){
			if(s[i]!=s[len-1-i])p=0;
			if(r(s[i])!=s[len-1-i])q=0;
		}
		pf("%s -- is %s.\n\n",s,msg[q*2+p]);
	}
	return 0;
}
