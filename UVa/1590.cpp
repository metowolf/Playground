#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#define sf scanf
#define pf printf
#define maxn 1000+2
using namespace std;

int n;
int IP[maxn+2][32+1];

int main(){
	while(~sf("%d",&n)){
		REP(i,1,n){
			int t[4],idx=1;
			sf("%d.%d.%d.%d",t,t+1,t+2,t+3);
			FOR(j,0,4)for(int k=7;k>=0;k--)IP[i][idx++]=(t[j]>>k)&1;
		}
		int m=32;
		REP(j,1,32){
			bool flag=1;
			FOR(i,1,n)if(IP[i][j]!=IP[i+1][j]){
				flag=0;
				break;
			}
			if(!flag){
				REP(_j,j,32)REP(i,1,n)IP[i][_j]=0;
				m=j-1;
				break;	
			}
		}
		
		REP(i,1,4){
			int num=0;
			REP(j,1,8)num=num*2+IP[1][(i-1)*8+j];
			pf("%d%c",num,i==4?'\n':'.');
		}
		REP(i,1,4){
			int num=0;
			REP(j,1,8)num=num*2+((i-1)*8+j<=m);
			pf("%d%c",num,i==4?'\n':'.');
		}
	}
	return 0;
}

