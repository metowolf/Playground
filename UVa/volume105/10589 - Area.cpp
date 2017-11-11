#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

struct Point{
    double x,y;
    double length(){
        return sqrt(x*x+y*y);
    }
};

int main(){
    int n;double R;
    while(~scanf("%d%lf",&n,&R),n){
        int cnt=0;
        REP(i,1,n){
            double x,y;
            bool flag=1;
            scanf("%lf%lf",&x,&y);
            flag&=((Point){0-x,0-y}).length()<=R;
            flag&=((Point){0-x,R-y}).length()<=R;
            flag&=((Point){R-x,0-y}).length()<=R;
            flag&=((Point){R-x,R-y}).length()<=R;
            cnt+=flag;
        }
        printf("%.5f\n",cnt*R*R/n);
    }
    return 0;
}
