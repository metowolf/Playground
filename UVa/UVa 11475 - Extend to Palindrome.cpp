#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
using namespace std;

const int maxn = 100000;
char a[maxn+2],b[maxn+2];
int nxt[maxn+2];

void get_next(char T[]){
	int n=strlen(T);
	nxt[1]=0;
	int j=0;
	REP(i,2,n){
		while(j&&T[j]!=T[i-1])j=nxt[j];
		if(T[j]==T[i-1])j++;
		nxt[i]=j;
	}
}

void find(char *T,char *S){
	int n=strlen(T);
	int j=0;
	FOR(i,0,n){
		while(j&&T[i]!=S[j])j=nxt[j];
		if(T[i]==S[j])j++;
	}
	printf("%s%s\n",T,S+j);
}

int main(){
	//freopen("input.txt","r",stdin);
	while(~sf("%s",a)){
		strcpy(b,a);
		reverse(b,b+strlen(b));
		get_next(b);
		find(a,b);
	}	
	return 0;
}
