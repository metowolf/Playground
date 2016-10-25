#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 1000
using namespace std;

struct bign{
	
	int len,v[maxn+2];

	bign(){len=0,memset(v,0,sizeof(v));}

	void read(char s[]){
		len=strlen(s);
		for(int i=1;i<=len;i++)v[i]=s[len-i]-'0';
	}

	void print(){
		if(!len)len++;
		for(int i=len;i>0;i--)putchar('0'+v[i]);
	}

	friend bign operator +(bign a,bign b){
		bign t;
		for(int i=1;i<=max(a.len,b.len);i++){
			t.v[i]=a.v[i]+b.v[i];
		}
		t.len=max(a.len,b.len);
		for(int i=1;i<=t.len;i++){
			t.v[i+1]+=t.v[i]/10;
			t.v[i]%=10;
		}
		while(t.v[t.len+1])t.len++;
		while(t.len&&!t.v[t.len])t.len--;
		return t;
	}

	friend bign operator *(bign a,bign b){
		bign t;
		for(int i=1;i<=a.len;i++)for(int j=1;j<=b.len;j++){
			t.v[i+j-1]+=a.v[i]*b.v[j];
		}
		t.len=a.len+b.len-1;
		for(int i=1;i<=t.len;i++){
			t.v[i+1]+=t.v[i]/10;
			t.v[i]%=10;
		}
		while(t.v[t.len+1])t.len++;
		while(t.len&&!t.v[t.len])t.len--;
		return t;
	}

};


char s[maxn+2];

int main(){
	bign ans,x;
	while(~scanf("%s",s)){
		if(strlen(s)==1&&s[0]=='0')break;
		x.read(s);
		ans=ans+x;
	}
	ans.print();putchar('\n');
	return 0;
}
