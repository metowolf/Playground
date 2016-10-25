#include<bits/stdc++.h>
using namespace std;

int n;

bool judge(int x,int y){
	bool vis[10]={0};
	for(int i=1;i<=5;i++){
		if(vis[x%10])return 0;
		else vis[x%10]=1,x/=10;
	}
	for(int i=1;i<=5;i++){
		if(vis[y%10])return 0;
		else vis[y%10]=1,y/=10;
	}
	return 1;
}

int main(){
	int _=0;
	while(~scanf("%d",&n),n){
		if(_++)putchar('\n');

		bool flag=0;
		for(int i=1234,j;i<=49876;i++){
			j=i*n;
			if(j>=100000)break;
			if(judge(i,j))printf("%05d / %05d = %d\n",j,i,n),flag=1;
		}
		if(!flag)printf("There are no solutions for %d.\n",n);
	}
	return 0;
}
			
