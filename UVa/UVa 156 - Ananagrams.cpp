#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i!=b;++i)
using namespace std;

string r_string(){
    char s[20+2];
    scanf("%s",s);
    return string(s);
}

map<string,string>M;
vector<string>V;

int main(){    
    string raw,s;
    while(raw=r_string(),raw[0]!='#'){
        s=raw;
        FOR(i,0,s.size())if(s[i]>='A'&&s[i]<='Z')s[i]+='a'-'A';
        sort(s.begin(),s.end());
        if(M.count(s))M[s]="#";
        else M[s]=raw;
    }
    for(auto it:M)if(it.second!="#")V.push_back(it.second);
    sort(V.begin(),V.end());
    for(string s:V)printf("%s\n",s.c_str());
    return 0;
}
