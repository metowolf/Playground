#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#define maxn 1000
using namespace std;

struct bign{

	int len,v[maxn+2];

	bign(){clean();}
	bign(int n){clean(),init(n);}

	void clean(){
		len=0;
		memset(v,0,sizeof(v));
	}

	void init(int n){
		len=0;
		while(n)v[++len]=n%10,n/=10;
	}

	void print(){
		if(!len)len++;
		for(int i=len;i>0;i--)putchar('0'+v[i]);
	}

	friend bool operator <(bign a,bign b){
		if(a.len!=b.len)return a.len<b.len;
		for(int i=a.len;i>=1;i--)if(a.v[i]!=b.v[i])return a.v[i]<b.v[i];
		return 0;
	}

	friend bign operator +(bign a,bign b){
		bign t;
		t.len=max(a.len,b.len);
		for(int i=1;i<=t.len;i++)t.v[i]=a.v[i]+b.v[i];
		for(int i=1;i<=t.len;i++){
			t.v[i+1]+=t.v[i]/10;
			t.v[i]%=10;
		}
		if(t.v[t.len+1])t.len++;
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

	friend bign operator /(bign a,bign b){
		bign L(1);
		bign R;R=a;
		bign one(1);
		while(L<R){
			bign mid=(L+R)/2;
			
			/*L.print();putchar(' ');
			mid.print();putchar(' ');
			R.print();putchar('\n');*/
			
			if((mid*b)<a)L=mid+one;
			else R=mid;
		}
		return L;
	}

	friend bign operator /(bign a,int b){
		for(int i=a.len;i>=1;i--){
			if(a.v[i]%b)a.v[i-1]+=a.v[i]%b*10;
			a.v[i]/=b;
		}
		a.v[0]=0;
		while(a.len&&!a.v[a.len])a.len--;
		return a;
	}
};

int main(){
	int n;
	while(~scanf("%d",&n),n){
		bign ans(1);
		for(int i=2;i<=n;i++){
			bign t(2*(2*i-1));
			ans=ans*t;
			ans=ans/(i+1);
		}
		for(int i=1;i<=n;i++){
			bign t(i);
			ans=ans*t;
		}
		ans.print();
		putchar('\n');
	}
	return 0;
}
