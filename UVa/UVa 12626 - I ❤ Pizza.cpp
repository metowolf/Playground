#include<bits/stdc++.h>
using namespace std;

int cnt[26];
char s[600+2];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%s",s);
		for(int i=0;i<26;i++)cnt[i]=0;
		for(int i=0;s[i];i++)cnt[s[i]-'A']++;
		int ans=cnt['M'-'A'];
		ans=min(ans,cnt['A'-'A']/3);
		ans=min(ans,cnt['R'-'A']/2);
		ans=min(ans,cnt['G'-'A']);
		ans=min(ans,cnt['I'-'A']);
		ans=min(ans,cnt['T'-'A']);
		printf("%d\n",ans);
	}
	return 0;
}
