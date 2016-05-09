#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<set>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf scanf
#define pf printf
#define maxn 300000
#define endl '\n'
using namespace std;

set<string>S;
set<string>::iterator it;

int main(){
	//freopen("input.txt","r",stdin);
	string s;
	while(cin>>s)S.insert(s);
	for(it=S.begin();it!=S.end();it++){
		int len=(*it).size();
		FOR(i,0,len){
			if(S.count((*it).substr(0,i))&&S.count((*it).substr(i,len))){
				pf("%s\n",(*it).c_str());
				break;
			}
		}
	}
	return 0;
}
