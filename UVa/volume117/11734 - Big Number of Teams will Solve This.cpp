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
#define sf   scanf
#define pf   printf
#define INF  ~0U>>2
#define EPS  1e-8
#define maxn 200
using namespace std;

int len;
char S[maxn+2],T[maxn+2];
char A[maxn+2],B[maxn+2];

int main(){
	int _T;
	sf("%d\n",&_T);
	REP(_,1,_T){
		gets(A);
		gets(B);
		
		len=0;
		for(int i=0;A[i];i++)if(A[i]!=' ')S[len++]=A[i];
		S[len]='\0';
		len=0;
		for(int i=0;B[i];i++)if(B[i]!=' ')T[len++]=B[i];
		T[len]='\0';
		
		//pf("%s\n%s\n",S,T);
		
		pf("Case %d: ",_);
		if(strlen(S)!=strlen(T))pf("Wrong Answer\n");
		else{
			bool flag=1;
			for(int i=0;S[i];i++)if(S[i]!=T[i]){flag=0;break;}
			if(!flag)pf("Wrong Answer\n");
			else{
				if(strlen(A)!=strlen(B))pf("Output Format Error\n");
				else{
					flag=1;
					for(int i=0;A[i];i++)if(A[i]!=B[i]){flag=0;break;}
					if(!flag)pf("Output Format Error\n");
					else pf("Yes\n");
				}
			}
		}
	}	 
	return 0;
}
