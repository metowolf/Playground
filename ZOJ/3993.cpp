#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;
const double inf=1e9;
const int maxn=100;

struct Point{double x,y;};
double len(Point a){return sqrt(a.x*a.x+a.y*a.y);}

int ans[maxn+10];
Point A[maxn+10];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,R,r;
		scanf("%d%d%d",&n,&R,&r);
		int ar=abs(R-2*r),cnt=0,flag=0;
		double minn=inf;
		for(int i=0;i<n;i++){
			scanf("%lf%lf",&A[i].x,&A[i].y);
			minn=min(minn,len(A[i]));
			if(len(A[i])<=ar)flag=1,ans[cnt++]=i;
		}
		if(flag){
			printf("%d\n",cnt);
			for(int i=0;i<cnt;i++)
				printf("%d%c",ans[i]+1,i+1==cnt?'\n':' ');
		}
		else{
			cnt=0;
			for(int i=0;i<n;i++)
				if(abs(len(A[i])-minn)<=eps)
					ans[cnt++]=i;
			printf("%d\n",cnt);
			for(int i=0;i<cnt;i++)
				printf("%d%c",ans[i]+1,i+1==cnt?'\n':' ');
		}
	}
	return 0;
}
