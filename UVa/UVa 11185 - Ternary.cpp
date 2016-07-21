#include<bits/stdc++.h>
using namespace std;

void Base3(int x){
	if(!x){
		printf("0\n");
		return;
	}
	int t[100],top=0;
	while(x)t[++top]=x%3,x/=3;
	while(top--)printf("%d",t[top+1]);
	printf("\n");
}

int main(){
	int n;
	while(~scanf("%d",&n),n>=0)Base3(n);
	return 0;
}
