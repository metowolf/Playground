#include<bits/stdc++.h>
#define eps 1e-12
using namespace std;

int n;
double R;
const double PI=acos(-1.0);

double area(double a,double b,double c){
    double p=(a+b+c)/2;
    return sqrt(p*(p-a)*(p-b)*(p-c));
}

double calc_r(){
    if(n==1)return R;
    double l=0,r=R;
    while(l+eps<r){
        double mid=(l+r)/2;
        if(mid+(mid)/sin(PI/n)>R)r=mid;
        else l=mid;
    }
    return l;
}

int main(){
    while(~scanf("%lf%d",&R,&n)){
        double r=calc_r();
        double I=n*area(R-r,R-r,2*r)-PI*r*r/2*(n-2);if(n==1)I=0;
        double E=PI*R*R-PI*r*r*n-I;
        printf("%.10f %.10f %.10f\n",r,I,E);
    }
    return 0;
}
