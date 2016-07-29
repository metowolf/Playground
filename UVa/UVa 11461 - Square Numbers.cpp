#include<bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	while(~scanf("%d%d",&a,&b),a||b){
		printf("%d\n",(int)sqrt(b)-(int)sqrt(a-1));
	}
	return 0;
}
