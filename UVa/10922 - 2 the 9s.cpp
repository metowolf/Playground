#include<iostream>
#include<cstdio>
using namespace std;

char s[1000+2];

int main(){
	while(~scanf("%s",s)){
		if(s[0]=='0'&&!s[1])break;
		int x=0,ans;
		for(int i=0;s[i];i++)x+=s[i]-'0';
		if(x%9)ans=0;
		else{
			ans=0;
			while(x%9==0){
				ans++;
				if(x<10)break;
				int t=0;
				while(x)t+=x%10,x/=10;
				x=t;
			}
		}
		if(ans)printf("%s is a multiple of 9 and has 9-degree %d.\n",s,ans);
		else printf("%s is not a multiple of 9.\n",s);
	}
	return 0;
}
