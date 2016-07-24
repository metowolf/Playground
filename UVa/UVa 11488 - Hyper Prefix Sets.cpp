#include<bits/stdc++.h>
#define REP(i,a,b) for(int i=a;i<=b;++i)
#define FOR(i,a,b) for(int i=a;i!=b;++i);
#define CLR(c,x) memset(c,x,sizeof(c))
#define maxnode 1000000
#define maxchar 2
#define maxn 200
using namespace std;

int ans;

struct Trie{
    int tot,root,child[maxnode+2][maxchar+2];
    bool flag[maxnode+2];
    int cnt[maxnode+2];
    
    void init(){
        CLR(child[0],0);
        cnt[0]=0;
        flag[0]=0;
        root=tot=0;
    }

    void insert(char *s){
        int *cur=&root,deep=0;
        for(char *p=s;*p;++p){
            cur=&child[*cur][*p-'0'];
            if(*cur==0){
                *cur=++tot;
                CLR(child[tot],0);
                cnt[tot]=0;
                flag[tot]=0;
            }
            cnt[*cur]++,deep++;
            ans=max(ans,cnt[*cur]*deep);
        }
        flag[*cur]=1;
    }
}solve;


char s[maxn+2];

int main(){

    //freopen("input.txt","r",stdin);

    int T;
    scanf("%d",&T);
    while(T--){
        int n;
        scanf("%d",&n);
        ans=0;
        solve.init();
        REP(i,1,n){
            scanf("%s",s);
            solve.insert(s);
        }
        printf("%d\n",ans);
    }
    return 0;
}
