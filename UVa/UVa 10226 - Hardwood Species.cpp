#include<algorithm>
#include <iostream>
#include  <cstring>
#include  <cstdlib>
#include   <cstdio>
#include   <vector>
#include    <cmath>
#include    <queue>
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

	int T;
	scanf("%d\n\n",&T);
	while(T--){
		int cnt=0;
		string s;
		map<string,int>H;
		while(getline(cin,s,'\n')&&s[0]){
			cnt++;
			if(H.count(s))++H[s];
			else H[s]=1;
		}
		for(map<string,int>::iterator it=H.begin();it!=H.end();it++){
			printf("%s %0.4f\n",it->first.c_str(),it->second*100.0/cnt);
		}
		if(T)putchar('\n');
	}
	return 0;
}
