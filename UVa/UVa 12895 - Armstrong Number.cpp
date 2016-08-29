#include<bits/stdc++.h>
using namespace std;

int f(int x){
	int len=log10(x)+1;
	int t=0;
	while(x){
		t+=pow(x%10,len);
		x/=10;
	}
	return t;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n;
		scanf("%d",&n);
		if(f(n)==n)printf("Armstrong\n");
		else printf("Not Armstrong\n");
	}
	return 0;
}
