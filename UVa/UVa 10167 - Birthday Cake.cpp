#include<bits/stdc++.h>
#define maxn 50
using namespace std;

int n;
struct Point{int x,y;}P[maxn<<1+2];

inline int r(int L,int R){
	return L+rand()%(R-L+1);
}

int main(){
	srand(time(NULL));
	while(~scanf("%d",&n),n){
		for(int i=1;i<=n*2;i++)scanf("%d%d",&P[i].x,&P[i].y);
		int A,B;
		while(1){
			A=r(-500,500),B=r(-500,500);
			int cnt1=0,cnt2=0;
			for(int i=1;i<=n*2;i++){
				int t=A*P[i].x+B*P[i].y;
				cnt1+=t>0,cnt2+=t<0;
			}
			if(cnt1==n&&cnt2==n)break;
		}
		printf("%d %d\n",A,B);
	}
	return 0;
}

