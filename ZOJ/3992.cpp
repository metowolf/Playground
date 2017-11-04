#include<bits/stdc++.h>
using namespace std;

const int maxn=1e5;

char s[maxn+10];

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		int n,m;
		scanf("%d%d",&n,&m);
		scanf("%s",s+1);
		int a=0,b=0;
		for(int i=m;i>1;i--)a+=s[i]!='L';
		for(int i=m;i<n;i++)b+=s[i]!='R';
		printf("%d\n",min(a,b));
	}
	return 0;
}
