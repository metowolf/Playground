#include<bits/stdc++.h>
using namespace std;

int read(){
	char c;
	int ans=0;
	while((c=getchar())){
		if(c==EOF)return -1;
		else if(c=='\n')return ans;
		else if(c==' '||c=='o')ans=ans*2+(c=='o');
	}
}

int main(){
	
	//freopen("input.txt","r",stdin);
	
	int t;
	read();
	while((t=read())!=-1)printf("%c",t);
	return 0;
}
