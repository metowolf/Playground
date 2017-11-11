#include<bits/stdc++.h>
using namespace std;

int A[100+2];
char s[100000+2];

char chex[]="0123456789ABCDEF";

int main(){
	int T,_=0;
	scanf("%d\n",&T);
	while(T--){
		scanf("%s",s);
		for(int i=1;i<=100;i++)A[i]=0;
		int it=1,t=0;
		for(int i=0;s[i];i++){
			//if(s[i]=='.')A[it]=t;
			if(s[i]=='>')if(++it>100)it=1;
			if(s[i]=='<')if(--it<1)it=100;
			if(s[i]=='+')if(++A[it]>255)A[it]=0;
			if(s[i]=='-')if(--A[it]<0)A[it]=255;
		}
		printf("Case %d: ",++_);
		for(int i=1;i<=100;i++)printf("%c%c%c",chex[A[i]/16],chex[A[i]%16],i==100?'\n':' ');
	}
	return 0;
}
