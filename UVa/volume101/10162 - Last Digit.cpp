#include<bits/stdc++.h>
using namespace std;

int qpow(int a,int k,int mod){
	int t=1;
	while(k){
		if(k&1)t=t*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return t;
}

int f(int n){
	int t=0;
	for(int i=1;i<=n;i++)t+=qpow(i,i,10);
	return t%10;
}

int main(){
	char s[100+2];
	while(~scanf("%s",s)){
		if(strlen(s)==1&&s[0]=='0')break;
		int n=0;
		for(int i=0;s[i];i++)n=(n*10+s[i]-'0')%100;
		printf("%d\n",f(n));
	}
	return 0;
}
