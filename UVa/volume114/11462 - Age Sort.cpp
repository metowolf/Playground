#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a,end=b+1;i!=end;++i)
#define maxn 100
using namespace std;

int cnt[maxn+2];

inline int _int(){
	int t=0;
	char c=getchar();
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9'){t=t*10+c-'0',c=getchar();}
	return t;
}

void o_int(int x){
	if(x>9)o_int(x/10);
	putchar(x%10+'0');	
}

int main(){
	int n;
	while(n=_int()){
		REP(i,0,100)cnt[i]=0;
		REP(i,1,n){
			int x=_int();
			++cnt[x];
		}
		REP(i,0,100)REP(j,1,cnt[i])o_int(i),putchar(--n?' ':'\n');
	}
	return 0;
}
