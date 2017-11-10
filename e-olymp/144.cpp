#include<bits/stdc++.h>
using namespace std;

struct Point{int x,y;}P[6];
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
int dot(Point a,Point b){return a.x*b.x+a.y*b.y;}

int main(){
	for(int i=1;i<=4;i++)scanf("%d%d",&P[i].x,&P[i].y);
	P[0]=P[4];P[5]=P[1];
	int ans=0;
	for(int i=1;i<=4;i++)if(dot(P[i-1]-P[i],P[i+1]-P[i])==0)ans++;
	printf("%d\n",ans);
	return 0;
}
