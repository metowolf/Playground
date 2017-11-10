#include<bits/stdc++.h>
using namespace std;

const double eps=1e-8;

int dcmp(double x){return (x>eps)-(x<-eps);}

int main(){
	double x1,y1,r1,x2,y2,r2;
	scanf("%lf%lf%lf%lf%lf%lf",&x1,&y1,&r1,&x2,&y2,&r2);
	if(r1>r2)swap(r1,r2),swap(x1,x2),swap(y1,y2);
	double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
	if(dcmp(x1-x2)==0&&dcmp(y1-y2)==0&&dcmp(r1-r2)==0)
		return 0*printf("%d\n",dcmp(r1)==0?1:-1);
	if(dcmp(d-(r1+r2))==0||dcmp(d-fabs(r1-r2))==0)return 0*printf("1\n");
	if(dcmp(d-r1-r2)==1)return 0*printf("0\n");
	if(dcmp(d-fabs(r1-r2))==-1)return 0*printf("0\n");
	printf("2\n");
	return 0;
}
