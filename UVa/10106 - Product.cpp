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

	friend bign operator *(bign a,bign b){
		bign t;
		for(int i=1;i<=a.len;i++)for(int j=1;j<=b.len;j++){
			t.v[i+j-1]+=a.v[i]*b.v[j];
		}
		for(int i=1;i<=a.len+b.len;i++){
			t.v[i+1]+=t.v[i]/10;
			t.v[i]%=10;
			if(t.v[i])t.len=i;
		}
		while(t.v[t.len+1])t.len++;
		return t;
	}

};


char s1[300],s2[300];

int main(){
	while(~scanf("%s%s",s1,s2)){
		bign a,b;
		a.read(s1),b.read(s2);
		a=a*b;
		a.print();putchar('\n');
	}
	return 0;
}
