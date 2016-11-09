#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int n;
char s[1000000+2];
int nxt[1000000+2];

void genNext(){
	nxt[0]=nxt[1]=0;
	for(int i=1;i<n;i++){
		int j=nxt[i];
		while(j&&s[i]!=s[j])j=nxt[j];
		nxt[i+1]=(s[i]==s[j])?j+1:0;
	}
}

int main(){
	while(~scanf("%s",s),s[0]!='.'){
		n=strlen(s);
		genNext();
		int k=n-nxt[n];
		printf("%d\n",n%k?1:n/k);
	}
	return 0;
}
