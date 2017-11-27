#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,a=0,b=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		char c;
		scanf(" %c",&c);
		if(c=='L')a--;
		if(c=='R')a++;
		if(c=='U')b--;
		if(c=='D')b++;
	}
	printf("%d\n",n-abs(a)-abs(b));
	return 0;
}
	
