#include<bits/stdc++.h>
using namespace std;
typedef long long LL;

const LL mod=1e9+7;

struct Mat{
	static const int SIZE=3;
	LL v[SIZE+1][SIZE+1];

	void clear(){
		memset(v,0,sizeof(v));
	}

	void makeI(){
		clear();
		for(int i=1;i<=SIZE;i++)v[i][i]=1;
	}

	friend Mat operator *(Mat a,Mat b){
		Mat t;
		t.clear();
		for(int i=1;i<=SIZE;i++)
			for(int j=1;j<=SIZE;j++)if(a.v[i][j])
				for(int k=1;k<=SIZE;k++)
					t.v[i][k]=(t.v[i][k]+a.v[i][j]*b.v[j][k]%mod)%mod;
		return t;
	}

	friend Mat operator ^(Mat a,LL k){
		Mat t;t.makeI();
		while(k){
			if(k&1)t=t*a;
			k>>=1LL;
			a=a*a;
		}
		return t;
	}
};

void OEIS(){
	LL h[100+10];
	h[0]=2,h[1]=3,h[2]=6;
	for(int i=3;i<=100;i++)h[i]=4*h[i-1]+17*h[i-2]-12*h[i-3]-16;
	for(int i=2;i<=10;i++){
		//b_n=3h_{n+1} h_n+9h_{n+1} h_{n-1}+9h_n^2+27h_n h_{n-1}-18h_{n+1}-126h_n-81h_{n-1}+192(n>0)
		LL b=3*h[i+1]*h[i]+9*h[i+1]*h[i-1]+9*h[i]*h[i]+27*h[i]*h[i-1]-18*h[i+1]-126*h[i]-81*h[i-1]+192;
		LL a=b+(1LL<<(2*i));
		printf("%lld\n",(LL)sqrt(a));
	}
}
/*
31
197
1255
7997
50959
324725
2069239
13185773
84023455
7 -4
*/

int main(){
	//OEIS();
	int T;
	scanf("%d",&T);
	while(T--){
		LL n;
		scanf("%lld",&n);
		Mat a;a.clear();
		a.v[1][1]=7,a.v[1][2]=-4,a.v[2][1]=1;
		Mat b;b.clear();
		b.v[1][1]=197,b.v[2][1]=31;
		a=a^(n-2);
		b=a*b;
		printf("%lld\n",(b.v[2][1]+mod)%mod);
	}
	return 0;
}

