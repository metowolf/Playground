#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

map<string,int>Tree;

bool _gets(string &s){
	s="";
	int len=0;
	char c;
	while((c=getchar())!=EOF){
		if(c=='\n')break;
		s=s+c;
		len++;
	}
	return len;
}

int main(){
	int T;
	scanf("%d\n\n",&T);
	while(T--){
		string s;int cnt=0;
		Tree.clear();
		while(_gets(s))Tree[s]++,cnt++;
		for(auto it=Tree.begin();it!=Tree.end();it++)
			printf("%s %.4lf\n",it->first.c_str(),it->second*100./cnt);
		if(T)printf("\n");
	}
	return 0;
}
