#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

double calc(double L,double C){
	double ans=0;
	if(L<C)swap(L,C);
	// 2*2
	ans=max(ans,C/2);
	// 1*4
	ans=max(ans,min(L/4,C/1));
	return ans;
}

int main(){
	int n;
	while(!scanf("%d",&n),n){
		double maxx=0;int idx=0;
		REP(i,1,n){
			int L,C;
			scanf("%d%d",&L,&C);
			double t=calc(L,C);
			if(t>maxx)maxx=t,idx=i;
		}
		printf("%d\n",idx);
	}
	return 0;
}
