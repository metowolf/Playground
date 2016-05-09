#include<iostream>
#include<cstdio>
#include<map>
using namespace std;

map<string,int>V;
string t;
char temp[100];

int main(){
	cin.sync_with_stdio(0);
	int T;
	cin>>T;
	getline(cin,t);
	while(T--){
		getline(cin,t);
		int pos=t.find(' ');
		t=t.substr(0,pos);
		if(!V.count(t))V[t]=1;
		else V[t]++;
	}
	for(map<string,int>::iterator it=V.begin();it!=V.end();it++){
		cout<<it->first<<" "<<it->second<<endl;
	}
	return 0;
}
