#include<bits/stdc++.h>
using namespace std;

map<string,int>M;

int dfs(string s){
	if(M.count(s))return M[s];
	if(!s.size())return 0;
	int &ans=M[s];
	for(int i=0;i<s.size();i++){
		for(int j=1;i+j<=s.size();j++){
			if(s[i]==s[i+j-1]){
				string t=s;t.erase(i,j);
				ans=max(ans,dfs(t)+(j>=3));
			}
			else break;
		}
	}
	return ans;
}

int main(){
	int T;
	scanf("%d",&T);
	while(T--){
		string s;
		cin>>s;
		printf("%d\n",dfs(s));
	}
	return 0;
}
