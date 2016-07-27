#include<bits/stdc++.h>
#define CLR(c,x) memset(c,x,sizeof(c))
using namespace std;

int dx[]={0,1,0,-1,0},dy[]={0,0,1,0,-1};
int cnt[3][3];
char s[200+2];

int main(){
	int _=0;
	while(fgets(s,200,stdin)){
		CLR(cnt,0);
		for(int i=0;s[i];i++){
			int a=(s[i]-'a')/3;
			int b=(s[i]-'a')%3;
			for(int j=0;j<=4;j++){
				int x=a+dx[j],y=b+dy[j];
				if(x<0||x>2||y<0||y>2)continue;
				cnt[x][y]++;
			}
		}
		printf("Case #%d:\n",++_);
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)printf("%d%c",cnt[i][j]%10,j==2?'\n':' ');
	}
	return 0;
}
