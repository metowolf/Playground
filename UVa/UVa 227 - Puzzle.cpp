#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define REP(i,a,b) for(int i=a;i<=b;i++)
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define CLR(c,x) memset(c,x,sizeof(c))
#define sf scanf
#define pf printf
#define maxn 
using namespace std;

char P[7][7];

int main(){
	int _=0;
	while(1){
		gets(P[0]);
		if(P[0][0]=='Z'&&!P[0][1])break;
		REP(i,1,4)gets(P[i]);
		FOR(i,0,5)FOR(j,0,5)if(!P[i][j])P[i][j]=' ';
		
		int x,y;
		FOR(i,0,5)FOR(j,0,5)if(P[i][j]==' ')x=i,y=j;
		bool flag=1;
		for(char c;scanf(" %c",&c),c!='0';){
			if(!flag)continue;
			//pf("[%c]",c);
			if(c=='A'){
				if(x==0){flag=0;continue;}
				swap(P[x][y],P[x-1][y]);
				x--;
			}
			if(c=='B'){
				if(x==4){flag=0;continue;}
				swap(P[x][y],P[x+1][y]);
				x++;
			}
			if(c=='L'){
				if(y==0){flag=0;continue;}
				swap(P[x][y],P[x][y-1]);
				y--;
			}
			if(c=='R'){
				if(y==4){flag=0;continue;}
				swap(P[x][y],P[x][y+1]);
				y++;
			}
		}
		getchar();
		
		if(_)pf("\n");
		pf("Puzzle #%d:\n",++_);
		
		if(flag)FOR(i,0,5)FOR(j,0,5)pf(j==4?"%c\n":"%c ",P[i][j]);
		else pf("This puzzle has no final configuration.\n");
	}	
	return 0;
}
