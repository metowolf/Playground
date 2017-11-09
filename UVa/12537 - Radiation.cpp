#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const int maxn=2e5;

struct Point{LL x,y;};
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
LL operator *(Point a,Point b){return a.x*b.x+a.y*b.y;}
LL operator ^(Point a,Point b){return a.x*b.y-a.y*b.x;}
LL dot(Point a,Point b){return a*b;}
LL cross(Point a,Point b){return a^b;}
LL dis2(Point a){return a*a;}

int n,q;
Point P[maxn+10],A,B;
LL disA[maxn+10],disB[maxn+10];

int BS(LL x,LL A[]){
	int L=0,R=n-1;
	while(L<R){
		int mid=L+R>>1;
		if(A[mid]<=x)L=mid+1;
		else R=mid;
	}
	return L;
}

int main(){
	int _=0;
	while(~scanf("%d",&n),n){
		for(int i=0;i<n;i++)scanf("%lld%lld",&P[i].x,&P[i].y);
		scanf("%lld%lld%lld%lld",&A.x,&A.y,&B.x,&B.y);
		for(int i=0;i<n;i++)disA[i]=dis2(P[i]-A),disB[i]=dis2(P[i]-B);
		sort(disA,disA+n);sort(disB,disB+n);
		scanf("%d",&q);
		printf("Case %d:\n",++_);
		while(q--){
			LL R1,R2;
			scanf("%lld%lld",&R1,&R2);
			LL ab=BS(R1*R1,disA);
			LL bc=BS(R2*R2,disB);
			printf("%lld\n",max(n-ab-bc,0LL));
		}
	}
	return 0;
}
