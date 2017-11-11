#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i!=b;++i)
using namespace std;

int n;
char s[1000];

bool cmp(char a,char b){
    char aa=tolower(a),bb=tolower(b);
    return aa==bb?a<b:aa<bb;
}

int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        scanf("%s",s);
        n=strlen(s);
        sort(s,s+n,cmp);
        do{
            FOR(i,0,n)printf("%c",s[i]);
            printf("\n");
        }while(next_permutation(s,s+n,cmp));
    }
    return 0;
}
