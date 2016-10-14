#include<bits/stdc++.h>
using namespace std;

map<string,string>Hash;

int main(){
	Hash["HELLO"]="ENGLISH";
	Hash["HOLA"]="SPANISH";
	Hash["HALLO"]="GERMAN";
	Hash["BONJOUR"]="FRENCH";
	Hash["CIAO"]="ITALIAN";
	Hash["ZDRAVSTVUJTE"]="RUSSIAN";
	
	int _=0;
	char s[20];
	while(~scanf("%s",s),s[0]!='#'){
		if(Hash.count(string(s)))printf("Case %d: %s\n",++_,Hash[string(s)].c_str());
		else printf("Case %d: UNKNOWN\n",++_);
	}
	return 0;
}
