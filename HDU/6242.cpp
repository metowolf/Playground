#include<bits/stdc++.h>
using namespace std;

const double eps=1e-6;
const int maxn=1e5;

inline int dcmp(double x){return (x>eps)-(x<-eps);}

struct Point{double x,y;};
Point operator +(Point a,Point b){return (Point){a.x+b.x,a.y+b.y};}
Point operator -(Point a,Point b){return (Point){a.x-b.x,a.y-b.y};}
Point operator *(Point a,double b){return (Point){a.x*b,a.y*b};}
Point operator /(Point a,double b){return (Point){a.x/b,a.y/b};}
double dot(Point a,Point b){return a.x*b.x+a.y*b.y;}
double cross(Point a,Point b){return a.x*b.y-a.y*b.x;}
double length(Point a){return dot(a,a);}

int n;
Point P[maxn+10];

bool in_line(Point a,Point b,Point c){
    return dcmp(cross(b-a,c-a))==0;
}

Point wai(Point a,Point b,Point c){
    Point res;
    double a1=b.x-a.x,b1=b.y-a.y,c1=(a1*a1+b1*b1)/2;
    double a2=c.x-a.x,b2=c.y-a.y,c2=(a2*a2+b2*b2)/2;
    double d=a1*b2-a2*b1;
    res.x=a.x+(c1*b2-c2*b1)/d;
    res.y=a.y+(a1*c2-a2*c1)/d;
    return res;
}

void Rand(int &i,int &j,int &k){
    i=rand()%n+1;
    j=rand()%n+1;
    k=rand()%n+1;
    while(i==j)j=rand()%n+1;
    while(i==k||j==k)k=rand()%n+1;
}

bool judge(Point o,double r){
    int N=(n+1)/2,cnt=0;
    for(int i=1;i<=n;i++){
        cnt+=fabs(length(P[i]-o)-r)<=eps;
        if(cnt>=N)return 1;
    }
    return 0;
}    

void solve(){
    int kase=200;
    while(kase--){
        int i,j,k;
        Rand(i,j,k);
        if(in_line(P[i],P[j],P[k]))continue;
        Point o=wai(P[i],P[j],P[k]);
        double r=length(P[i]-o);
        if(judge(o,r)){
            printf("%.8f %.8f %.8f\n",o.x,o.y,sqrt(r));
            return;
        }
    }
}

void bf(){
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            Point o=(P[i]+P[j])/2;
            double r=length(P[i]-o);
            if(judge(o,r)){
                printf("%.8f %.8f %.8f\n",o.x,o.y,sqrt(r));
                return;
            }
        }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++)
            for(int k=j+1;k<=n;k++){
                if(in_line(P[i],P[j],P[k]))continue;
                Point o=wai(P[i],P[j],P[k]);
                double r=length(P[i]-o);
                if(judge(o,r)){
                    printf("%.8f %.8f %.8f\n",o.x,o.y,sqrt(r));
                    return;
                }
            }
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)scanf("%lf%lf",&P[i].x,&P[i].y);
        if(n<=2)printf("%.8f %.8f %.8f\n",P[1].x,P[1].y,0.);
        else if(n<=10)bf();
        else solve();
    }
    return 0;
}
