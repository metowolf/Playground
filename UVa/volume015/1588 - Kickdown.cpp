#include<bits/stdc++.h>
using namespace std;

const int maxn=120;

char s1[maxn+10],s2[maxn+10];

int main(){
	while(~scanf("%s %s",s1,s2)){
		int len1=strlen(s1),len2=strlen(s2);
		int ans=len1+len2;
		for(int i=-len2;i<=len1;i++){
			int flag=1;
			for(int j=0;j<len2&&flag;j++)
				if(i+j>=0&&i+j<len1)
					flag&=s1[i+j]-'0'+s2[j]-'0'<=3;
			if(flag)
				ans=min(ans,max(len1,len2+i)-min(0,i));
		}
		printf("%d\n",ans);
	}
	return 0;
}

