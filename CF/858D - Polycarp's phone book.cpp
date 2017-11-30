#include<bits/stdc++.h>
using namespace std;

const int maxn=70000;

inline string read(){
	char _s[12];
	scanf("%s",_s);
	return string(_s);
}

string s[maxn+10];
unordered_map<string,int>cnt;
set<string>Set;

int main(){
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)s[i]=read();
	for(int i=1;i<=n;i++){
		Set.clear();
		int len=s[i].size();
		for(int L=0;L<len;L++){
			string ts="";
			for(int R=L;R<len;R++){
				ts+=s[i][R];
				Set.insert(ts);
			}
		}
		for(string t:Set)cnt[t]++;
	}
	string ans;
	for(int i=1;i<=n;i++){
		int len=s[i].size(),anslen=10;
		for(int L=0;L<len;L++){
			string ts="";
			for(int R=L;R<len;R++){
				ts+=s[i][R];
				if(cnt[ts]==1&&ts.size()<anslen)ans=ts,anslen=ts.size();
			}
		}
		printf("%s\n",ans.c_str());
	}
	return 0;
}
