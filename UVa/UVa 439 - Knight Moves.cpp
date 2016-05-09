#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<climits>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#pragma GCC optimize("O2")
#define sf scanf
#define pf printf
#define maxn 300000
#define endl '\n'
using namespace std;
typedef pair<int,int> PII;

int cnt[9][9];
int dx[]={-2,-2,-1,-1,1,1,2,2};
int dy[]={1,-1,2,-2,2,-2,1,-1};

int main(){
	char a[4],b[4];
	while(~sf(" %s %s",a,b)){
		int sx=a[0]-'a'+1,sy=a[1]-'0';
		int tx=b[0]-'a'+1,ty=b[1]-'0';
		REP(i,1,8)REP(j,1,8)cnt[i][j]=INT_MAX; 
		cnt[sx][sy]=0;
		queue<PII>Q;
		Q.push(PII(sx,sy));
		while(!Q.empty()){
			PII t=Q.front();
			Q.pop();
			int x=t.first,y=t.second;
			FOR(i,0,8){
				int _x=x+dx[i],_y=y+dy[i];
				if(_x<1||_x>8||_y<1||_y>8)continue;
				if(cnt[x][y]+1<cnt[_x][_y]){
					cnt[_x][_y]=cnt[x][y]+1;
					Q.push(PII(_x,_y));
				}
			}
		}
		pf("To get from %s to %s takes %d knight moves.\n",a,b,cnt[tx][ty]);
	}
	return 0;
}
