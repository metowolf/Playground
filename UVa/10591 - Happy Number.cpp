#include<bits/stdc++.h>
using namespace std;

int next(int x){
	int t=0;
	while(x){
		int tt=x%10;
		t+=tt*tt;
		x/=10;
	}
	return t;
}

int main(){
	int T,_=0;
	scanf("%d",&T);
	while(T--){
		int x;
		scanf("%d",&x);
		bool flag=0;
		int s1,s2;
		s1=s2=x;
		do{
			s1=next(s1);
			s2=next(s2),s2=next(s2);
			if(s1==1)flag=1;
		}while(s1!=s2);
		printf("Case #%d: %d is %s\n",++_,x,flag?"a Happy number.":"an Unhappy number.");
	}
	return 0;
}
