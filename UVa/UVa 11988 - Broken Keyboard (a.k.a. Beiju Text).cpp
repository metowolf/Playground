#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <cstdlib>
#include   <cstdio>
#include   <vector>
#include    <cmath>
#include    <queue>
#include     <list>
#include      <map>
#include      <set>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i)
#define CLR(c,x)   memset(c,x,sizeof(c))
#pragma GCC  optimize("O2")
#define INF  ~0U>>2
#define EPS  1e-8
#define maxn 105
using namespace std;

int main(){
	//freopen("input.txt","r",stdin);
	string s;
	while(cin>>s){
		list<char>L;
		list<char>::iterator it=L.begin();
		for(char c:s){
			if(c=='[')it=L.begin();
			else if(c==']')it=L.end();
			else L.insert(it,c);
		}
		for(it=L.begin();it!=L.end();it++)putchar(*it);
		putchar('\n');
	}
	return 0;
}
			
