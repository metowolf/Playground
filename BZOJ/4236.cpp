#include<bits/stdc++.h>
#define X first
#define Y second
using namespace std;
typedef pair<int,int> PII;

map<PII,int>M;

int main(){
	int n,A,B,C,ans=0;
	scanf("%d",&n);
	A=B=C=0;
	M[PII(0,0)]=0;
	for(int i=1;i<=n;i++){
		char ch;
		scanf(" %c",&ch);
		if(ch=='J')A++;
		if(ch=='O')B++;
		if(ch=='I')C++;
		PII t=PII(A-B,B-C);
		if(M.find(t)!=M.end())ans=max(ans,i-M[t]);
		else M[t]=i;
	}
	printf("%d\n",ans);
	return 0;
}
