#include<bits/stdc++.h>
using namespace std;
int main(){
    int T,_=0;
    scanf("%d",&T);
    while(T--){
        int x,y,z;
        scanf("%d%d%d",&x,&y,&z);
        printf("Case %d: %s\n",++_,(x<=20&&y<=20&&z<=20)?"good":"bad");
    }
    return 0;
}
