#include<bits/stdc++.h>
#define maxn 800
#define eps 1e-8
using namespace std;

int fac[maxn+2];

int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		int cnt1=0;	
		double cnt2=0;

		for(int i=1;i<=k;i++)fac[i]=0;

		for(int t=1,i=1;i<=n;i++){
			cnt2+=log(i)/log(k),t*=i;
			for(int ii=i,j=2;j<=k;j++){
				while(ii%j==0)++fac[j],ii/=j;
			}
		}
		
		while(1){
			int t=k;
			for(int i=2;i<=k;i++){
				while(fac[i]&&t%i==0)--fac[i],t/=i;
			}
			if(t==1)cnt1++;
			else break;
		}
		
		printf("%d %d\n",cnt1,int(cnt2+eps)+1);
	}
	return 0;
}

