#include<bits/stdc++.h>
using namespace std;

int a,b,c;
char s[]="*CBAABC*";

int main(){
	while(~scanf("%d%d%d",&a,&b,&c)){
		printf("%c\n",s[a*4+b*2+c]);
	}
	return 0;
}
