#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

struct Point{LL x,y;};
Point cd(Point a){LL d=__gcd(a.x,a.y);return (Point){a.x/d,a.y/d};}
Point operator +(Point a,Point b){return cd((Point){a.x*b.y+a.y*b.x,a.y*b.y});}
Point operator *(Point a,Point b){return cd((Point){a.x*b.x,a.y*b.y});}

int main(){
	int n;
	while(~scanf("%d",&n)){
		Point ans=(Point){0,1};
		for(int i=1;i<=n;i++)ans=ans+(Point){1,i};
		ans=ans*(Point){n,1};
		LL t=ans.x/ans.y;
		ans.x-=t*ans.y;
		if(ans.x){
			char v[30],x[30],y[30];
            sprintf(v,"%lld",t);
            sprintf(x,"%lld",ans.x);
            sprintf(y,"%lld",ans.y);
            int vl=strlen(v),bl=strlen(y);
            for(int i=0;i<=vl;i++)putchar(' ');
            puts(x);
            printf("%s ",v);
            for(int i=0;i<bl;i++)putchar('-');
            puts("");
            for(int i=0;i<=vl;i++)putchar(' ');
            puts(y);
		}
		else printf("%lld\n",t);
	}
	return 0;
}
