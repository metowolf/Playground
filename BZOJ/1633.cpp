#include<bits/stdc++.h>
using namespace std;

const int maxn=600;
const int maxL=300;

char s[maxL+10];
char dir[maxn+10][maxL+10];
int dp[maxL+10];

int main(){
	int n,L;
	scanf("%d%d",&n,&L);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)scanf("%s",dir[i]+1);
	for(int i=1;i<=L;i++){
		dp[i]=i;
		for(int j=1;j<=n;j++){
			int k,cnt=0,len=strlen(dir[j]+1);
			for(k=i;k>0;k--){
				if(s[k]==dir[j][len])len--;else cnt++;
				if(!len)break;
			}
			if(!len)dp[i]=min(dp[i],dp[k-1]+cnt);
		}
	}
	printf("%d\n",dp[L]);
	return 0;
}

