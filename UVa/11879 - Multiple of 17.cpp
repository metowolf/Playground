#include<iostream>
#include<cstdio>
using namespace std;

char s[100+2];

int main(){
	while(~scanf("%s",s),s[0]-'0'){
		int t=0;
		for(int i=0;s[i];i++){
			t=t*10+s[i]-'0';
			if(t>=17)t%=17;
		}
		printf("%d\n",t==0);
	}
	return 0;
}
