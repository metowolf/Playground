#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#define sf scanf
#define pf printf
#define maxn 30
using namespace std;

int n,m;
int A[maxn*maxn+2];

int main(){
	int _=0;
	while(~sf("%d%d",&n,&m),n){
		n*=m;
		REP(i,1,n)sf("%d",A+i);
		A[++n]=1e9;
		sort(A+1,A+n+1);
		double sum=0;
		sf("%lf",&sum);
		int k;
		double H;
		sum/=100.0;
		REP(i,2,n){
			sum+=A[i-1];
			H=sum/(i-1);
			if(H<A[i]){
				k=i;
				break;
			}
		}
		printf("Region %d\n",++_);  
        printf("Water level is %.2lf meters.\n",H);  
        printf("%.2lf percent of the region is under water.\n\n",100.0*k/(n-1));  
	}		
	return 0;
}
