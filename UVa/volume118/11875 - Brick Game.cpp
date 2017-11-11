#include<bits/stdc++.h>
using namespace std;

int A[11+2];

int main(){
	int T,_=0;
	scanf("%d",&T);
	while(T--){
		 int n;
		 scanf("%d",&n);
		 for(int i=1;i<=n;i++)scanf("%d",A+i);
		 sort(A+1,A+n+1);
		 printf("Case %d: %d\n",++_,A[(n+1)/2]);
	}
	return 0;
}
