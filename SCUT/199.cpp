#include<bits/stdc++.h>
using namespace std;

const int maxn=10000;

int read(){
	char c=getchar();int x=0;
	while((c<'0'||c>'9')&&c!='n')c=getchar();
	if(c=='n')return maxn;
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}

int L,w,top,Ftype[maxn+10],Sum,Ans;
char s[maxn+10],Vname[maxn+10];
bool vis[maxn+10],ERR;

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		scanf("%d%s",&L,s);
		if(s[2]!='n')w=0;
		else sscanf(s,"O(n^%d",&w);
		Sum=Ans=top=ERR=0;
		memset(vis,0,sizeof(vis));
		while(L--){
			char c=getchar();
			while(c!='F'&&c!='E')c=getchar();
			if(c=='F'){
				while(c<'a'||c>'z')c=getchar();
				int a,b;
				a=read(),b=read();
				if(vis[c-'a'+1])ERR=1;
				if(!ERR){
					vis[c-'a'+1]=1;
					top++;
					Ftype[top]=0;
					if(a>b)Ftype[top]=-maxn;
					if(b-a>1000)Ftype[top]=1;
					Vname[top]=c;
					Sum+=Ftype[top];
					Ans=max(Ans,Sum);
				}
			}
			else{
				if(top==0)ERR=1;
				if(!ERR){
					vis[Vname[top]-'a'+1]=0;
					Sum-=Ftype[top];
					top--;
				}
			}
		}
		if(ERR||top)printf("ERR\n");
		else printf(w==Ans?"Yes\n":"No\n");
	}
	return 0;
}

