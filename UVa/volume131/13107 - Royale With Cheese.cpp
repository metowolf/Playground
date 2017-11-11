#include<bits/stdc++.h>
using namespace std;

char s[100000+2];
int idx[26+2];

char ss[]="0153429786";

void _out(int x){
	if(x){
		_out(x/10);
		putchar(ss[x%10]);
	}
}

int main(){
	while(~scanf("%s",s)){
		int cnt=0;
		memset(idx,0,sizeof(idx));
		for(int i=0;s[i];i++){
			if(!idx[s[i]-'a'])idx[s[i]-'a']=++cnt;
			_out(idx[s[i]-'a']);
		}
		putchar('\n');
	}
	return 0;
}
