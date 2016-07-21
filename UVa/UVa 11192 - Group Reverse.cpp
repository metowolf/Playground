#include<bits/stdc++.h>
using namespace std;

int n;
char s[100+2];

int main(){
	while(~scanf("%d",&n),n){
		scanf("%s",s);
		n=strlen(s)/n;
		for(int i=0;i<strlen(s);i+=n){
			for(int j=n;j>0;j--)putchar(s[i+j-1]);
		}
		putchar('\n');
	}
	return 0;
}
