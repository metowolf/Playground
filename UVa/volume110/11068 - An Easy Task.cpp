#include<bits/stdc++.h>
using namespace std;

double a1,a2,b1,b2,c1,c2;

int main(){
    while(~scanf("%lf%lf%lf%lf%lf%lf",&a1,&b1,&c1,&a2,&b2,&c2)){
        if(!(a1||a2||b1||b2||c1||c2))break;
        if(a1*b2==a2*b1)printf("No fixed point exists.\n");
        else{
            double y=(c1*a2-c2*a1)/(b1*a2-b2*a1);
            double x=(c1-b1*y)/a1;
            printf("The fixed point is at %.2f %.2f.\n",x,y);
        }
    }
    return 0;
}
