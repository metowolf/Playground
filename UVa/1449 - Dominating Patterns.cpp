#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
#include<map>
#define maxnode 11000
#define maxsize 26
#define maxs 150
using namespace std;


struct acAutomate{
	int ch[maxnode+2][maxsize+2];
	int fail[maxnode+2];
	int val[maxnode+2];
	int last[maxnode+2];
	int cnt[maxs+2];
	int size;

	void init(){
		size=1;
		memset(ch[0],0,sizeof(ch[0]));
		memset(cnt,0,sizeof(cnt));
	}

	int idx(char c){
		return c-'a';
	}

	void insert(char *s,int v){
		int u=0,n=strlen(s);
		for(int i=0;i<n;i++){
			int c=idx(s[i]);
			if(!ch[u][c]){
				memset(ch[size],0,sizeof(ch[size]));
				val[size]=0;
				ch[u][c]=size++;
			}
			u=ch[u][c];
		}
		val[u]=v;
	}

	void print(int j){
		if(j)cnt[val[j]]++,print(last[j]);
	}

	int find(char *T){
		int n=strlen(T);
		int j=0;
		for(int i=0;i<n;i++){
			int c=idx(T[i]);
			while(j&&!ch[j][c])j=fail[j];
			j=ch[j][c];
			if(val[j])print(j);
			else if(last[j])print(last[j]);
		}
	}

	void getFail(){
		queue<int>Q;
		fail[0]=0;
		for(int c=0;c<maxsize;c++){
			int u=ch[0][c];
			if(u){fail[u]=0;Q.push(u);last[u]=0;}
		}
		while(!Q.empty()){
			int t=Q.front();Q.pop();
			for(int c=0;c<maxsize;c++){
				int u=ch[t][c];
				if(!u)continue;
				Q.push(u);
				int v=fail[t];
				while(v&&!ch[v][c])v=fail[v];
				fail[u]=ch[v][c];
				last[u]=val[fail[u]]?fail[u]:last[u];
			}
		}
	}

};

acAutomate ac;

char text[1000000+2],P[150+2][80];
map<string,int>ms;

int main(){
	int n;
	while(~scanf("%d",&n),n){
		ac.init();
		ms.clear();
		for(int i=1;i<=n;i++){
			scanf("%s",P[i]);
			ac.insert(P[i],i);
			ms[string(P[i])]=i;
		}
		ac.getFail();
		scanf("%s",text);
		ac.find(text);
		
		int best=-1;
		for(int i=1;i<=n;i++){
			if(ac.cnt[i]>best)best=ac.cnt[i];
		}
		printf("%d\n",best);
		for(int i=1;i<=n;i++){
			if(ac.cnt[ms[string(P[i])]]==best)printf("%s\n",P[i]);
		}
	}
	return 0;
}


