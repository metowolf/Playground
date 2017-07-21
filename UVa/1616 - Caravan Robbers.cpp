#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> PII;

const int maxn=1e6;
const double eps=1e-9;

int n;
PII A[maxn+10];

bool check(double l){
	double last=0;
	for(int i=1;i<=n;i++){
		last=max(last,(double)A[i].X)+l;
		if(last>A[i].Y)return 0;
	}
	return 1;
}


int main(){
	while(~scanf("%d",&n)){
		for(int i=1;i<=n;i++){
			int L,R;
			scanf("%d%d",&L,&R);
			A[i]=PII(L,R);
		}
		sort(A+1,A+n+1);
		double L=0,R=1e6;
		while(L+eps<R){
			double mid=(L+R)/2;
			if(check(mid))L=mid;
			else R=mid;
		}
		int a=0,b=1;
		for(int p,q=1;q<=n;q++){
			p=round(q*L);
			if(fabs((double)p/q-L)<fabs((double)a/b-L))a=p,b=q;
		}
		printf("%d/%d\n",a,b);
	}
	return 0;
}

