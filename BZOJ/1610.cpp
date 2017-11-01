#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> PII;

const int maxn=200;

struct Point{int x,y;};
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}

set<PII>S;
Point P[maxn+10];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		P[i]=(Point){x,y};
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++){
			Point t=P[i]-P[j];
			int d=__gcd(t.x,t.y);
			S.insert(PII(t.x/d,t.y/d));
		}
	printf("%d\n",S.size());
	return 0;
}
