#include<bits/stdc++.h>
#define maxn 15
#define INF 1e9
using namespace std;

const double PI=acos(-1.0);
int n;
double L;
struct Point{
	double x,y,v,L;
	friend Point operator -(Point a,Point b){
		return (Point){a.x-b.x,a.y-b.y};
	}
	friend bool operator <(Point a,Point b){
		return make_pair(a.x,a.y)<make_pair(b.x,b.y);
	}
	double length(){
		return sqrt(x*x+y*y);
	}
}P[maxn+2],PP[maxn+2],CH[maxn+2];

double cross(Point a,Point b){
	return a.x*b.y-a.y*b.x;
}

double CovexHull(int st){
	int nn=0;
	for(int i=1;i<=n;i++)if(!(st&(1<<(i-1))))PP[++nn]=P[i];
	sort(PP+1,PP+nn+1);
	int m=0;
	for(int i=1;i<=nn;i++){
		while(m>1&&cross(CH[m]-CH[m-1],PP[i]-CH[m-1])<0)m--;
		CH[++m]=PP[i];
	}
	int k=m;
	for(int i=nn-1;i>=1;i--){
		while(m>k&&cross(CH[m]-CH[m-1],PP[i]-CH[m-1])<0)m--;
		CH[++m]=PP[i];
	}
	m-=(nn>1);
	CH[0]=CH[m];
	double l=0;
	for(int i=1;i<=m;i++)l+=(CH[i]-CH[i-1]).length();
	return l;
}

int main(){
	//freopen("input.txt","r",stdin);
	int _=0;
	while(~scanf("%d",&n),n){
	
		int ans;	
		double minv=INF,sumv,sumL,mincnt=INF,cnt,extra;
		
		for(int i=1;i<=n;i++)
			scanf("%lf%lf%lf%lf",&P[i].x,&P[i].y,&P[i].v,&P[i].L);
		for(int st=0;st<(1<<n);st++){
			sumv=sumL=cnt=0;
			for(int i=1;i<=n;i++)if(st&(1<<(i-1))){
				sumv+=P[i].v,sumL+=P[i].L,cnt++;
			}
			double len=CovexHull(st);
			if(len<=sumL&&((sumv<minv)||(sumv==minv&&cnt<mincnt))){
				minv=sumv;
				mincnt=cnt;
				extra=sumL-len;
				ans=st;
			}
		}
		if(_)printf("\n");
		printf("Forest %d\n",++_);
		printf("Cut these trees:");
		for(int i=1;i<=n;i++)if(ans&(1<<(i-1)))printf(" %d",i);printf("\n");
		printf("Extra wood: %.2f\n",extra);
	}
	return 0;
}
