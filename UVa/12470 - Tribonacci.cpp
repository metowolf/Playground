#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000009
using namespace std;
typedef long long LL;

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
					t.v[i][k]=(t.v[i][k]+a.v[i][j]*b.v[j][k])%mod;
		return t;
	}

	friend Mat operator ^(Mat a,LL k){
		Mat t;
		t.makeI();
		while(k){
			if(k&1)t=t*a;
			k>>=1;
			a=a*a;
		}
		return t;
	}
};

int main(){
	LL n;
	Mat A,B;
	while(~scanf("%lld",&n),n){
		A.clear();
		A.v[1][1]=A.v[1][2]=A.v[1][3]=1;
		A.v[2][1]=A.v[3][2]=1;
		B.clear();
		B.v[1][1]=B.v[3][1]=1;

		B=(A^n)*B;
		printf("%lld\n",B.v[3][1]);
	}
	return 0;
}
