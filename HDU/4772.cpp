#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<b;i++)
using namespace std;

const int maxn=300;

int n;  
int mat[maxn+10][maxn+10],mp[maxn+10][maxn+10];  
int tmp[maxn+10][maxn+10];  

void gao2(){  
	int pos=0;  
	memcpy(mat,tmp,sizeof(tmp));  
	for(int i=n-1;i>=0;i--,pos++)  
		FOR(j,0,n)
			tmp[pos][j]=mat[j][i];   
}

int gao(){  
	int cnt=0;
	FOR(i,0,n)FOR(j,0,n)
		cnt+=tmp[i][j]==mp[i][j]; 
	return cnt;  
}  

int solve(){  
	int ans=0; 
	memcpy(tmp,mat,sizeof(tmp));  
	for(int i=1;i<=4;i++){
		ans=max(ans,gao());
		gao2();
	}
	return ans;  
}  

int main(){  
	while(~scanf("%d",&n),n){
		FOR(i,0,n)FOR(j,0,n)scanf("%d",&mat[i][j]);  
		FOR(i,0,n)FOR(j,0,n)scanf("%d",&mp[i][j]);  
		printf("%d\n",solve());  
	}  
	return 0;  
}  

