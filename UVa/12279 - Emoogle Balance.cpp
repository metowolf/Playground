#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int n,_=0;
	while(~scanf("%d",&n),n){
		int L,R;
		L=R=0;
		while(n--){
			int t;
			scanf("%d",&t);
			if(t)L++;else R++;
		}
		printf("Case %d: %d\n",++_,L-R);
	}
	return 0;
}
