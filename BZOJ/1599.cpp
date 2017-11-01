#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

int cnt[80+2];

int main(){
	int a,b,c,ans,maxcnt=0;
	scanf("%d%d%d",&a,&b,&c);
	REP(i,1,a)REP(j,1,b)REP(k,1,c)++cnt[i+j+k];
	REP(i,3,a+b+c)if(cnt[i]>maxcnt)maxcnt=cnt[i],ans=i;
	printf("%d\n",ans);
	return 0;
}

