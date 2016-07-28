#include<bits/stdc++.h>
#define maxn 500000
using namespace std;
typedef long long LL;

int len;
char s[maxn+2];

LL qpow(LL a,LL k,LL mod){
	LL t=1;
	while(k){
		if(k&1)t=t*a%mod;
		a=a*a%mod;
		k>>=1;
	}
	return t;
}

LL calc(LL mod){
	LL t=0;
	for(int i=0;s[i];i++)t=(t*10+s[i]-'0')%mod;
	return t;
}

map<int,int>as;

int main(){

//freopen("input.txt","r",stdin);

	for(int i=2;i<=maxn;i++)as[log10(i)*i+1]=i;

	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		len=strlen(s);

		if(len==1){
			if(s[0]=='1')printf("1\n");
			else if(s[0]=='4')printf("2\n");
			else printf("-1\n");
		}
		else if(as.find(len)!=as.end()){
			int x=as[len];
			int seed[]={2,3,5,7,11,13,17,19,23};
			bool flag=1;
			for(int i=0;i<9;i++){
				if(qpow(x,x,seed[i])!=calc(seed[i])){
					flag=0;break;
				}
			}
			printf("%d\n",flag?x:-1);
		}
		else printf("-1\n");
	}
	return 0;
}

