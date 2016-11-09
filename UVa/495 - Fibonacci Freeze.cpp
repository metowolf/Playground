#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

struct bign{
	static const int BASE=100000000;
	static const int WIDTH=8;
	int len,v[200];

	bign(){clear();}
	bign(int x){
		clear();
		len=0;
		while(x){
			v[++len]=x%BASE;
			x/=BASE;
		}
		if(!len)++len;
	}

	void clear(){
		memset(v,0,sizeof(v));
		len=1;
	}

	void print(){
		printf("%d",v[len]);
		for(int i=len-1;i>=1;i--)printf("%08d",v[i]);
	}

	friend bign operator +(bign a,bign b){
		bign t;
		long long x=0;
		t.len=max(a.len,b.len);
		for(int i=1;i<=t.len;i++){
			x+=a.v[i]+b.v[i];
			t.v[i]=x%BASE;
			x/=BASE;
		}
		if(x)t.v[++t.len]=x;
		return t;
	}
};

bign ans[5000+2];

void initial(){
	ans[0]=bign(0);
	ans[1]=bign(1);
	for(int i=2;i<=5000;i++)ans[i]=ans[i-2]+ans[i-1];
}

int main(){
	
	initial();

	int n;
	while(~scanf("%d",&n)){
		printf("The Fibonacci number for %d is ",n);
		ans[n].print();
		printf("\n");
	}
	return 0;
}
