#include<bits/stdc++.h>
using namespace std;

char A[200];
map<char,int>cnt;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf(" %c",A+i),cnt[A[i]]++;
	for(int i=1;i<=n;i++)if(cnt[A[i]]==1){
		printf("%c\n",A[i]);
		return 0;
	}
	printf("-1\n");
	return 0;
}

