#include<bits/stdc++.h>
#define maxn 30
using namespace std;

int n,m;
int V[maxn+2];

bool mod(int deep){
	long long t=0;
	for(int i=1;i<=deep;i++){
		t=t*10+V[i];
		if(i==17)t%=deep;
	}
	return t%deep==0;
}

bool DFS(int deep){
	if(deep>m)return 1;
	for(V[deep]=0;V[deep]<=9;V[deep]++){
		if(deep==1&&V[deep]==0)continue;
		if(deep<n||mod(deep)){
			if(DFS(deep+1))return 1;
		}
	}
	return 0;
}

int main(){
	int T,_=0;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d",&n,&m);
		printf("Case %d: ",++_);
		if(!DFS(1))printf("-1\n");
		else{
			for(int i=1;i<=m;i++)printf("%d",V[i]);
			printf("\n");
		}
	}
	return 0;
}
