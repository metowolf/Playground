#include<bits/stdc++.h>
using namespace std;
int main(){
    int T;
    scanf("%d",&T);
    while(T--){
        int s,d;
        scanf("%d%d",&s,&d);
        int a=(s+d)/2,b=(s-d)/2;
        if(a<b)swap(a,b);
        if(b>=0&&a+b==s&&a-b==d)printf("%d %d\n",a,b);
        else printf("impossible\n");
    }
    return 0;
}
