#include<bits/stdc++.h>
using namespace std;

int main(){
	int T,_=0;
	scanf("%d\n",&T);
	while(T--){
		char c;int n;
		printf("Case %d: ",++_);
		while(c=getchar(),c>='A'&&c<='Z'){
			scanf("%d",&n);
			while(n--)putchar(c);
		}
		printf("\n");
	}
	return 0;
}
