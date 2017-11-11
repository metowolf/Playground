#include<iostream>
#include<cstdio>
using namespace std;

char s[20+2];

int f(char c){
	if(c>='a'&&c<='z')return 1+c-'a';
	else return 27+c-'A';
}

bool isPrime(int x){
	for(int i=2;i*i<=x;i++)if(x%i==0)return 0;
	return 1;
}

int main(){
	while(~scanf("%s",s)){
		int x=0;
		for(int i=0;s[i];i++)x+=f(s[i]);
		printf(isPrime(x)?"It is a prime word.\n":"It is not a prime word.\n");
	}
	return 0;
}
