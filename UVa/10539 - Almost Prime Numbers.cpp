#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<vector>
#include<algorithm> 
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define uREP(i,a,b) for(int i=a;i>=b;--i)
#define ECH(i,x) for(__typeof(x.begin()) i=x.begin();i!=x.end();++i) 
#define CPY(a,b) memcpy(a,b,sizeof(a))
#define CLR(a,b) memset(a,b,sizeof(a))
#pragma GCC optimize("O2")
//#pragma comment(linker,"/STACK:36777216")
#define endl '\n'
#define sf scanf
#define pf printf
#define maxn 1000000
using namespace std;
typedef long long LL;

vector<LL>ans;

vector<int>Prime;
bool vis[maxn+2];
void init(){
    for(int i=2;i<=maxn;i++){
        if(!vis[i])Prime.push_back(i);
        FOR(j,0,Prime.size()){
            int t=i*Prime[j];
            if(t>maxn)break;
            vis[t]=1;
            if(i%Prime[j]==0)break;
        }
    }
    FOR(i,0,Prime.size()){
    	LL t=(LL)Prime[i]*Prime[i];
    	while(t<=1e12){
    		ans.push_back(t);
    		t*=Prime[i];
    	}
    }
    sort(ans.begin(),ans.end());
}

int main(){
	init();
	int T;
	sf("%d",&T);
	while(T--){
		LL L,R;
		sf("%lld%lld",&L,&R);
		pf("%d\n",upper_bound(ans.begin(),ans.end(),R)-lower_bound(ans.begin(),ans.end(),L));
	}	
	return 0;
}
